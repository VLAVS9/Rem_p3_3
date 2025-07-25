/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2023 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "lwip/tcpip.h"
#include "board.h"
#include "app.h"
#include "wpl.h"
#include "timers.h"
#include "httpsrv.h"
#include "http_server.h"

#include "fsl_debug_console.h"
#include "webconfig.h"
#include "cred_flash_storage.h"
#include "mqtt_freertos/mqtt_freertos.h"

#include <stdio.h>

#include "FreeRTOS.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static int CGI_HandleGet(HTTPSRV_CGI_REQ_STRUCT *param);
static int CGI_HandlePost(HTTPSRV_CGI_REQ_STRUCT *param);
static int CGI_HandleReset(HTTPSRV_CGI_REQ_STRUCT *param);
static int CGI_HandleStatus(HTTPSRV_CGI_REQ_STRUCT *param);

static uint32_t SetBoardToClient();
static uint32_t SetBoardToAP();
static uint32_t CleanUpAP();
static uint32_t CleanUpClient();

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum board_wifi_states
{
    WIFI_STATE_CLIENT,
    WIFI_STATE_CONNECTING,
    WIFI_STATE_CLIENT_SCAN,
    WIFI_STATE_AP,
    WIFI_STATE_AP_SCAN,
} board_wifi_states;

struct board_state_variables
{
    board_wifi_states wifiState;
    char ssid[WPL_WIFI_SSID_LENGTH];
    char password[WPL_WIFI_PASSWORD_LENGTH];
    char security[WIFI_SECURITY_LENGTH];
    bool connected;
    TaskHandle_t mainTask;
};

const HTTPSRV_CGI_LINK_STRUCT cgi_lnk_tbl[] = {
    {"reset", CGI_HandleReset},
    {"get", CGI_HandleGet},
    {"post", CGI_HandlePost},
    {"status", CGI_HandleStatus},
    {0, 0} // DO NOT REMOVE - last item - end of table
};

/*******************************************************************************
 * Variables
 ******************************************************************************/
struct board_state_variables g_BoardState;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*CGI*/
/* Example Common Gateway Interface callback. */
/* These callbacks are called from the session tasks according to the Link struct above */
/* The get.cgi request triggers a scan and responds with a list of the SSIDs */
static int CGI_HandleGet(HTTPSRV_CGI_REQ_STRUCT *param)
{
    /* Buffer for hodling response JSON data */
    char buffer[32]                 = {0};
    char *ssids                     = NULL;
    HTTPSRV_CGI_RES_STRUCT response = {0};

    response.ses_handle   = param->ses_handle;
    response.status_code  = HTTPSRV_CODE_OK;
    response.content_type = HTTPSRV_CONTENT_TYPE_PLAIN;
    response.data         = buffer;

    if (g_BoardState.wifiState == WIFI_STATE_CLIENT || g_BoardState.wifiState == WIFI_STATE_AP)
    {
        /* Initiate Scan */
        PRINTF("\r\nInitiating scan...\r\n\r\n");
        ssids = WPL_Scan();
        if (ssids == NULL)
        {
            PRINTF("[!] Scan Error\r\n");
            /* "null" string is interpreted as error by the website */
            strcpy(buffer, "{\"networks\":\"null\"}");
        }
        else
        {
            response.data = ssids;
        }
    }
    else
    {
        /* We can not start a scan if a previous scan is running or if we are connecting */
        strcpy(buffer, "{\"networks\":\"false\"}");
    }

    /* Send the response back to browser */
    response.data_length    = strlen(response.data);
    response.content_length = response.data_length;
    HTTPSRV_cgi_write(&response);

    if (ssids != NULL)
    {
        /* Release JSON buffer from WPL_Scan() */
        vPortFree(ssids);
    }

    return (response.content_length);
}

