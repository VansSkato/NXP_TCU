/**
 * @file    IoHwAb_pwm.h
 * @brief   PWM pin definitions and initialization APIs for TCM pressure control.
 *
 * This header belongs to the IoHwAb (I/O Hardware Abstraction) layer.
 * It exposes:
 *  - Symbolic pin definitions for PWM outputs
 *  - Board/application specific PWM configuration macros
 *  - Initialization API for PWM module
 *
 * PWM is used to control:
 *  - LINE_PRESSURE_PIN : Hydraulic line pressure control
 *  - TCC_CONTROL_PIN   : Torque Converter Clutch (TCC) control
 */

#ifndef _IOHWAB_PWM_H_
#define _IOHWAB_PWM_H_

/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"
#include "fsl_pwm.h"

/* **********************************************************************
 * Pin Definitions
 * *********************************************************************/
/**
 * @brief PWM pin used for line pressure control.
 *
 * This value represents the pin number within the corresponding PORT
 * instance configured in IoHwAb_pwm.c (actual PORTx is board-specific).
 */
#define LINE_PRESSURE_PIN	(6U)

/**
 * @brief PWM pin used for TCC (Torque Converter Clutch) control.
 */
#define TCC_CONTROL_PIN		(7U)

/* **********************************************************************
 * PWM Hardware Configuration Macros
 * *********************************************************************/
/**
 * @brief Base address of the PWM peripheral used by this module.
 *
 * Must match the instance used in IoHwAb_pwm.c (e.g. PWM1).
 */
#define BOARD_PWM_BASEADDR        PWM1

/**
 * @brief Source clock for the PWM module.
 *
 * Typically the bus clock or specific PWM clock, depending on the MCU.
 */
#define PWM_SRC_CLK_FREQ          (CLOCK_GetFreq(kCLOCK_BusClk))

/**
 * @brief Fault level configuration for PWM inputs.
 *
 * When true, a high level on the fault input is considered a fault condition.
 */
#define DEMO_PWM_FAULT_LEVEL      (true)

/**
 * @brief Default PWM switching frequency in Hertz.
 */
#define APP_DEFAULT_PWM_FREQUENCY (10000UL)

/**
 * @brief Helper macro to build the fault disable map mask.
 *
 * In this implementation it is simply the identity of the mask, but the macro
 * is kept for clarity and easy adaptation (e.g. if mapping logic changes).
 */
#define DEMO_PWM_DISABLE_MAP_OP(mask)  (mask)

/* **********************************************************************
 * API Prototypes
 * *********************************************************************/
static void PWM_DRV_Init3PhPwm(void);
void Init_Pin_PWM(void);

#endif /* _IOHWAB_PWM_H_ */
