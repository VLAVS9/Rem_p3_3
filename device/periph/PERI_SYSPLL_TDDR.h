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
**         CMSIS Peripheral Access Layer for SYSPLL_TDDR
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
 * @file PERI_SYSPLL_TDDR.h
 * @version 3.0
 * @date 2025-04-07
 * @brief CMSIS Peripheral Access Layer for SYSPLL_TDDR
 *
 * CMSIS Peripheral Access Layer for SYSPLL_TDDR
 */

#if !defined(PERI_SYSPLL_TDDR_H_)
#define PERI_SYSPLL_TDDR_H_                      /**< Symbol preventing repeated inclusion */

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
   -- SYSPLL_TDDR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSPLL_TDDR_Peripheral_Access_Layer SYSPLL_TDDR Peripheral Access Layer
 * @{
 */

/** SYSPLL_TDDR - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[160];
  __I  uint8_t SYSBYPASS_SOC_CTRL_ONE_RO_REG;      /**< SYSBYPASS_SOC_CTRL_ONE_RO_REG, offset: 0xA0 */
  __I  uint8_t SYSBYPASS_SOC_CTRL_TWO_RO_REG;      /**< SYSBYPASS_SOC_CTRL_TWO_RO_REG, offset: 0xA1 */
  __I  uint8_t SYSBYPASS_SOC_CTRL_THREE_RO_REG;    /**< SYSBYPASS_SOC_CTRL_THREE_RO_REG, offset: 0xA2 */
  __I  uint8_t REG_RO_REG;                         /**< REG_RO_REG, offset: 0xA3 */
  __IO uint8_t SYS_CTRL_REG;                       /**< SYS_CTRL_REG, offset: 0xA4 */
  __IO uint8_t SYSBYPASS_SOC_CTRL_ONE_RW_REG;      /**< SYSBYPASS_SOC_CTRL_ONE_RW_REG, offset: 0xA5 */
  __IO uint8_t SYSBYPASS_SOC_CTRL_TWO_RW_REG;      /**< SYSBYPASS_SOC_CTRL_TWO_RW_REG, offset: 0xA6 */
  __IO uint8_t SYSBYPASS_SOC_CTRL_THREE_RW_REG;    /**< SYSBYPASS_SOC_CTRL_THREE_RW_REG, offset: 0xA7 */
  __IO uint8_t TDDR_CTRL_ONE_REG;                  /**< TDDR_CTRL_ONE_REG, offset: 0xA8 */
  __IO uint8_t TDDR_CTRL_TWO_REG;                  /**< TDDR_CTRL_TWO_REG, offset: 0xA9 */
  __IO uint8_t TDDR_CTRL_THREE_REG;                /**< TDDR_CTRL_THREE_REG, offset: 0xAA */
  __IO uint8_t TDDR_CTRL_FOUR_REG;                 /**< TDDR_CTRL_FOUR_REG, offset: 0xAB */
  __IO uint8_t TDDR_CTRL_FIVE_REG;                 /**< TDDR_CTRL_FIVE_REG, offset: 0xAC */
  __IO uint8_t TDDR_CTRL_SIX_REG;                  /**< TDDR_CTRL_SIX_REG, offset: 0xAD */
  __IO uint8_t CLKTREE_CTRL_ONE_REG;               /**< CLKTREE_CTRL_ONE_REG, offset: 0xAE */
  __IO uint8_t CLKTREE_CTRL_TWO_REG;               /**< CLKTREE_CTRL_TWO_REG, offset: 0xAF */
  __IO uint8_t GPIO_CTRL_REG;                      /**< GPIO_CTRL_REG, offset: 0xB0 */
  __IO uint8_t ATEST_CTRL_REG;                     /**< ATEST_CTRL_REG, offset: 0xB1 */
  __IO uint8_t RESERVED_LO_REG;                    /**< RESERVED_LO_REG, offset: 0xB2 */
  __IO uint8_t RESERVED_HI_REG;                    /**< RESERVED_HI_REG, offset: 0xB3 */
} SYSPLL_TDDR_Type;

/* ----------------------------------------------------------------------------
   -- SYSPLL_TDDR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSPLL_TDDR_Register_Masks SYSPLL_TDDR Register Masks
 * @{
 */

/*! @name SYSBYPASS_SOC_CTRL_ONE_RO_REG - SYSBYPASS_SOC_CTRL_ONE_RO_REG */
/*! @{ */

#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_MASK (0xFFU)
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_ONE_RO - Reserved. (Do not change) */
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_SHIFT)) & SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_TWO_RO_REG - SYSBYPASS_SOC_CTRL_TWO_RO_REG */
/*! @{ */

#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_MASK (0xFFU)
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_TWO_RO - Reserved. (Do not change) */
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_SHIFT)) & SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_THREE_RO_REG - SYSBYPASS_SOC_CTRL_THREE_RO_REG */
/*! @{ */