/* The post.cgi request is used for triggering a connection to an external AP */
static int CGI_HandlePost(HTTPSRV_CGI_REQ_STRUCT *param)
{
    HTTPSRV_CGI_RES_STRUCT response = {0};

    response.ses_handle   = param->ses_handle;
    response.status_code  = HTTPSRV_CODE_OK;
    response.content_type = HTTPSRV_CONTENT_TYPE_PLAIN;

    char buffer[256] = {0};

    uint32_t length = 0;
    uint32_t read   = 0;
    char posted_passphrase[WPL_WIFI_PASSWORD_LENGTH + 1];
    char posted_ssid[WPL_WIFI_SSID_LENGTH + 1];
    char posted_security[WIFI_SECURITY_LENGTH + 1];

    int32_t result = WPLRET_FAIL;
    bool err       = false;

    /* We can not join another AP if we are already connected to one */
    if (g_BoardState.wifiState == WIFI_STATE_CLIENT)
    {
        err = true;
    }

    if (err == false)
    {
        length = MIN(param->content_length, (sizeof(buffer) - 1));
        read   = HTTPSRV_cgi_read(param->ses_handle, buffer, length);
        if (read > 0)
        {
            buffer[length] = '\0';
            cgi_get_varval(buffer, "post_ssid", posted_ssid, sizeof(posted_ssid));
            cgi_get_varval(buffer, "post_passphrase", posted_passphrase, sizeof(posted_passphrase));
            cgi_get_varval(buffer, "post_security", posted_security, sizeof(posted_security));
            cgi_urldecode(posted_ssid);
            cgi_urldecode(posted_passphrase);
            cgi_urldecode(posted_security);

            /* Any post processing of the posted data (sanitation, validation) */
            format_post_data(posted_ssid);
            format_post_data(posted_passphrase);
            format_post_data(posted_security);

            WC_DEBUG("[i] Chosen ssid: %s\r\n", posted_ssid);
            WC_DEBUG("[i] Chosen passphrase: \"%s\" \r\n", posted_passphrase);
            WC_DEBUG("[i] Chosen security methods: \"%s\" \r\n", posted_security);
        }
        else
        {
            err = true;
        }
    }

    if (err == false)
    {
        /* Add Wi-Fi network */
        if (strstr(posted_security, "WPA3_SAE"))
        {
            result = WPL_AddNetworkWithSecurity(posted_ssid, posted_passphrase, WIFI_NETWORK_LABEL, WPL_SECURITY_WPA3_SAE);
        }
        else
        {
            result = WPL_AddNetworkWithSecurity(posted_ssid, posted_passphrase, WIFI_NETWORK_LABEL, WPL_SECURITY_WILDCARD);
        }
        
        if (result != WPLRET_SUCCESS)
        {
            err = true;
        }
    }

    if (err == false)
    {
        /* Initiate joining process */
        PRINTF("[i] Joining: %s\r\n", posted_ssid);
        result = WPL_Join(WIFI_NETWORK_LABEL);
        if (result != WPLRET_SUCCESS)
        {
            err = true;
        }
    }

    if (err == true)
    {
        PRINTF("[!] Cannot connect to wifi\r\n[!] ssid: %s\r\n[!] passphrase: %s\r\n", posted_ssid, posted_passphrase);
        /* Respond with a failure to the browser */
        response.data           = "{\"status\":\"failed\"}";
        response.data_length    = strlen(response.data);
        response.content_length = response.data_length;
        HTTPSRV_cgi_write(&response);

        WPL_RemoveNetwork(WIFI_NETWORK_LABEL);
    }
    else
    {
        /* We have successfully connected however the old AP is still running.
         * This session is still active and will try replying to the browser with a success message.
         * This message will also hold the new IP address under which the board will be reachable */
        PRINTF("[i] Successfully joined: %s\r\n", posted_ssid);
        char ip[32];
        /* Get new client address to be sent back to the old browser session */
        WPL_GetIP(ip, 1);
        PRINTF(" Now join that network on your device and connect to this IP: %s\r\n", ip);

        snprintf(buffer, sizeof(buffer), "{\"status\":\"success\",\"new_ip\":\"%s\"}", ip);

        response.data           = buffer;
        response.data_length    = strlen(response.data);
        response.content_length = response.data_length;
        HTTPSRV_cgi_write(&response);

        g_BoardState.wifiState = WIFI_STATE_CLIENT;
        g_BoardState.connected = true;
        /* Since the Joining was successful, we can save the credentials to the Flash */
        save_wifi_credentials(CONNECTION_INFO_FILENAME, posted_ssid, posted_passphrase, posted_security);

        mqtt_freertos_run_thread(netif_default);
        /* Resume the main task, this will make sure to clean up and shut down the AP*/
        /* Since g_BoardState.connected == true, the reconnection to AP will be skipped and
         * the main task will be put back to sleep waiting for a reset event */
        vTaskResume(g_BoardState.mainTask);
    }

    return (response.content_length);
}

