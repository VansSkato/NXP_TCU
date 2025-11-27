/**
 * @file    IoHwAb_gpio.h
 * @brief   GPIO pin definitions and initialization APIs for the
 *          Transmission Control Module (TCM).
 *
 * This header belongs to the IoHwAb (I/O Hardware Abstraction) layer.
 * It exposes:
 *  - Symbolic pin definitions (no magic numbers in the .c file)
 *  - Initialization functions for all GPIOs used by the TCM
 *
 * The GPIOs covered here include:
 *  - Brake pedal input
 *  - Gear lever position inputs (P, R, N, D, 1st, 2nd)
 *  - Shift solenoids (A, B, C, D, E)
 *  - Shift-lock solenoid
 *
 * Each pin macro represents the **pin number** for the corresponding PORT/GPIO
 * instance specified in app.h or board.h.
 */

#ifndef _IOHWAB_GPIO_H_
#define _IOHWAB_GPIO_H_


/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "fsl_port.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "app.h"
#include "board.h"
#include "fsl_common.h"
#include "pin_mux.h"


/* **********************************************************************
 * Defines
 * *********************************************************************/

/**
 * @name Brake Pedal Input
 * @{
 */
#define BREAK_PEDAL_PIN	4U			/**< Brake pedal GPIO pin */
/** @} */


/**
 * @name Gear Position Inputs
 * @{
 */
#define PARKING_PIN		(9U)			/**< Gear position: Parking  */
#define REVERSE_PIN 	(12U)			/**< Gear position: Reverse  */
#define NEUTRAL_PIN		(5U)			/**< Gear position: Neutral  */
#define DRIVE_PIN		(0U)			/**< Gear position: Drive    */
#define FIRST_PIN		(23U)			/**< Gear position: 1st gear */
#define SECOND_PIN		(13U)			/**< Gear position: 2nd gear */
/** @} */

/**
 * @name Shift Solenoid Outputs
 * @{
 */
#define SOLENOID_A_PIN      (17U)  	/**< Solenoid A */
#define SOLENOID_B_PIN      (22U)  	/**< Solenoid B */
#define SOLENOID_C_PIN      (15U)  	/**< Solenoid C */
#define SOLENOID_D_PIN      (14U)   	/**< Solenoid D */
#define SOLENOID_E_PIN      (4U)  	/**< Solenoid E */
/** @} */

/**
 * @name Shift-Lock Solenoid Output
 * @{
 */
#define LOCK_SOLENOID		(8U)	/**< Shift-lock solenoid */
/** @} */


/* **********************************************************************
 * API Prototypes
 * *********************************************************************/

/**
 * @brief Initializes the GPIO for the brake pedal input.
 */
void Init_Pin_BreakPedal(void);

/**
 * @brief Initializes all GPIOs used to detect mechanical gear position.
 */
void Init_Pin_GearPossition(void);

/**
 * @brief Initializes all GPIOs that drive the shift solenoids (A–E).
 */
void Init_Pin_ShiftSolenoids(void);

/**
 * @brief Initializes the GPIO that controls the shift-lock solenoid.
 */
void Init_Pin_ShiftLockSolenoid(void);


#endif /* _IOHWAB_GPIO_H_ */