#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_MASK (0xFFU)
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_THREE_RO - Reserved. (Do not change) */
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_SHIFT)) & SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_MASK)
/*! @} */

/*! @name REG_RO_REG - REG_RO_REG */
/*! @{ */

#define SYSPLL_TDDR_REG_RO_REG_REG_RO_MASK       (0xFFU)
#define SYSPLL_TDDR_REG_RO_REG_REG_RO_SHIFT      (0U)
/*! REG_RO - Reserved. (Do not change) */
#define SYSPLL_TDDR_REG_RO_REG_REG_RO(x)         (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_REG_RO_REG_REG_RO_SHIFT)) & SYSPLL_TDDR_REG_RO_REG_REG_RO_MASK)
/*! @} */

/*! @name SYS_CTRL_REG - SYS_CTRL_REG */
/*! @{ */

#define SYSPLL_TDDR_SYS_CTRL_REG_REG_SYS_CTRL_MASK (0xFFU)
#define SYSPLL_TDDR_SYS_CTRL_REG_REG_SYS_CTRL_SHIFT (0U)
/*! REG_SYS_CTRL - Reserved. (Do not change) */
#define SYSPLL_TDDR_SYS_CTRL_REG_REG_SYS_CTRL(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_SYS_CTRL_REG_REG_SYS_CTRL_SHIFT)) & SYSPLL_TDDR_SYS_CTRL_REG_REG_SYS_CTRL_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_ONE_RW_REG - SYSBYPASS_SOC_CTRL_ONE_RW_REG */
/*! @{ */

#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RW_REG_REG_SYSBYPASS_SOC_CTRL_ONE_RW_MASK (0xFFU)
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RW_REG_REG_SYSBYPASS_SOC_CTRL_ONE_RW_SHIFT (0U)
/*! REG_SYSBYPASS_SOC_CTRL_ONE_RW - Reserved. (Do not change) */
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RW_REG_REG_SYSBYPASS_SOC_CTRL_ONE_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RW_REG_REG_SYSBYPASS_SOC_CTRL_ONE_RW_SHIFT)) & SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_ONE_RW_REG_REG_SYSBYPASS_SOC_CTRL_ONE_RW_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_TWO_RW_REG - SYSBYPASS_SOC_CTRL_TWO_RW_REG */
/*! @{ */

#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RW_REG_REG_SYSBYPASS_SOC_CTRL_TWO_RW_MASK (0xFFU)
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RW_REG_REG_SYSBYPASS_SOC_CTRL_TWO_RW_SHIFT (0U)
/*! REG_SYSBYPASS_SOC_CTRL_TWO_RW - Reserved. (Do not change) */
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RW_REG_REG_SYSBYPASS_SOC_CTRL_TWO_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RW_REG_REG_SYSBYPASS_SOC_CTRL_TWO_RW_SHIFT)) & SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_TWO_RW_REG_REG_SYSBYPASS_SOC_CTRL_TWO_RW_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_THREE_RW_REG - SYSBYPASS_SOC_CTRL_THREE_RW_REG */
/*! @{ */

#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RW_REG_REG_SYSBYPASS_SOC_CTRL_THREE_RW_MASK (0xFFU)
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RW_REG_REG_SYSBYPASS_SOC_CTRL_THREE_RW_SHIFT (0U)
/*! REG_SYSBYPASS_SOC_CTRL_THREE_RW - Reserved. (Do not change) */
#define SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RW_REG_REG_SYSBYPASS_SOC_CTRL_THREE_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RW_REG_REG_SYSBYPASS_SOC_CTRL_THREE_RW_SHIFT)) & SYSPLL_TDDR_SYSBYPASS_SOC_CTRL_THREE_RW_REG_REG_SYSBYPASS_SOC_CTRL_THREE_RW_MASK)
/*! @} */

/*! @name TDDR_CTRL_ONE_REG - TDDR_CTRL_ONE_REG */
/*! @{ */

#define SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD0_MASK (0xFU)
#define SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD0_SHIFT (0U)
/*! RSVD0 - Reserved. (Do not change) */
#define SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD0(x)   (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD0_SHIFT)) & SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD0_MASK)

#define SYSPLL_TDDR_TDDR_CTRL_ONE_REG_REG_TDDR_CTRL_ONE_MASK (0x30U)
#define SYSPLL_TDDR_TDDR_CTRL_ONE_REG_REG_TDDR_CTRL_ONE_SHIFT (4U)
/*! REG_TDDR_CTRL_ONE - Adjust lock detector delay. */
#define SYSPLL_TDDR_TDDR_CTRL_ONE_REG_REG_TDDR_CTRL_ONE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_TDDR_CTRL_ONE_REG_REG_TDDR_CTRL_ONE_SHIFT)) & SYSPLL_TDDR_TDDR_CTRL_ONE_REG_REG_TDDR_CTRL_ONE_MASK)