/* The reset.cgi is used to clear the Flash memory and reset the board back to AP mode */
static int CGI_HandleReset(HTTPSRV_CGI_REQ_STRUCT *param)
{
    HTTPSRV_CGI_RES_STRUCT response;

    response.ses_handle   = param->ses_handle;
    response.status_code  = HTTPSRV_CODE_OK;
    response.content_type = HTTPSRV_CONTENT_TYPE_PLAIN;
    char str_buffer[64];

    /* Try to clear the flash memory */
    if (reset_saved_wifi_credentials(CONNECTION_INFO_FILENAME) != 0)
    {
        PRINTF("[!] Error occured during resetting of saved credentials!\r\n");
        response.data        = "{\"status\":\"failed\"}";
        response.data_length = strlen(response.data);
    }
    else
    {
        /* The new ip will be the static ip configured for the local AP */
        snprintf(str_buffer, sizeof(str_buffer), "{\"status\":\"success\",\"new_ip\":\"%s\"}", WPL_WIFI_AP_IP_ADDR);

        response.data        = str_buffer;
        response.data_length = strlen(str_buffer);
    }

    response.content_length = response.data_length;
    HTTPSRV_cgi_write(&response);

    /* If we were client, disconnect from the external AP and start local AP */
    if (g_BoardState.wifiState == WIFI_STATE_CLIENT)
    {
        g_BoardState.wifiState = WIFI_STATE_AP;
        g_BoardState.connected = false;

        vTaskResume(g_BoardState.mainTask);
    }

    return 0;
}

/*CGI*/
/* Example Common Gateway Interface callback. */
/* These callbacks are called from the session tasks according to the Link struct above */
/* The status  status.cgi request returns status */
static int CGI_HandleStatus(HTTPSRV_CGI_REQ_STRUCT *param)
{
    HTTPSRV_CGI_RES_STRUCT response = {0};

    response.ses_handle  = param->ses_handle;
    response.status_code = HTTPSRV_CODE_OK;

    /* Buffer for hodling response JSON data */
    char buffer[256] = {0};
    char ip[16];
    char status_str[32] = {'\0'};

    // Get the Board IP address
    switch (g_BoardState.wifiState)
    {
        case WIFI_STATE_CONNECTING:
            strcpy(status_str, "connecting");
            WPL_GetIP(ip, 0);
            break;
        case WIFI_STATE_CLIENT_SCAN:
            strcpy(status_str, "scan_");
        case WIFI_STATE_CLIENT:
            strcat(status_str, "client");
            WPL_GetIP(ip, 1);
            break;
        case WIFI_STATE_AP_SCAN:
            strcpy(status_str, "scan_");
        case WIFI_STATE_AP:
        default:
            strcat(status_str, "ap");
            WPL_GetIP(ip, 0);
    }

    // Build the response JSON
    snprintf(buffer, sizeof(buffer), "{\"info\":{\"name\":\"%s\",\"ip\":\"%s\",\"ap\":\"%s\",\"status\":\"%s\"}}",
             BOARD_NAME, ip, g_BoardState.ssid, status_str);

    // Send the response back to browser
    response.content_type   = HTTPSRV_CONTENT_TYPE_PLAIN;
    response.data           = buffer;
    response.data_length    = strlen(buffer);
    response.content_length = response.data_length;
    HTTPSRV_cgi_write(&response);

    return (response.content_length);
}

/* Link lost callback */
static void LinkStatusChangeCallback(bool linkState)
{
    if (linkState == false)
    {
        /* -------- LINK LOST -------- */
        /* DO SOMETHING */
        PRINTF("-------- LINK LOST --------\r\n");
    }
    else
    {
        /* -------- LINK REESTABLISHED -------- */
        /* DO SOMETHING */
        PRINTF("-------- LINK REESTABLISHED --------\r\n");
    }
}

/*!
 * @brief The main task function
 */
