/*
** ###################################################################
**     Processors:          RW610ETA2I
**                          RW610HNA2I
**                          RW610UKA2I
**                          RW612ETA2I
**                          RW612HNA2I
**                          RW612UKA2I
**
**     Version:             rev. 3.0, 2025-04-07
**     Build:               b250519
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BUCK18
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-16)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**     - rev. 3.0 (2025-04-07)
**         Based on CRR Rev9.1.
**
** ###################################################################
*/

/*!
 * @file PERI_BUCK18.h
 * @version 3.0
 * @date 2025-04-07
 * @brief CMSIS Peripheral Access Layer for BUCK18
 *
 * CMSIS Peripheral Access Layer for BUCK18
 */

#if !defined(PERI_BUCK18_H_)
#define PERI_BUCK18_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_RW610ETA2I) || defined(CPU_RW610HNA2I) || defined(CPU_RW610UKA2I))
#include "RW610_COMMON.h"
#elif (defined(CPU_RW612ETA2I) || defined(CPU_RW612HNA2I) || defined(CPU_RW612UKA2I))
#include "RW612_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- BUCK18 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BUCK18_Peripheral_Access_Layer BUCK18 Peripheral Access Layer
 * @{
 */

/** BUCK18 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[96];
  __I  uint8_t BUCK_BYPASS_SOC_CTRL_ONE_RO_REG;    /**< BUCK_BYPASS_SOC_CTRL_ONE_RO_REG, offset: 0x60 */
  __I  uint8_t BUCK_BYPASS_SOC_CTRL_TWO_RO_REG;    /**< BUCK_BYPASS_SOC_CTRL_TWO_RO_REG, offset: 0x61 */
  __I  uint8_t REG_RO_ONE_REG;                     /**< REG_RO_ONE_REG, offset: 0x62 */
  __I  uint8_t REG_RO_TWO_REG;                     /**< REG_RO_TWO_REG, offset: 0x63 */
  __I  uint8_t REG_RO_THREE_REG;                   /**< REG_RO_THREE_REG, offset: 0x64 */
  __I  uint8_t REG_RO_FOUR_REG;                    /**< REG_RO_FOUR_REG, offset: 0x65 */
  __IO uint8_t SYS_CTRL_REG;                       /**< SYS_CTRL_REG, offset: 0x66 */
  __IO uint8_t BUCK_BYPASS_SOC_CTRL_ONE_RW_REG;    /**< BUCK_BYPASS_SOC_CTRL_ONE_RW_REG, offset: 0x67 */
  __IO uint8_t BUCK_BYPASS_SOC_CTRL_TWO_RW_REG;    /**< BUCK_BYPASS_SOC_CTRL_TWO_RW_REG, offset: 0x68 */
  __IO uint8_t BUCK_CTRL_ONE_REG;                  /**< BUCK_CTRL_ONE_REG, offset: 0x69 */
  __IO uint8_t BUCK_CTRL_TWO_REG;                  /**< BUCK_CTRL_TWO_REG, offset: 0x6A */
  __IO uint8_t BUCK_CTRL_THREE_REG;                /**< BUCK_CTRL_THREE_REG, offset: 0x6B */
  __IO uint8_t BUCK_CTRL_FOUR_REG;                 /**< BUCK_CTRL_FOUR_REG, offset: 0x6C */
  __IO uint8_t BUCK_CTRL_FIVE_REG;                 /**< BUCK_CTRL_FIVE_REG, offset: 0x6D */
  __IO uint8_t BUCK_CTRL_SIX_REG;                  /**< BUCK_CTRL_SIX_REG, offset: 0x6E */
  __IO uint8_t BUCK_CTRL_SEVEN_REG;                /**< BUCK_CTRL_SEVEN_REG, offset: 0x6F */
  __IO uint8_t BUCK_CTRL_EIGHT_REG;                /**< BUCK_CTRL_EIGHT_REG, offset: 0x70 */
  __IO uint8_t BUCK_CTRL_NINE_REG;                 /**< BUCK_CTRL_NINE_REG, offset: 0x71 */
  __IO uint8_t BUCK_CTRL_TEN_REG;                  /**< BUCK_CTRL_TEN_REG, offset: 0x72 */
  __IO uint8_t BUCK_CTRL_ELEVEN_REG;               /**< BUCK_CTRL_ELEVEN_REG, offset: 0x73 */
  __IO uint8_t BUCK_CTRL_TWELVE_REG;               /**< BUCK_CTRL_TWELVE_REG, offset: 0x74 */
  __IO uint8_t BUCK_CTRL_THIRTEEN_REG;             /**< BUCK_CTRL_THIRTEEN_REG, offset: 0x75 */
  __IO uint8_t BUCK_CTRL_FOURTEEN_REG;             /**< BUCK_CTRL_FOURTEEN_REG, offset: 0x76 */
  __IO uint8_t BUCK_CTRL_FIFTEEN_REG;              /**< BUCK_CTRL_FIFTEEN_REG, offset: 0x77 */
  __IO uint8_t BUCK_CTRL_SIXTEEN_REG;              /**< BUCK_CTRL_SIXTEEN_REG, offset: 0x78 */
  __IO uint8_t BUCK_CTRL_SEVENTEEN_REG;            /**< BUCK_CTRL_SEVENTEEN_REG, offset: 0x79 */
  __IO uint8_t BUCK_CTRL_EIGHTEEN_REG;             /**< BUCK_CTRL_EIGHTEEN_REG, offset: 0x7A */
  __IO uint8_t BUCK_CTRL_NINTEEN_REG;              /**< BUCK_CTRL_NINTEEN_REG, offset: 0x7B */
  __IO uint8_t BUCK_CTRL_TWENTY_REG;               /**< BUCK_CTRL_TWENTY_REG, offset: 0x7C */
} BUCK18_Type;