#define SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD1_MASK (0xC0U)
#define SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD1_SHIFT (6U)
/*! RSVD1 - Reserved. (Do not change) */
#define SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD1(x)   (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD1_SHIFT)) & SYSPLL_TDDR_TDDR_CTRL_ONE_REG_RSVD1_MASK)
/*! @} */

/*! @name TDDR_CTRL_TWO_REG - TDDR_CTRL_TWO_REG */
/*! @{ */

#define SYSPLL_TDDR_TDDR_CTRL_TWO_REG_REG_TDDR_CTRL_TWO_MASK (0xFFU)
#define SYSPLL_TDDR_TDDR_CTRL_TWO_REG_REG_TDDR_CTRL_TWO_SHIFT (0U)
/*! REG_TDDR_CTRL_TWO - Reserved. (Do not change) */
#define SYSPLL_TDDR_TDDR_CTRL_TWO_REG_REG_TDDR_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_TDDR_CTRL_TWO_REG_REG_TDDR_CTRL_TWO_SHIFT)) & SYSPLL_TDDR_TDDR_CTRL_TWO_REG_REG_TDDR_CTRL_TWO_MASK)
/*! @} */

/*! @name TDDR_CTRL_THREE_REG - TDDR_CTRL_THREE_REG */
/*! @{ */

#define SYSPLL_TDDR_TDDR_CTRL_THREE_REG_REG_TDDR_CTRL_THREE_MASK (0xFFU)
#define SYSPLL_TDDR_TDDR_CTRL_THREE_REG_REG_TDDR_CTRL_THREE_SHIFT (0U)
/*! REG_TDDR_CTRL_THREE - Reserved. (Do not change) */
#define SYSPLL_TDDR_TDDR_CTRL_THREE_REG_REG_TDDR_CTRL_THREE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_TDDR_CTRL_THREE_REG_REG_TDDR_CTRL_THREE_SHIFT)) & SYSPLL_TDDR_TDDR_CTRL_THREE_REG_REG_TDDR_CTRL_THREE_MASK)
/*! @} */

/*! @name TDDR_CTRL_FOUR_REG - TDDR_CTRL_FOUR_REG */
/*! @{ */

#define SYSPLL_TDDR_TDDR_CTRL_FOUR_REG_REG_TDDR_CTRL_FOUR_MASK (0xFFU)
#define SYSPLL_TDDR_TDDR_CTRL_FOUR_REG_REG_TDDR_CTRL_FOUR_SHIFT (0U)
/*! REG_TDDR_CTRL_FOUR - Reserved. (Do not change) */
#define SYSPLL_TDDR_TDDR_CTRL_FOUR_REG_REG_TDDR_CTRL_FOUR(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_TDDR_CTRL_FOUR_REG_REG_TDDR_CTRL_FOUR_SHIFT)) & SYSPLL_TDDR_TDDR_CTRL_FOUR_REG_REG_TDDR_CTRL_FOUR_MASK)
/*! @} */

/*! @name TDDR_CTRL_FIVE_REG - TDDR_CTRL_FIVE_REG */
/*! @{ */

#define SYSPLL_TDDR_TDDR_CTRL_FIVE_REG_REG_TDDR_CTRL_FIVE_MASK (0xFFU)
#define SYSPLL_TDDR_TDDR_CTRL_FIVE_REG_REG_TDDR_CTRL_FIVE_SHIFT (0U)
/*! REG_TDDR_CTRL_FIVE - Reserved. (Do not change) */
#define SYSPLL_TDDR_TDDR_CTRL_FIVE_REG_REG_TDDR_CTRL_FIVE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_TDDR_CTRL_FIVE_REG_REG_TDDR_CTRL_FIVE_SHIFT)) & SYSPLL_TDDR_TDDR_CTRL_FIVE_REG_REG_TDDR_CTRL_FIVE_MASK)
/*! @} */

/*! @name TDDR_CTRL_SIX_REG - TDDR_CTRL_SIX_REG */
/*! @{ */

#define SYSPLL_TDDR_TDDR_CTRL_SIX_REG_REG_TDDR_CTRL_SIX_MASK (0xFFU)
#define SYSPLL_TDDR_TDDR_CTRL_SIX_REG_REG_TDDR_CTRL_SIX_SHIFT (0U)
/*! REG_TDDR_CTRL_SIX - Reserved. (Do not change) */
#define SYSPLL_TDDR_TDDR_CTRL_SIX_REG_REG_TDDR_CTRL_SIX(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_TDDR_CTRL_SIX_REG_REG_TDDR_CTRL_SIX_SHIFT)) & SYSPLL_TDDR_TDDR_CTRL_SIX_REG_REG_TDDR_CTRL_SIX_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_ONE_REG - CLKTREE_CTRL_ONE_REG */
/*! @{ */