static void main_task(void *arg)
{
    uint32_t result = 1;

    PRINTF(
        "\r\n"
        "Starting webconfig DEMO\r\n");

    /* When the App starts up, it will first read the mflash to check if any
     * credentials have been saved from previous runs.
     * If the mflash is empty, the board starts and AP allowing the user to configure
     * the desired Wi-Fi network.
     * Otherwise the stored credentials will be used to connect to the Wi-Fi network.*/
    WC_DEBUG("[i] Trying to load data from mflash.\r\n");

    init_flash_storage(CONNECTION_INFO_FILENAME);

    char ssid[WPL_WIFI_SSID_LENGTH];
    char password[WPL_WIFI_PASSWORD_LENGTH];
    char security[WIFI_SECURITY_LENGTH];

    result = get_saved_wifi_credentials(CONNECTION_INFO_FILENAME, ssid, password, security);

    if (result == 1 && strcmp(ssid, "") != 0)
    {
        /* Credentials from last time have been found. The board will attempt to
         * connect to this network as a client */
        WC_DEBUG("[i] Saved SSID: %s, Password: %s, Security: %s\r\n", ssid, password, security);
        g_BoardState.wifiState = WIFI_STATE_CLIENT;
        strcpy(g_BoardState.ssid, ssid);
        strcpy(g_BoardState.password, password);
        strcpy(g_BoardState.security, security);
    }
    else
    {
        /* No credentials are stored, the board will start its own AP */
        WC_DEBUG("[i] Nothing stored yet\r\n");
        strcpy(g_BoardState.ssid, WIFI_SSID);
        strcpy(g_BoardState.password, WIFI_PASSWORD);
        g_BoardState.wifiState = WIFI_STATE_AP;
    }

    g_BoardState.connected = false;

    /* Initialize Wi-Fi board */
    WC_DEBUG("[i] Initializing Wi-Fi connection... \r\n");

    result = WPL_Init();
    if (result != WPLRET_SUCCESS)
    {
        PRINTF("[!] WPL Init failed: %d\r\n", (uint32_t)result);
        __BKPT(0);
    }

    result = WPL_Start(LinkStatusChangeCallback);
    if (result != WPLRET_SUCCESS)
    {
        PRINTF("[!] WPL Start failed %d\r\n", (uint32_t)result);
        __BKPT(0);
    }

    WC_DEBUG("[i] Successfully initialized Wi-Fi module\r\n");

    /* Start WebServer */
    if (xTaskCreate(http_srv_task, "http_srv_task", HTTPD_STACKSIZE, NULL, HTTPD_PRIORITY, NULL) != pdPASS)
    {
        PRINTF("[!] HTTPD Task creation failed.");
        while (1)
            __BKPT(0);
    }

    /* Here other tasks can be created that will run the enduser app.... */

    /* Main Loop */
    while (1)
    {
        /* The SetBoardTo<state> function will configure the board Wifi to that given state.
         * After that, this task will suspend itself. It will remain suspended until it is time
         * to switch the state again. Uppon resuming, it will clean up the current state.
         * Every time the Wi-Fi state changes, this loop will perform an iteration switching back
         * and fourth between the two states as required.
         */
        switch (g_BoardState.wifiState)
        {
            case WIFI_STATE_CLIENT:
                SetBoardToClient();
                /* Suspend here until its time to swtich back to AP */
                vTaskSuspend(NULL);
                CleanUpClient();
                //mqtt_freertos_run_thread(netif_default);
                break;
            case WIFI_STATE_AP:
            default:
                SetBoardToAP();
                /* Suspend here until its time to stop the AP */
                vTaskSuspend(NULL);
                CleanUpAP();
        }
    }
}

/* Initialize and start local AP */
static uint32_t SetBoardToAP()
{
    uint32_t result;

    /* Set the global ssid and password to the default AP ssid and password */
    strcpy(g_BoardState.ssid, WIFI_SSID);
    strcpy(g_BoardState.password, WIFI_PASSWORD);

    /* Start the access point */
    PRINTF("Starting Access Point: SSID: %s, Chnl: %d\r\n", g_BoardState.ssid, WIFI_AP_CHANNEL);
    result = WPL_Start_AP(g_BoardState.ssid, g_BoardState.password, WIFI_AP_CHANNEL);

    if (result != WPLRET_SUCCESS)
    {
        PRINTF("[!] Failed to start access point\r\n");
        while (1)
            __BKPT(0);
    }
    g_BoardState.connected = true;

    char ip[16];
    WPL_GetIP(ip, 0);
    PRINTF(" Now join that network on your device and connect to this IP: %s\r\n", ip);

    return 0;
}