/* ----------------------------------------------------------------------------
   -- BUCK18 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BUCK18_Register_Masks BUCK18 Register Masks
 * @{
 */

/*! @name BUCK_BYPASS_SOC_CTRL_ONE_RO_REG - BUCK_BYPASS_SOC_CTRL_ONE_RO_REG */
/*! @{ */

#define BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RO_REG_BUCK_BYPASS_SOC_CTRL_ONE_RO_MASK (0xFFU)
#define BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RO_REG_BUCK_BYPASS_SOC_CTRL_ONE_RO_SHIFT (0U)
/*! BUCK_BYPASS_SOC_CTRL_ONE_RO - Reserved. (Do not change) */
#define BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RO_REG_BUCK_BYPASS_SOC_CTRL_ONE_RO(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RO_REG_BUCK_BYPASS_SOC_CTRL_ONE_RO_SHIFT)) & BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RO_REG_BUCK_BYPASS_SOC_CTRL_ONE_RO_MASK)
/*! @} */

/*! @name BUCK_BYPASS_SOC_CTRL_TWO_RO_REG - BUCK_BYPASS_SOC_CTRL_TWO_RO_REG */
/*! @{ */

#define BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RO_REG_BUCK_BYPASS_SOC_CTRL_TWO_RO_MASK (0xFFU)
#define BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RO_REG_BUCK_BYPASS_SOC_CTRL_TWO_RO_SHIFT (0U)
/*! BUCK_BYPASS_SOC_CTRL_TWO_RO - Reserved. (Do not change) */
#define BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RO_REG_BUCK_BYPASS_SOC_CTRL_TWO_RO(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RO_REG_BUCK_BYPASS_SOC_CTRL_TWO_RO_SHIFT)) & BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RO_REG_BUCK_BYPASS_SOC_CTRL_TWO_RO_MASK)
/*! @} */

/*! @name REG_RO_ONE_REG - REG_RO_ONE_REG */
/*! @{ */

#define BUCK18_REG_RO_ONE_REG_REG_RO_ONE_MASK    (0xFFU)
#define BUCK18_REG_RO_ONE_REG_REG_RO_ONE_SHIFT   (0U)
/*! REG_RO_ONE - Reserved. (Do not change) */
#define BUCK18_REG_RO_ONE_REG_REG_RO_ONE(x)      (((uint8_t)(((uint8_t)(x)) << BUCK18_REG_RO_ONE_REG_REG_RO_ONE_SHIFT)) & BUCK18_REG_RO_ONE_REG_REG_RO_ONE_MASK)
/*! @} */

/*! @name REG_RO_TWO_REG - REG_RO_TWO_REG */
/*! @{ */

