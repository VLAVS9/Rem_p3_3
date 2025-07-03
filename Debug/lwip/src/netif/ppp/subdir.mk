################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwip/src/netif/ppp/auth.c \
../lwip/src/netif/ppp/ccp.c \
../lwip/src/netif/ppp/chap-md5.c \
../lwip/src/netif/ppp/chap-new.c \
../lwip/src/netif/ppp/chap_ms.c \
../lwip/src/netif/ppp/demand.c \
../lwip/src/netif/ppp/eap.c \
../lwip/src/netif/ppp/ecp.c \
../lwip/src/netif/ppp/eui64.c \
../lwip/src/netif/ppp/fsm.c \
../lwip/src/netif/ppp/ipcp.c \
../lwip/src/netif/ppp/ipv6cp.c \
../lwip/src/netif/ppp/lcp.c \
../lwip/src/netif/ppp/magic.c \
../lwip/src/netif/ppp/mppe.c \
../lwip/src/netif/ppp/multilink.c \
../lwip/src/netif/ppp/ppp.c \
../lwip/src/netif/ppp/pppapi.c \
../lwip/src/netif/ppp/pppcrypt.c \
../lwip/src/netif/ppp/pppoe.c \
../lwip/src/netif/ppp/pppol2tp.c \
../lwip/src/netif/ppp/pppos.c \
../lwip/src/netif/ppp/upap.c \
../lwip/src/netif/ppp/utils.c \
../lwip/src/netif/ppp/vj.c 

C_DEPS += \
./lwip/src/netif/ppp/auth.d \
./lwip/src/netif/ppp/ccp.d \
./lwip/src/netif/ppp/chap-md5.d \
./lwip/src/netif/ppp/chap-new.d \
./lwip/src/netif/ppp/chap_ms.d \
./lwip/src/netif/ppp/demand.d \
./lwip/src/netif/ppp/eap.d \
./lwip/src/netif/ppp/ecp.d \
./lwip/src/netif/ppp/eui64.d \
./lwip/src/netif/ppp/fsm.d \
./lwip/src/netif/ppp/ipcp.d \
./lwip/src/netif/ppp/ipv6cp.d \
./lwip/src/netif/ppp/lcp.d \
./lwip/src/netif/ppp/magic.d \
./lwip/src/netif/ppp/mppe.d \
./lwip/src/netif/ppp/multilink.d \
./lwip/src/netif/ppp/ppp.d \
./lwip/src/netif/ppp/pppapi.d \
./lwip/src/netif/ppp/pppcrypt.d \
./lwip/src/netif/ppp/pppoe.d \
./lwip/src/netif/ppp/pppol2tp.d \
./lwip/src/netif/ppp/pppos.d \
./lwip/src/netif/ppp/upap.d \
./lwip/src/netif/ppp/utils.d \
./lwip/src/netif/ppp/vj.d 

OBJS += \
./lwip/src/netif/ppp/auth.o \
./lwip/src/netif/ppp/ccp.o \
./lwip/src/netif/ppp/chap-md5.o \
./lwip/src/netif/ppp/chap-new.o \
./lwip/src/netif/ppp/chap_ms.o \
./lwip/src/netif/ppp/demand.o \
./lwip/src/netif/ppp/eap.o \
./lwip/src/netif/ppp/ecp.o \
./lwip/src/netif/ppp/eui64.o \
./lwip/src/netif/ppp/fsm.o \
./lwip/src/netif/ppp/ipcp.o \
./lwip/src/netif/ppp/ipv6cp.o \
./lwip/src/netif/ppp/lcp.o \
./lwip/src/netif/ppp/magic.o \
./lwip/src/netif/ppp/mppe.o \
./lwip/src/netif/ppp/multilink.o \
./lwip/src/netif/ppp/ppp.o \
./lwip/src/netif/ppp/pppapi.o \
./lwip/src/netif/ppp/pppcrypt.o \
./lwip/src/netif/ppp/pppoe.o \
./lwip/src/netif/ppp/pppol2tp.o \
./lwip/src/netif/ppp/pppos.o \
./lwip/src/netif/ppp/upap.o \
./lwip/src/netif/ppp/utils.o \
./lwip/src/netif/ppp/vj.o 