/* Clean up the local AP after waiting for all tasks to clean up */
static uint32_t CleanUpAP()
{
    /* Give time for reply message to reach the web interface before destorying the conection */
    vTaskDelay(10000 / portTICK_PERIOD_MS);

    WC_DEBUG("[i] Stopping AP!\r\n");
    if (WPL_Stop_AP() != WPLRET_SUCCESS)
    {
        PRINTF("Error while stopping ap\r\n");
        while (1)
            __BKPT(0);
    }

    return 0;
}

/* Connect to the external AP in g_BoardState.ssid */
static uint32_t SetBoardToClient()
{
    int32_t result;
    // If we are already connected, skip the initialization
    if (!g_BoardState.connected)
    {
        /* Add Wi-Fi network */
        if (strstr(g_BoardState.security, "WPA3_SAE"))
        {
            result = WPL_AddNetworkWithSecurity(g_BoardState.ssid, g_BoardState.password, WIFI_NETWORK_LABEL, WPL_SECURITY_WPA3_SAE);
        }
        else
        {
            result = WPL_AddNetworkWithSecurity(g_BoardState.ssid, g_BoardState.password, WIFI_NETWORK_LABEL, WPL_SECURITY_WILDCARD);
        }
        if (result == WPLRET_SUCCESS)
        {
            PRINTF("Connecting as client to ssid: %s with password %s\r\n", g_BoardState.ssid, g_BoardState.password);
            result = WPL_Join(WIFI_NETWORK_LABEL);
        }

        if (result != WPLRET_SUCCESS)
        {
            PRINTF("[!] Cannot connect to Wi-Fi\r\n[!]ssid: %s\r\n[!]passphrase: %s\r\n", g_BoardState.ssid,
                   g_BoardState.password);
            char c;
            do
            {
                PRINTF("[i] To reset the board to AP mode, press 'r'.\r\n");
                PRINTF("[i] In order to try connecting again press 'a'.\r\n");

                do
                {
                    c = GETCHAR();
                    // Skip over \n and \r and don't print the prompt again, just get next char
                } while (c == '\n' || c == '\r');

                switch (c)
                {
                    case 'r':
                    case 'R':
                        if (reset_saved_wifi_credentials(CONNECTION_INFO_FILENAME) != 0)
                        {
                            PRINTF("[!] Error occured during resetting of saved credentials!\r\n");
                            while (1)
                                __BKPT(0);
                        }
                        else
                        {
                            // Reset back to AP mode
                            g_BoardState.wifiState = WIFI_STATE_AP;
                            return 0;
                        }
                        break;
                    case 'a':
                    case 'A':
                        // Try connecting again...
                        return 0;
                    default:
                        PRINTF("Unknown command %c, please try again.\r\n", c);
                }

            } while (1);
        }
        else
        {
            PRINTF("[i] Connected to Wi-Fi\r\nssid: %s\r\n[!]passphrase: %s\r\n", g_BoardState.ssid,
                   g_BoardState.password);
            g_BoardState.connected = true;
            char ip[16];
            WPL_GetIP(ip, 1);
            PRINTF(" Now join that network on your device and connect to this IP: %s\r\n", ip);
        }
    }
    return 0;
}

/* Wait for any transmissions to finish and clean up the Client connection */
static uint32_t CleanUpClient() {
    /* Give time for reply message to reach the web interface before destroying the connection */
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    /* Leave the external AP */
    if (WPL_Leave() != WPLRET_SUCCESS)
    {
        PRINTF("[!] Error Leaving from Client network.\r\n");
        __BKPT(0);
    }

    /* Remove the network profile */
    if (WPL_RemoveNetwork(WIFI_NETWORK_LABEL) != WPLRET_SUCCESS)
    {
        PRINTF("[!] Failed to remove network profile.\r\n");
        __BKPT(0);
    }

    return 0;
}
/*!
 * @brief Main function.
 */
int web_config_init(void) {
    /* Initialize the hardware */
    BOARD_InitHardware();

    /* Create the main Task */
    if (xTaskCreate(main_task, "main_task", 2048, NULL, configMAX_PRIORITIES - 4, &g_BoardState.mainTask) != pdPASS) {
        PRINTF("[!] MAIN Task creation failed!\r\n");
        while (1) ;
    }


}