#define BUCK18_REG_RO_TWO_REG_REG_RO_TWO_MASK    (0xFFU)
#define BUCK18_REG_RO_TWO_REG_REG_RO_TWO_SHIFT   (0U)
/*! REG_RO_TWO - Reserved. (Do not change) */
#define BUCK18_REG_RO_TWO_REG_REG_RO_TWO(x)      (((uint8_t)(((uint8_t)(x)) << BUCK18_REG_RO_TWO_REG_REG_RO_TWO_SHIFT)) & BUCK18_REG_RO_TWO_REG_REG_RO_TWO_MASK)
/*! @} */

/*! @name REG_RO_THREE_REG - REG_RO_THREE_REG */
/*! @{ */

#define BUCK18_REG_RO_THREE_REG_REG_RO_THREE_MASK (0xFFU)
#define BUCK18_REG_RO_THREE_REG_REG_RO_THREE_SHIFT (0U)
/*! REG_RO_THREE - Reserved. (Do not change) */
#define BUCK18_REG_RO_THREE_REG_REG_RO_THREE(x)  (((uint8_t)(((uint8_t)(x)) << BUCK18_REG_RO_THREE_REG_REG_RO_THREE_SHIFT)) & BUCK18_REG_RO_THREE_REG_REG_RO_THREE_MASK)
/*! @} */

/*! @name REG_RO_FOUR_REG - REG_RO_FOUR_REG */
/*! @{ */

#define BUCK18_REG_RO_FOUR_REG_REG_RO_FOUR_MASK  (0xFFU)
#define BUCK18_REG_RO_FOUR_REG_REG_RO_FOUR_SHIFT (0U)
/*! REG_RO_FOUR - Reserved. (Do not change) */
#define BUCK18_REG_RO_FOUR_REG_REG_RO_FOUR(x)    (((uint8_t)(((uint8_t)(x)) << BUCK18_REG_RO_FOUR_REG_REG_RO_FOUR_SHIFT)) & BUCK18_REG_RO_FOUR_REG_REG_RO_FOUR_MASK)
/*! @} */

/*! @name SYS_CTRL_REG - SYS_CTRL_REG */
/*! @{ */

#define BUCK18_SYS_CTRL_REG_REG_SYS_CTRL_MASK    (0xFFU)
#define BUCK18_SYS_CTRL_REG_REG_SYS_CTRL_SHIFT   (0U)
/*! REG_SYS_CTRL - Reserved. (Do not change) */
#define BUCK18_SYS_CTRL_REG_REG_SYS_CTRL(x)      (((uint8_t)(((uint8_t)(x)) << BUCK18_SYS_CTRL_REG_REG_SYS_CTRL_SHIFT)) & BUCK18_SYS_CTRL_REG_REG_SYS_CTRL_MASK)
/*! @} */

/*! @name BUCK_BYPASS_SOC_CTRL_ONE_RW_REG - BUCK_BYPASS_SOC_CTRL_ONE_RW_REG */
/*! @{ */

#define BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_ONE_RW_MASK (0xFFU)
#define BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_ONE_RW_SHIFT (0U)
/*! REG_BUCK_BYPASS_SOC_CTRL_ONE_RW - Reserved. (Do not change) */
#define BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_ONE_RW(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_ONE_RW_SHIFT)) & BUCK18_BUCK_BYPASS_SOC_CTRL_ONE_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_ONE_RW_MASK)
/*! @} */

/*! @name BUCK_BYPASS_SOC_CTRL_TWO_RW_REG - BUCK_BYPASS_SOC_CTRL_TWO_RW_REG */
/*! @{ */

#define BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_TWO_RW_MASK (0xFFU)
#define BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_TWO_RW_SHIFT (0U)
/*! REG_BUCK_BYPASS_SOC_CTRL_TWO_RW - Reserved. (Do not change) */
#define BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_TWO_RW(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_TWO_RW_SHIFT)) & BUCK18_BUCK_BYPASS_SOC_CTRL_TWO_RW_REG_REG_BUCK_BYPASS_SOC_CTRL_TWO_RW_MASK)
/*! @} */