# Each subdirectory must supply rules for building sources it contributes
lwip/src/netif/ppp/%.o: ../lwip/src/netif/ppp/%.c lwip/src/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_RW612ETA2I -DCPU_RW612ETA2I_cm33_nodsp -DMCUXPRESSO_SDK -DLWIP_TIMEVAL_PRIVATE=0 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DUSE_RTOS=1 -DPRINTF_ADVANCED_ENABLE=1 -DLWIP_NETIF_API=1 -DHTTPSRV_CFG_WEBSOCKET_ENABLED=1 -DHTTPSRV_CFG_DEFAULT_SES_CNT=8 -DSDK_DEBUGCONSOLE_UART -DMCUX_META_BUILD -DRW612_SERIES -DOSA_USED -DBOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DWIFI_BOARD_FRDM_RW61X -DMFLASH_FILE_BASEADDR=7340032 -DCONFIG_NXP_WIFI_SOFTAP_SUPPORT=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -DSDK_DEBUGCONSOLE=0 -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/flash_config" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/drivers" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/CMSIS" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/CMSIS/m-profile" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/device" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/device/periph" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/drivers/freertos" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/utilities" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/lists" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/utilities/str" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/utilities/debug_console" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/serial_manager" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/uart" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/imu_adapter" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/osa/config" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/osa" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/edgefast_wifi/include" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/wifi_bt_module/AzureWave/tx_pwr_limits" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/wifi_bt_module/Murata/tx_pwr_limits" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/wifi_bt_module/u-blox/tx_pwr_limits" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/wifi_bt_module/incl" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxClBuffer/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxClBuffer/inc/internal" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxClCore/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxClEls/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxClEls/inc/internal" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxClMemory/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxClMemory/inc/internal" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxCsslMemory/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxCsslMemory/inc/internal" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxCsslCPreProcessor/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxCsslDataIntegrity/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxCsslFlowProtection/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxCsslParamIntegrity/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/comps/mcuxCsslSecureCounter/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/compiler" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/platforms/rw61x" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/src/platforms/rw61x/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/els_pkc/includes/platform/rw61x" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/flash/mflash" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/flash/mflash/frdmrw612" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/conn_fwloader/include" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/conn_fwloader/fw_bin" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/conn_fwloader/fw_bin/inc" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/conn_fwloader/fw_bin/rw61x" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/conn_fwloader/fw_bin/script" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/incl" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/incl/port/osa" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/port/osa" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/incl/port" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/incl/wifidriver" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/wifi_bt_firmware" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/wifidriver" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/wifidriver/incl" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/incl/wlcmgr" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/wifidriver/wpa_supp_if" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/wifidriver/wpa_supp_if/incl" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/certs" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/firmware_dnld" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/sdio_nxp_abs" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/sdio_nxp_abs/incl" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/incl/port/net" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/port/net" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/wifi/incl/port/net/hooks" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/lwip/port" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/lwip/src/include" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/lwip/port/sys_arch/dynamic" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/lwip/src/apps/httpsrv" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/freertos/freertos-kernel/include" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/freertos/freertos-kernel/portable/GCC/ARM_CM33_NTZ/non_secure" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component/silicon_id" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/component" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/freertos/freertos-kernel/template" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/freertos/freertos-kernel/template/ARM_CM33_3_priority_bits" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/lwip/template" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/source" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/board" -O0 -fno-common -g3 -gdwarf-4 -c -ffunction-sections -fdata-sections -fno-builtin -mcpu=cortex-m33+nodsp -imacros "/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_25.6.136/workspace/612_wifi_webconfig/source/mcux_config.h" -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33+nodsp -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lwip-2f-src-2f-netif-2f-ppp

clean-lwip-2f-src-2f-netif-2f-ppp:
	-$(RM) ./lwip/src/netif/ppp/auth.d ./lwip/src/netif/ppp/auth.o ./lwip/src/netif/ppp/ccp.d ./lwip/src/netif/ppp/ccp.o ./lwip/src/netif/ppp/chap-md5.d ./lwip/src/netif/ppp/chap-md5.o ./lwip/src/netif/ppp/chap-new.d ./lwip/src/netif/ppp/chap-new.o ./lwip/src/netif/ppp/chap_ms.d ./lwip/src/netif/ppp/chap_ms.o ./lwip/src/netif/ppp/demand.d ./lwip/src/netif/ppp/demand.o ./lwip/src/netif/ppp/eap.d ./lwip/src/netif/ppp/eap.o ./lwip/src/netif/ppp/ecp.d ./lwip/src/netif/ppp/ecp.o ./lwip/src/netif/ppp/eui64.d ./lwip/src/netif/ppp/eui64.o ./lwip/src/netif/ppp/fsm.d ./lwip/src/netif/ppp/fsm.o ./lwip/src/netif/ppp/ipcp.d ./lwip/src/netif/ppp/ipcp.o ./lwip/src/netif/ppp/ipv6cp.d ./lwip/src/netif/ppp/ipv6cp.o ./lwip/src/netif/ppp/lcp.d ./lwip/src/netif/ppp/lcp.o ./lwip/src/netif/ppp/magic.d ./lwip/src/netif/ppp/magic.o ./lwip/src/netif/ppp/mppe.d ./lwip/src/netif/ppp/mppe.o ./lwip/src/netif/ppp/multilink.d ./lwip/src/netif/ppp/multilink.o ./lwip/src/netif/ppp/ppp.d ./lwip/src/netif/ppp/ppp.o ./lwip/src/netif/ppp/pppapi.d ./lwip/src/netif/ppp/pppapi.o ./lwip/src/netif/ppp/pppcrypt.d ./lwip/src/netif/ppp/pppcrypt.o ./lwip/src/netif/ppp/pppoe.d ./lwip/src/netif/ppp/pppoe.o ./lwip/src/netif/ppp/pppol2tp.d ./lwip/src/netif/ppp/pppol2tp.o ./lwip/src/netif/ppp/pppos.d ./lwip/src/netif/ppp/pppos.o ./lwip/src/netif/ppp/upap.d ./lwip/src/netif/ppp/upap.o ./lwip/src/netif/ppp/utils.d ./lwip/src/netif/ppp/utils.o ./lwip/src/netif/ppp/vj.d ./lwip/src/netif/ppp/vj.o

.PHONY: clean-lwip-2f-src-2f-netif-2f-ppp