#define SYSPLL_TDDR_CLKTREE_CTRL_ONE_REG_REG_CLKTREE_CTRL_ONE_MASK (0xFFU)
#define SYSPLL_TDDR_CLKTREE_CTRL_ONE_REG_REG_CLKTREE_CTRL_ONE_SHIFT (0U)
/*! REG_CLKTREE_CTRL_ONE - Reserved. (Do not change) */
#define SYSPLL_TDDR_CLKTREE_CTRL_ONE_REG_REG_CLKTREE_CTRL_ONE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_CLKTREE_CTRL_ONE_REG_REG_CLKTREE_CTRL_ONE_SHIFT)) & SYSPLL_TDDR_CLKTREE_CTRL_ONE_REG_REG_CLKTREE_CTRL_ONE_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_TWO_REG - CLKTREE_CTRL_TWO_REG */
/*! @{ */

#define SYSPLL_TDDR_CLKTREE_CTRL_TWO_REG_REG_CLKTREE_CTRL_TWO_MASK (0xFFU)
#define SYSPLL_TDDR_CLKTREE_CTRL_TWO_REG_REG_CLKTREE_CTRL_TWO_SHIFT (0U)
/*! REG_CLKTREE_CTRL_TWO - Reserved. (Do not change) */
#define SYSPLL_TDDR_CLKTREE_CTRL_TWO_REG_REG_CLKTREE_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_CLKTREE_CTRL_TWO_REG_REG_CLKTREE_CTRL_TWO_SHIFT)) & SYSPLL_TDDR_CLKTREE_CTRL_TWO_REG_REG_CLKTREE_CTRL_TWO_MASK)
/*! @} */

/*! @name GPIO_CTRL_REG - GPIO_CTRL_REG */
/*! @{ */

#define SYSPLL_TDDR_GPIO_CTRL_REG_REG_GPIO_CTRL_MASK (0xFFU)
#define SYSPLL_TDDR_GPIO_CTRL_REG_REG_GPIO_CTRL_SHIFT (0U)
/*! REG_GPIO_CTRL - Reserved. (Do not change) */
#define SYSPLL_TDDR_GPIO_CTRL_REG_REG_GPIO_CTRL(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_GPIO_CTRL_REG_REG_GPIO_CTRL_SHIFT)) & SYSPLL_TDDR_GPIO_CTRL_REG_REG_GPIO_CTRL_MASK)
/*! @} */

/*! @name ATEST_CTRL_REG - ATEST_CTRL_REG */
/*! @{ */

#define SYSPLL_TDDR_ATEST_CTRL_REG_REG_ATEST_CTRL_MASK (0xFFU)
#define SYSPLL_TDDR_ATEST_CTRL_REG_REG_ATEST_CTRL_SHIFT (0U)
/*! REG_ATEST_CTRL - Reserved. (Do not change) */
#define SYSPLL_TDDR_ATEST_CTRL_REG_REG_ATEST_CTRL(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_ATEST_CTRL_REG_REG_ATEST_CTRL_SHIFT)) & SYSPLL_TDDR_ATEST_CTRL_REG_REG_ATEST_CTRL_MASK)
/*! @} */

/*! @name RESERVED_LO_REG - RESERVED_LO_REG */
/*! @{ */

#define SYSPLL_TDDR_RESERVED_LO_REG_REG_RESERVED_LO_MASK (0xFFU)
#define SYSPLL_TDDR_RESERVED_LO_REG_REG_RESERVED_LO_SHIFT (0U)
/*! REG_RESERVED_LO - Reserved. (Do not change) */
#define SYSPLL_TDDR_RESERVED_LO_REG_REG_RESERVED_LO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_RESERVED_LO_REG_REG_RESERVED_LO_SHIFT)) & SYSPLL_TDDR_RESERVED_LO_REG_REG_RESERVED_LO_MASK)
/*! @} */

/*! @name RESERVED_HI_REG - RESERVED_HI_REG */
/*! @{ */

#define SYSPLL_TDDR_RESERVED_HI_REG_REG_RESERVED_HI_MASK (0xFFU)
#define SYSPLL_TDDR_RESERVED_HI_REG_REG_RESERVED_HI_SHIFT (0U)
/*! REG_RESERVED_HI - Reserved. (Do not change) */
#define SYSPLL_TDDR_RESERVED_HI_REG_REG_RESERVED_HI(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TDDR_RESERVED_HI_REG_REG_RESERVED_HI_SHIFT)) & SYSPLL_TDDR_RESERVED_HI_REG_REG_RESERVED_HI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSPLL_TDDR_Register_Masks */


/*!
 * @}
 */ /* end of group SYSPLL_TDDR_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSPLL_TDDR_H_ */