/*! @name BUCK_CTRL_ONE_REG - BUCK_CTRL_ONE_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_ONE_REG_REG_BUCK_CTRL_ONE_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_ONE_REG_REG_BUCK_CTRL_ONE_SHIFT (0U)
/*! REG_BUCK_CTRL_ONE - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_ONE_REG_REG_BUCK_CTRL_ONE(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_ONE_REG_REG_BUCK_CTRL_ONE_SHIFT)) & BUCK18_BUCK_CTRL_ONE_REG_REG_BUCK_CTRL_ONE_MASK)
/*! @} */

/*! @name BUCK_CTRL_TWO_REG - BUCK_CTRL_TWO_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_TWO_REG_REG_BUCK_CTRL_TWO_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_TWO_REG_REG_BUCK_CTRL_TWO_SHIFT (0U)
/*! REG_BUCK_CTRL_TWO - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_TWO_REG_REG_BUCK_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWO_REG_REG_BUCK_CTRL_TWO_SHIFT)) & BUCK18_BUCK_CTRL_TWO_REG_REG_BUCK_CTRL_TWO_MASK)
/*! @} */

/*! @name BUCK_CTRL_THREE_REG - BUCK_CTRL_THREE_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_THREE_REG_D_NONOV_SEL_MASK (0x3U)
#define BUCK18_BUCK_CTRL_THREE_REG_D_NONOV_SEL_SHIFT (0U)
/*! D_NONOV_SEL - Tune NONOV time between NSW off --> PSW ON */
#define BUCK18_BUCK_CTRL_THREE_REG_D_NONOV_SEL(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_THREE_REG_D_NONOV_SEL_SHIFT)) & BUCK18_BUCK_CTRL_THREE_REG_D_NONOV_SEL_MASK)

#define BUCK18_BUCK_CTRL_THREE_REG_DB_NONOV_SEL_MASK (0xCU)
#define BUCK18_BUCK_CTRL_THREE_REG_DB_NONOV_SEL_SHIFT (2U)
/*! DB_NONOV_SEL - Tune NONOV time between PSW off --> NSW ON */
#define BUCK18_BUCK_CTRL_THREE_REG_DB_NONOV_SEL(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_THREE_REG_DB_NONOV_SEL_SHIFT)) & BUCK18_BUCK_CTRL_THREE_REG_DB_NONOV_SEL_MASK)

#define BUCK18_BUCK_CTRL_THREE_REG_SOC_BUCK_RINGOSC_CTRL_MASK (0x10U)
#define BUCK18_BUCK_CTRL_THREE_REG_SOC_BUCK_RINGOSC_CTRL_SHIFT (4U)
/*! SOC_BUCK_RINGOSC_CTRL - SOC_BUCK_RINGOSC_CTRL */
#define BUCK18_BUCK_CTRL_THREE_REG_SOC_BUCK_RINGOSC_CTRL(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_THREE_REG_SOC_BUCK_RINGOSC_CTRL_SHIFT)) & BUCK18_BUCK_CTRL_THREE_REG_SOC_BUCK_RINGOSC_CTRL_MASK)

#define BUCK18_BUCK_CTRL_THREE_REG_RINGOSC_FORCE_ON_MASK (0x20U)
#define BUCK18_BUCK_CTRL_THREE_REG_RINGOSC_FORCE_ON_SHIFT (5U)
/*! RINGOSC_FORCE_ON - RINGOSC_FORCE_ON */
#define BUCK18_BUCK_CTRL_THREE_REG_RINGOSC_FORCE_ON(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_THREE_REG_RINGOSC_FORCE_ON_SHIFT)) & BUCK18_BUCK_CTRL_THREE_REG_RINGOSC_FORCE_ON_MASK)

#define BUCK18_BUCK_CTRL_THREE_REG_AT_PAD_EN_MASK (0x40U)
#define BUCK18_BUCK_CTRL_THREE_REG_AT_PAD_EN_SHIFT (6U)
/*! AT_PAD_EN - Buck DCPT is connected to BUCK_VSENSE pin */
#define BUCK18_BUCK_CTRL_THREE_REG_AT_PAD_EN(x)  (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_THREE_REG_AT_PAD_EN_SHIFT)) & BUCK18_BUCK_CTRL_THREE_REG_AT_PAD_EN_MASK)

