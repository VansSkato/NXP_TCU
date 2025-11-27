/*
 * @file    IoHwAb_adc.h
 * @brief   LPADC pin, command and trigger definitions for TCM sensors.
 *
 * This header belongs to the IoHwAb (I/O Hardware Abstraction) layer.
 * It exposes:
 *  - Symbolic pin definitions for ADC inputs
 *  - LPADC base addresses, command IDs and trigger IDs
 *  - Common result mask/shift macros
 *  - Initialization and acquisition API for TCM sensors
 */

#ifndef _IOHWAB_ADC_H_
#define _IOHWAB_ADC_H_

/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_lpadc.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"
#include "clock_config.h"
#include "fsl_vref.h"
#include "fsl_spc.h"

/* **********************************************************************
 * ADC Pin Definitions
 * *********************************************************************/

/**
 * @brief ADC pin used for transmission fluid temperature sensor.
 *        (P0_22 = ADC0_A14)
 */
#define ADC_TEMPERATURE_PIN 	(22)

/**
 * @brief ADC pin used for output speed sensor.
 *        (P0_14 = ADC0_B14)
 */
#define ADC_OUTPUT_SPEED_PIN 	(14)

/**
 * @brief ADC pin used for turbine speed sensor.
 *        (P1_10 = ADC1_A10)
 *
 */
#define ADC_TURBINE_SPEED_PIN	(10U)

/* **********************************************************************
 * LPADC Base and Support Modules
 * *********************************************************************/

/**
 * @brief LPADC instances used by TCM.
 */
#define TCM_LPADC0_BASE  	ADC0
#define TCM_LPADC1_BASE		ADC1

/**
 * @brief VREF instance used to bias the LPADC.
 * @brief SPC instance used to enable analog modules (including VREF).
 */
#define DEMO_VREF_BASE 		VREF0
#define DEMO_SPC_BASE           SPC0

/**
 * @brief Clock divider for ADC functional clock.
 */
#define TCM_LPADC_CLOCK_DIVIDER  (1U)

/* **********************************************************************
 * Command IDs and Trigger IDs
 * *********************************************************************/

/* Command IDs (1–15 valid) for conversion commands */
#define TCM_LPADC_CMDID_OUTPUT   (1U)  /**< Output speed sensor command ID   */
#define TCM_LPADC_CMDID_FLUID    (2U)  /**< Fluid temperature command ID     */
#define TCM_LPADC_CMDID_TURBINE  (3U)  /**< Turbine speed sensor command ID  */

/* Software trigger indices (0–3 typically) */
#define TCM_LPADC_TRIG_OUTPUT    (0U)  /**< Software trigger index for output speed  */
#define TCM_LPADC_TRIG_FLUID     (1U)  /**< Software trigger index for fluid temp    */
#define TCM_LPADC_TRIG_TURBINE   (2U)  /**< Software trigger index for turbine speed */

/**
 * @brief LPADC channel numbers for each sensor.
 */
#define TCM_LPADC_CHANNEL_OUTPUT   (14U) /**< ADC0_B14 → output speed       */
#define TCM_LPADC_CHANNEL_FLUID    (14U) /**< ADC0_A14 → fluid temperature  */
#define TCM_LPADC_CHANNEL_TURBINE  (10U) /**< ADC1_A10 → turbine speed      */

/* **********************************************************************
 * API Prototypes
 * *********************************************************************/

/**
 * @brief Initializes ADC pins, clocks, VREF and LPADC configuration.
 */
void Init_ADC_Pins(void);

 /**
  * @brief Acquires the raw output speed sensor ADC sample and forwards it
  *        to the application layer (implementation TBD).
  */
void TCM_Read_OutputSpeedSensorRaw(void);

/**
 * @brief Acquires the raw transmission fluid temperature ADC sample and
 *        forwards it to the application layer (implementation TBD).
 */
void TCM_Read_FluidTempSensorRaw(void);

/**
 * @brief Acquires the raw turbine speed sensor ADC sample and forwards it
 *        to the application layer (implementation TBD).
 */
void TCM_Read_TurbineSpeedSensorRaw(void);

#endif /* _IOHWAB_ADC_H_ */
