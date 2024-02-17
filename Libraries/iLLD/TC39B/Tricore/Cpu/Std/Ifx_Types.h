/**
 * \file Ifx_Types.h
 * \brief This files defines all types used by the IFX HAL and libraries
 *
 * \version iLLD_1_0_1_17_0_1
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef IFX_TYPES_H
#define IFX_TYPES_H 1

/******************************************************************************/
#include "Tricore/Compilers/Compilers.h" /* mapping compiler specific keywords */
#include "Platform_Types.h"

/*******************************************************************************
**                      Global Data Types                                     **
**                      (Types not defined by AUTOSAR)                        **
*******************************************************************************/
typedef const char        *pchar;                           /**< \brief const char pointer                               */
typedef void              *pvoid;                           /**< \brief void pointer                                     */
typedef volatile void     *vvoid;                           /**< \brief volatile void pointer                            */
typedef void              (*voidfuncvoid) (void);           /**< \brief void pointer which takes void argument           */

typedef struct
{
    float32 real;               /**< \brief Real part */
    float32 imag;               /**< \brief Imaginary part */
} cfloat32;

typedef struct
{
    sint32 real;				/**< \brief Real part */
    sint32 imag;				/**< \brief Imaginary part */
} csint32;

typedef struct
{
    sint16 real;				/**< \brief Real part */
    sint16 imag;				/**< \brief Imaginary part */
} csint16;

typedef sint64             Ifx_TickTime;    /**< \brief Time in ticks */
#define TIME_INFINITE ((Ifx_TickTime)0x7FFFFFFFFFFFFFFFLL)
#define TIME_NULL     ((Ifx_TickTime)0x0000000000000000LL)

#define IFX_ONES          (0xFFFFFFFFFFFFFFFFU)
#define IFX_ZEROS         (0x0000000000000000U)


#if CFG_LONG_SIZE_T
#define IFX_SIZET_MAX (0x7FFFFFFFL)
typedef sint32 Ifx_SizeT;                       /**< \brief Type used for data stream size */
#else
#define IFX_SIZET_MAX (0x7FFF)
typedef sint16 Ifx_SizeT;                       /**< \brief Type used for data stream size */
#endif

/** \brief Circular buffer definition. */
typedef struct
{
    void  *base;                   /**< \brief buffer base address */
    uint16 index;                  /**< \brief buffer current index */
    uint16 length;                 /**< \brief buffer length*/
} Ifx_CircularBuffer;

typedef uint16 Ifx_Priority;       /**< \brief Used in interrupt service priorities */
typedef uint32 Ifx_TimerValue;     /**< \brief Used in timer values */
typedef sint32 Ifx_SignedTimerVal; /**< \brief Used in signed timer values */

typedef pvoid  Ifx_AddressValue;   /**< \brief Used in address values */

typedef struct
{
    uint16 priority;
    uint16 provider;
} Ifx_IsrSetting;

/** \brief Signal active state definition. */
typedef enum
{
    Ifx_ActiveState_low  = 0,       /**< \brief The signal is low active */
    Ifx_ActiveState_high = 1        /**< \brief The signal is high active */
} Ifx_ActiveState;

typedef enum
{
    Ifx_ParityMode_even = 0,
    Ifx_ParityMode_odd  = 1
} Ifx_ParityMode;

/** \brief input multiplexer definition used in PinMaps
 */
typedef enum
{
    Ifx_RxSel_a,
    Ifx_RxSel_b,
    Ifx_RxSel_c,
    Ifx_RxSel_d,
    Ifx_RxSel_e,
    Ifx_RxSel_f,
    Ifx_RxSel_g,
    Ifx_RxSel_h
} Ifx_RxSel;

/** \brief Module address and index map */
typedef struct
{
    volatile void *module;      /**< \brief Module address */
    sint32         index;       /**< \brief Module index */
} IfxModule_IndexMap;

typedef struct
{
    Ifx_TickTime timestamp;
    uint8        data;
}Ifx_DataBufferMode_TimeStampSingle;

/*
 * typedef struct
 * {
 *  Ifx_TickTime timestamp;
 *  uint8 count[1];     // Number of valid data
 *  uint8 data[7];
 * }Ifx_DataBufferMode_TimeStampBurst;
 */

typedef enum
{
    Ifx_DataBufferMode_normal = 0,           /**< \brief normal mode, each received byte is moved to the rx fifo */
    Ifx_DataBufferMode_timeStampSingle,      /**< \brief Single byte type stamp mode. The rx fifo is filled in with Ifx_DataBufferMode_TimeStampSingle items. */
//    Ifx_DataBufferMode_timeStameBurst      /**< \brief Burst byte type stamp mode. The rx fifo is filled in with Ifx_DataBufferMode_TimeStampBurst items. */
}Ifx_DataBufferMode;

/**
 * Defines the PWM modes
 *
 * The 1st member shall start with value 0, and the next members value shall be the previous member +1
 * pwmMode_off shall be the member with the higher index
 * \note enum order and values should not be modified, except Ifx_Pwm_Mode_init and Ifx_Pwm_Mode_count
 */
typedef enum
{
    Ifx_Pwm_Mode_centerAligned         = 0, /**< \brief Center aligned mode */
    Ifx_Pwm_Mode_centerAlignedInverted = 1, /**< \brief Center aligned inverted aligned mode */
    Ifx_Pwm_Mode_leftAligned           = 2, /**< \brief Left aligned mode. The PWM period starts with a rising edge */
    Ifx_Pwm_Mode_rightAligned          = 3, /**< \brief Right aligned mode. The PWM period starts with a falling edge*/
    Ifx_Pwm_Mode_off                   = 4, /**< \brief All switch open */
    Ifx_Pwm_Mode_init                  = 5, /**< \brief Initialisation mode, do not use at run time */
    Ifx_Pwm_Mode_count                      /**< \brief Number of defined modes */
} Ifx_Pwm_Mode;

#ifdef __DCC__
#include "Ifx_TypesDcc.h"

#elif defined(__TASKING__)
#include "Ifx_TypesTasking.h"

#elif defined(__HIGHTEC__)
#include "Ifx_TypesGnuc.h"

#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#include "Ifx_TypesGcc.h"

#elif defined(__ghs__)
#include "Ifx_TypesGhs.h"

#elif defined(__MSVC__)
#include "Ifx_TypesMsvc.h"
#else
#error Unsupported compiler.
#endif


typedef struct
{
    fract real;				/**< \brief Real part */
    fract imag;				/**< \brief Imaginary part */
} cfract;

typedef struct
{
    sfract real;				/**< \brief Real part */
    sfract imag;				/**< \brief Imaginary part */
} csfract;

#define IFX_PI                  (3.1415926535897932384626433832795f)
#define IFX_TWO_OVER_PI         (2.0 / IFX_PI)
#define IFX_ONE_OVER_TWO_PI     (1.0f / (2.0f * IFX_PI))
#define IFX_ONE_OVER_SQRT_THREE (0.57735026918962576450914878050196f)
#define IFX_SQRT_TWO            (1.4142135623730950488016887242097f)
#define IFX_SQRT_THREE          (1.7320508075688772935274463415059f)
#define IFX_UNUSED_PARAMETER(x) if(x){}             /**< \brief Added to handle warning resulting from cases where one/multiple function argument(s) is/are not used(but function signature maintained for legacy purposes). Another use case being usage of intrinsics wherein the compiler ignores it and copy pastes the statements using intrinsics directly to the object file and hence usage of arguments isn't visible to it.(eg: __mfcr() etc) */ 

#endif /* IFX_TYPES_H */