#define BUCK18_BUCK_CTRL_THREE_REG_BUCK_MODE_OSC_MASK (0x80U)
#define BUCK18_BUCK_CTRL_THREE_REG_BUCK_MODE_OSC_SHIFT (7U)
/*! BUCK_MODE_OSC - Special test mode, Buck control circuits are operating with power switch-off. */
#define BUCK18_BUCK_CTRL_THREE_REG_BUCK_MODE_OSC(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_THREE_REG_BUCK_MODE_OSC_SHIFT)) & BUCK18_BUCK_CTRL_THREE_REG_BUCK_MODE_OSC_MASK)
/*! @} */

/*! @name BUCK_CTRL_FOUR_REG - BUCK_CTRL_FOUR_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_FOUR_REG_REG_BUCK_CTRL_FOUR_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_FOUR_REG_REG_BUCK_CTRL_FOUR_SHIFT (0U)
/*! REG_BUCK_CTRL_FOUR - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_FOUR_REG_REG_BUCK_CTRL_FOUR(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_FOUR_REG_REG_BUCK_CTRL_FOUR_SHIFT)) & BUCK18_BUCK_CTRL_FOUR_REG_REG_BUCK_CTRL_FOUR_MASK)
/*! @} */

/*! @name BUCK_CTRL_FIVE_REG - BUCK_CTRL_FIVE_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_FIVE_REG_REG_BUCK_CTRL_FIVE_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_FIVE_REG_REG_BUCK_CTRL_FIVE_SHIFT (0U)
/*! REG_BUCK_CTRL_FIVE - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_FIVE_REG_REG_BUCK_CTRL_FIVE(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_FIVE_REG_REG_BUCK_CTRL_FIVE_SHIFT)) & BUCK18_BUCK_CTRL_FIVE_REG_REG_BUCK_CTRL_FIVE_MASK)
/*! @} */

/*! @name BUCK_CTRL_SIX_REG - BUCK_CTRL_SIX_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_SIX_REG_REG_BUCK_CTRL_SIX_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_SIX_REG_REG_BUCK_CTRL_SIX_SHIFT (0U)
/*! REG_BUCK_CTRL_SIX - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_SIX_REG_REG_BUCK_CTRL_SIX(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_SIX_REG_REG_BUCK_CTRL_SIX_SHIFT)) & BUCK18_BUCK_CTRL_SIX_REG_REG_BUCK_CTRL_SIX_MASK)
/*! @} */

/*! @name BUCK_CTRL_SEVEN_REG - BUCK_CTRL_SEVEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_SEVEN_REG_REG_BUCK_CTRL_SEVEN_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_SEVEN_REG_REG_BUCK_CTRL_SEVEN_SHIFT (0U)
/*! REG_BUCK_CTRL_SEVEN - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_SEVEN_REG_REG_BUCK_CTRL_SEVEN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_SEVEN_REG_REG_BUCK_CTRL_SEVEN_SHIFT)) & BUCK18_BUCK_CTRL_SEVEN_REG_REG_BUCK_CTRL_SEVEN_MASK)
/*! @} */

/*! @name BUCK_CTRL_EIGHT_REG - BUCK_CTRL_EIGHT_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_EIGHT_REG_REG_BUCK_CTRL_EIGHT_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_EIGHT_REG_REG_BUCK_CTRL_EIGHT_SHIFT (0U)
/*! REG_BUCK_CTRL_EIGHT - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_EIGHT_REG_REG_BUCK_CTRL_EIGHT(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_EIGHT_REG_REG_BUCK_CTRL_EIGHT_SHIFT)) & BUCK18_BUCK_CTRL_EIGHT_REG_REG_BUCK_CTRL_EIGHT_MASK)
/*! @} */

/*! @name BUCK_CTRL_NINE_REG - BUCK_CTRL_NINE_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_NINE_REG_REG_BUCK_CTRL_NINE_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_NINE_REG_REG_BUCK_CTRL_NINE_SHIFT (0U)
/*! REG_BUCK_CTRL_NINE - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_NINE_REG_REG_BUCK_CTRL_NINE(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_NINE_REG_REG_BUCK_CTRL_NINE_SHIFT)) & BUCK18_BUCK_CTRL_NINE_REG_REG_BUCK_CTRL_NINE_MASK)
/*! @} */

/*! @name BUCK_CTRL_TEN_REG - BUCK_CTRL_TEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_TEN_REG_REG_BUCK_CTRL_TEN_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_TEN_REG_REG_BUCK_CTRL_TEN_SHIFT (0U)
/*! REG_BUCK_CTRL_TEN - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_TEN_REG_REG_BUCK_CTRL_TEN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TEN_REG_REG_BUCK_CTRL_TEN_SHIFT)) & BUCK18_BUCK_CTRL_TEN_REG_REG_BUCK_CTRL_TEN_MASK)
/*! @} */

/*! @name BUCK_CTRL_ELEVEN_REG - BUCK_CTRL_ELEVEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_ELEVEN_REG_VBAT_LOW_VTH_SEL_MASK (0x3U)
#define BUCK18_BUCK_CTRL_ELEVEN_REG_VBAT_LOW_VTH_SEL_SHIFT (0U)
/*! VBAT_LOW_VTH_SEL - VBAT detection threshold */
#define BUCK18_BUCK_CTRL_ELEVEN_REG_VBAT_LOW_VTH_SEL(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_ELEVEN_REG_VBAT_LOW_VTH_SEL_SHIFT)) & BUCK18_BUCK_CTRL_ELEVEN_REG_VBAT_LOW_VTH_SEL_MASK)

#define BUCK18_BUCK_CTRL_ELEVEN_REG_SUP_OFF_SEL_MASK (0x4U)
#define BUCK18_BUCK_CTRL_ELEVEN_REG_SUP_OFF_SEL_SHIFT (2U)
/*! SUP_OFF_SEL - When Buck is in power down, collapse the internal supply or not */
#define BUCK18_BUCK_CTRL_ELEVEN_REG_SUP_OFF_SEL(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_ELEVEN_REG_SUP_OFF_SEL_SHIFT)) & BUCK18_BUCK_CTRL_ELEVEN_REG_SUP_OFF_SEL_MASK)

#define BUCK18_BUCK_CTRL_ELEVEN_REG_USE_EXT_SUP_MASK (0x8U)
#define BUCK18_BUCK_CTRL_ELEVEN_REG_USE_EXT_SUP_SHIFT (3U)
/*! USE_EXT_SUP - Use BUCK18 output for internal V18 rails */
#define BUCK18_BUCK_CTRL_ELEVEN_REG_USE_EXT_SUP(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_ELEVEN_REG_USE_EXT_SUP_SHIFT)) & BUCK18_BUCK_CTRL_ELEVEN_REG_USE_EXT_SUP_MASK)

#define BUCK18_BUCK_CTRL_ELEVEN_REG_SLEEP_HYS_SEL_MASK (0x70U)
#define BUCK18_BUCK_CTRL_ELEVEN_REG_SLEEP_HYS_SEL_SHIFT (4U)
/*! SLEEP_HYS_SEL - switching frequency in sleep mode */
#define BUCK18_BUCK_CTRL_ELEVEN_REG_SLEEP_HYS_SEL(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_ELEVEN_REG_SLEEP_HYS_SEL_SHIFT)) & BUCK18_BUCK_CTRL_ELEVEN_REG_SLEEP_HYS_SEL_MASK)

#define BUCK18_BUCK_CTRL_ELEVEN_REG_RSVD_MASK    (0x80U)
#define BUCK18_BUCK_CTRL_ELEVEN_REG_RSVD_SHIFT   (7U)
/*! RSVD - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_ELEVEN_REG_RSVD(x)      (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_ELEVEN_REG_RSVD_SHIFT)) & BUCK18_BUCK_CTRL_ELEVEN_REG_RSVD_MASK)
/*! @} */

/*! @name BUCK_CTRL_TWELVE_REG - BUCK_CTRL_TWELVE_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_TWELVE_REG_REG_BUCK_CTRL_TWELVE_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_TWELVE_REG_REG_BUCK_CTRL_TWELVE_SHIFT (0U)
/*! REG_BUCK_CTRL_TWELVE - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_TWELVE_REG_REG_BUCK_CTRL_TWELVE(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWELVE_REG_REG_BUCK_CTRL_TWELVE_SHIFT)) & BUCK18_BUCK_CTRL_TWELVE_REG_REG_BUCK_CTRL_TWELVE_MASK)
/*! @} */

/*! @name BUCK_CTRL_THIRTEEN_REG - BUCK_CTRL_THIRTEEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_THIRTEEN_REG_REG_BUCK_CTRL_THIRTEEN_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_THIRTEEN_REG_REG_BUCK_CTRL_THIRTEEN_SHIFT (0U)
/*! REG_BUCK_CTRL_THIRTEEN - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_THIRTEEN_REG_REG_BUCK_CTRL_THIRTEEN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_THIRTEEN_REG_REG_BUCK_CTRL_THIRTEEN_SHIFT)) & BUCK18_BUCK_CTRL_THIRTEEN_REG_REG_BUCK_CTRL_THIRTEEN_MASK)
/*! @} */

/*! @name BUCK_CTRL_FOURTEEN_REG - BUCK_CTRL_FOURTEEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_FOURTEEN_REG_REG_BUCK_CTRL_FOURTEEN_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_FOURTEEN_REG_REG_BUCK_CTRL_FOURTEEN_SHIFT (0U)
/*! REG_BUCK_CTRL_FOURTEEN - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_FOURTEEN_REG_REG_BUCK_CTRL_FOURTEEN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_FOURTEEN_REG_REG_BUCK_CTRL_FOURTEEN_SHIFT)) & BUCK18_BUCK_CTRL_FOURTEEN_REG_REG_BUCK_CTRL_FOURTEEN_MASK)
/*! @} */

/*! @name BUCK_CTRL_FIFTEEN_REG - BUCK_CTRL_FIFTEEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_FIFTEEN_REG_REG_BUCK_CTRL_FIFTEEN_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_FIFTEEN_REG_REG_BUCK_CTRL_FIFTEEN_SHIFT (0U)
/*! REG_BUCK_CTRL_FIFTEEN - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_FIFTEEN_REG_REG_BUCK_CTRL_FIFTEEN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_FIFTEEN_REG_REG_BUCK_CTRL_FIFTEEN_SHIFT)) & BUCK18_BUCK_CTRL_FIFTEEN_REG_REG_BUCK_CTRL_FIFTEEN_MASK)
/*! @} */

/*! @name BUCK_CTRL_SIXTEEN_REG - BUCK_CTRL_SIXTEEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_SIXTEEN_REG_REG_BUCK_CTRL_SIXTEEN_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_SIXTEEN_REG_REG_BUCK_CTRL_SIXTEEN_SHIFT (0U)
/*! REG_BUCK_CTRL_SIXTEEN - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_SIXTEEN_REG_REG_BUCK_CTRL_SIXTEEN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_SIXTEEN_REG_REG_BUCK_CTRL_SIXTEEN_SHIFT)) & BUCK18_BUCK_CTRL_SIXTEEN_REG_REG_BUCK_CTRL_SIXTEEN_MASK)
/*! @} */

/*! @name BUCK_CTRL_SEVENTEEN_REG - BUCK_CTRL_SEVENTEEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_SEVENTEEN_REG_REG_BUCK_CTRL_SEVENTEEN_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_SEVENTEEN_REG_REG_BUCK_CTRL_SEVENTEEN_SHIFT (0U)
/*! REG_BUCK_CTRL_SEVENTEEN - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_SEVENTEEN_REG_REG_BUCK_CTRL_SEVENTEEN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_SEVENTEEN_REG_REG_BUCK_CTRL_SEVENTEEN_SHIFT)) & BUCK18_BUCK_CTRL_SEVENTEEN_REG_REG_BUCK_CTRL_SEVENTEEN_MASK)
/*! @} */

/*! @name BUCK_CTRL_EIGHTEEN_REG - BUCK_CTRL_EIGHTEEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_EIGHTEEN_REG_REG_BUCK_CTRL_EIGHTEEN_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_EIGHTEEN_REG_REG_BUCK_CTRL_EIGHTEEN_SHIFT (0U)
/*! REG_BUCK_CTRL_EIGHTEEN - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_EIGHTEEN_REG_REG_BUCK_CTRL_EIGHTEEN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_EIGHTEEN_REG_REG_BUCK_CTRL_EIGHTEEN_SHIFT)) & BUCK18_BUCK_CTRL_EIGHTEEN_REG_REG_BUCK_CTRL_EIGHTEEN_MASK)
/*! @} */

/*! @name BUCK_CTRL_NINTEEN_REG - BUCK_CTRL_NINTEEN_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_NINTEEN_REG_REG_BUCK_CTRL_NINTEEN_MASK (0xFFU)
#define BUCK18_BUCK_CTRL_NINTEEN_REG_REG_BUCK_CTRL_NINTEEN_SHIFT (0U)
/*! REG_BUCK_CTRL_NINTEEN - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_NINTEEN_REG_REG_BUCK_CTRL_NINTEEN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_NINTEEN_REG_REG_BUCK_CTRL_NINTEEN_SHIFT)) & BUCK18_BUCK_CTRL_NINTEEN_REG_REG_BUCK_CTRL_NINTEEN_MASK)
/*! @} */

/*! @name BUCK_CTRL_TWENTY_REG - BUCK_CTRL_TWENTY_REG */
/*! @{ */

#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP_VAL_MASK (0x1U)
#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP_VAL_SHIFT (0U)
/*! SHORT_V18_BYP_VAL - SHORT_V18_BYP_VAL */
#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP_VAL(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP_VAL_SHIFT)) & BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP_VAL_MASK)

#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP_MASK (0x2U)
#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP_SHIFT (1U)
/*! SHORT_V18_BYP - SHORT_V18_BYP */
#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP_SHIFT)) & BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_V18_BYP_MASK)

#define BUCK18_BUCK_CTRL_TWENTY_REG_V18_AON_SHORT_EN_MASK (0x4U)
#define BUCK18_BUCK_CTRL_TWENTY_REG_V18_AON_SHORT_EN_SHIFT (2U)
/*! V18_AON_SHORT_EN - V18_AON_SHORT_EN */
#define BUCK18_BUCK_CTRL_TWENTY_REG_V18_AON_SHORT_EN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWENTY_REG_V18_AON_SHORT_EN_SHIFT)) & BUCK18_BUCK_CTRL_TWENTY_REG_V18_AON_SHORT_EN_MASK)

#define BUCK18_BUCK_CTRL_TWENTY_REG_BUCK18_RDY_BYP_MASK (0x8U)
#define BUCK18_BUCK_CTRL_TWENTY_REG_BUCK18_RDY_BYP_SHIFT (3U)
/*! BUCK18_RDY_BYP - BUCK18_RDY_BYP */
#define BUCK18_BUCK_CTRL_TWENTY_REG_BUCK18_RDY_BYP(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWENTY_REG_BUCK18_RDY_BYP_SHIFT)) & BUCK18_BUCK_CTRL_TWENTY_REG_BUCK18_RDY_BYP_MASK)

#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB_SLEEP_MASK (0x10U)
#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB_SLEEP_SHIFT (4U)
/*! SHORT_C18_ENB_SLEEP - It is used in buck18_lvlshf_bank_A1 cell */
#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB_SLEEP(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB_SLEEP_SHIFT)) & BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB_SLEEP_MASK)

#define BUCK18_BUCK_CTRL_TWENTY_REG_RESERVED_MASK (0x20U)
#define BUCK18_BUCK_CTRL_TWENTY_REG_RESERVED_SHIFT (5U)
/*! RESERVED - Reserved. (Do not change) */
#define BUCK18_BUCK_CTRL_TWENTY_REG_RESERVED(x)  (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWENTY_REG_RESERVED_SHIFT)) & BUCK18_BUCK_CTRL_TWENTY_REG_RESERVED_MASK)

#define BUCK18_BUCK_CTRL_TWENTY_REG_CLK_OUT_EN_MASK (0x40U)
#define BUCK18_BUCK_CTRL_TWENTY_REG_CLK_OUT_EN_SHIFT (6U)
/*! CLK_OUT_EN - CLK_OUT_EN */
#define BUCK18_BUCK_CTRL_TWENTY_REG_CLK_OUT_EN(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWENTY_REG_CLK_OUT_EN_SHIFT)) & BUCK18_BUCK_CTRL_TWENTY_REG_CLK_OUT_EN_MASK)

#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB_MASK (0x80U)
#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB_SHIFT (7U)
/*! SHORT_C18_ENB - 0: short C18 and Buck18 output once V18_RDY */
#define BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB(x) (((uint8_t)(((uint8_t)(x)) << BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB_SHIFT)) & BUCK18_BUCK_CTRL_TWENTY_REG_SHORT_C18_ENB_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BUCK18_Register_Masks */


/*!
 * @}
 */ /* end of group BUCK18_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_BUCK18_H_ */

