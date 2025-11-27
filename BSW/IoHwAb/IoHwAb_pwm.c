/*
 *@file    IoHwAb_pwm.c
 * @brief   PWM initialization for hydraulic pressure and TCC control.
 *
 * This module belongs to the IoHwAb (I/O Hardware Abstraction) layer and is
 * responsible for configuring:
 *  - PWM outputs for line pressure control
 *  - PWM outputs for torque converter clutch (TCC) control
 *
 * It configures:
 *  - Pin mux for PWM lines
 *  - PWM submodules 0, 1 and 2
 *  - Deadtime insertion
 *  - Fault inputs and fault-disable mapping
 *
 * All "magic numbers" for timing and duty cycle are wrapped in local macros.
 */

#include "IoHwAb_pwm.h"
#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_pwm.h"

/* **********************************************************************
 * Local configuration constants
 * *********************************************************************/

/**
 * @brief PWM deadtime in nanoseconds.
 * This value is converted to timer ticks using PWM_SRC_CLK_FREQ.
 */
#define IOHWAB_PWM_DEADTIME_NS           (650U)

/**
 * @brief Default duty cycle (in percent) for initial PWM setup.
 */
#define IOHWAB_PWMA_DEFAULT_DUTY_PERCENT  (80U)
#define IOHWAB_PWMB_DEFAULT_DUTY_PERCENT  (80U)

/**
 * @brief Number of channels that will be used for PWM
 */
#define IOHWAB_PWM_CHANELS				  (2U)

/* **********************************************************************
 * Static pin configuration
 * *********************************************************************/

/**
 * @brief Common PORT configuration for PWM output pins.
 *
 *  - No pull-up/down
 *  - Fast slew rate
 *  - No passive filter
 *  - Push-pull output
 *  - Low drive strength
 *  - Pin muxed to ALT5 (PWM function)
 *  - Input buffer disabled
 */
static const port_pin_config_t s_pwmPinConfig = {
    /* Internal pull-up/down resistor is disabled */
    kPORT_PullDisable,
    /* Low internal pull resistor value is selected (not used since pull disabled) */
    kPORT_LowPullResistor,
    /* Fast slew rate is configured */
    kPORT_FastSlewRate,
    /* Passive input filter is disabled */
    kPORT_PassiveFilterDisable,
    /* Open drain output is disabled */
    kPORT_OpenDrainDisable,
    /* Low drive strength is configured */
    kPORT_LowDriveStrength,
    /* Pin is configured as GPIO */
	kPORT_MuxAlt5,
    /* Digital input enabled */
    kPORT_InputBufferDisable,
    /* Digital input is not inverted */
    kPORT_InputNormal,
    /* Pin Control Register fields [15:0] are not locked */
    kPORT_UnlockRegister
};


/* **********************************************************************
 * Local functions
 * *********************************************************************/

/**
 * @brief Initializes 3-phase-like PWM on submodules 0, 1 and 2.
 *
 * This helper:
 *  - Computes deadtime from IOHWAB_PWM_DEADTIME_NS and PWM_SRC_CLK_FREQ.
 *  - Configures complementary channels A/B (where applicable) with
 *    IOHWAB_PWM_DEFAULT_DUTY_PERCENT.
 *  - Uses signed center-aligned mode and APP_DEFAULT_PWM_FREQUENCY.
 *
 * It assumes that:
 *  - BOARD_PWM_BASEADDR
 *  - PWM_SRC_CLK_FREQ
 *  - APP_DEFAULT_PWM_FREQUENCY
 * are defined in board- or application-specific headers.
 */
static void PWM_DRV_Init3PhPwm(void)
{
    uint16_t deadTimeVal;
    pwm_signal_param_t pwmSignal[IOHWAB_PWM_CHANELS];
    uint32_t pwmSourceClockInHz;
    uint32_t pwmFrequencyInHz = APP_DEFAULT_PWM_FREQUENCY;

    pwmSourceClockInHz = PWM_SRC_CLK_FREQ;

    /* Set deadtime count based on desired IOHWAB_PWM_DEADTIME_NS */
    deadTimeVal = ((uint64_t)pwmSourceClockInHz * IOHWAB_PWM_DEADTIME_NS) / 1000000000;

    /* Channel A configuration */
    pwmSignal[0].pwmChannel       = kPWM_PwmA;
    pwmSignal[0].level            = kPWM_HighTrue;
    pwmSignal[0].dutyCyclePercent = IOHWAB_PWMA_DEFAULT_DUTY_PERCENT;
    pwmSignal[0].deadtimeValue    = deadTimeVal;
    pwmSignal[0].faultState       = kPWM_PwmFaultState0;
    pwmSignal[0].pwmchannelenable = true;

    /* Channel B configuration */
    pwmSignal[1].pwmChannel = kPWM_PwmB;
    pwmSignal[1].level      = kPWM_HighTrue;
    /* Dutycycle field of PWM B does not matter as we are running in PWM A complementary mode */
    pwmSignal[1].dutyCyclePercent = IOHWAB_PWMB_DEFAULT_DUTY_PERCENT;
    pwmSignal[1].deadtimeValue    = deadTimeVal;
    pwmSignal[1].faultState       = kPWM_PwmFaultState0;
    pwmSignal[1].pwmchannelenable = true;

    /*********** PWMA_SM0 - configure both A and B channels ************/
    PWM_SetupPwm(BOARD_PWM_BASEADDR, kPWM_Module_0, pwmSignal, 2, kPWM_SignedCenterAligned, pwmFrequencyInHz,
                 pwmSourceClockInHz);

    /*********** PWMA_SM1 - configure only channel A ************/
    PWM_SetupPwm(BOARD_PWM_BASEADDR, kPWM_Module_1, pwmSignal, 1, kPWM_SignedCenterAligned, pwmFrequencyInHz,
                 pwmSourceClockInHz);

    /*********** PWMA_SM2 - configure only channel A ************/
    PWM_SetupPwm(BOARD_PWM_BASEADDR, kPWM_Module_2, pwmSignal, 1, kPWM_SignedCenterAligned, pwmFrequencyInHz,
                 pwmSourceClockInHz);
}

/* **********************************************************************
 * Global functions
 * *********************************************************************/

/**
 * @brief Initializes the PWM pins and PWM modules used for:
 *        - Line pressure control
 *        - TCC (Torque Converter Clutch) control
 *
 * This function performs:
 *  - Pin mux configuration for LINE_PRESSURE_PIN and TCC_CONTROL_PIN
 *  - PWM submodules 0/1/2 initialization
 *  - Fault configuration and disable mapping
 *  - 3-phase PWM setup and timer start
 *
 * All macros like LINE_PRESSURE_PIN, TCC_CONTROL_PIN, BOARD_PWM_BASEADDR,
 * DEMO_PWM_FAULT_LEVEL and DEMO_PWM_DISABLE_MAP_OP must be defined in
 * IoHwAb_pwm.h
 */
void Init_Pin_PWM(void)
{
	/* Configure pin muxing for PWM outputs */
	PORT_SetPinConfig(PORT2, LINE_PRESSURE_PIN, &s_pwmPinConfig);
	PORT_SetPinConfig(PORT2, TCC_CONTROL_PIN, &s_pwmPinConfig);

	/* PWM configuration structures */
    pwm_config_t pwmConfig;
    pwm_fault_param_t faultConfig;

    PWM_GetDefaultConfig(&pwmConfig);

    /* Use full cycle reload */
    pwmConfig.reloadLogic = kPWM_ReloadPwmFullCycle;
    /* PWM A & PWM B are configured as independent outputs in this setup */
    pwmConfig.pairOperation   = kPWM_Independent;
    pwmConfig.enableDebugMode = true;

	/* Initialize submodule 0 */
    if (PWM_Init(BOARD_PWM_BASEADDR, kPWM_Module_0, &pwmConfig) == kStatus_Fail)
    {
    	PRINTF("PWM initialization failed\n");

    }

    /* Initialize submodule 1,using submodule 0 clock  */
    pwmConfig.clockSource           = kPWM_Submodule0Clock;
    pwmConfig.prescale              = kPWM_Prescale_Divide_1;
    pwmConfig.initializationControl = kPWM_Initialize_MasterSync;
    if (PWM_Init(BOARD_PWM_BASEADDR, kPWM_Module_1, &pwmConfig) == kStatus_Fail)
    {
    	PRINTF("PWM initialization failed\n");
    }

    /* Initialize submodule 2 similarly to submodule 1 */
    if (PWM_Init(BOARD_PWM_BASEADDR, kPWM_Module_2, &pwmConfig) == kStatus_Fail)
    {
	   PRINTF("PWM initialization failed\n");
    }

    /*
     *   faultConfig.faultClearingMode     = kPWM_Automatic;
     *   faultConfig.faultLevel            = false;
     *   faultConfig.enableCombinationalPath = true;
     *   faultConfig.recoverMode           = kPWM_NoRecovery;
     */
    PWM_FaultDefaultConfig(&faultConfig);

    /* Override fault level from demo/application macro */
    faultConfig.faultLevel = DEMO_PWM_FAULT_LEVEL;

    /* Configure fault inputs for all fault channels */
    PWM_SetupFaults(BOARD_PWM_BASEADDR, kPWM_Fault_0, &faultConfig);
    PWM_SetupFaults(BOARD_PWM_BASEADDR, kPWM_Fault_1, &faultConfig);
    PWM_SetupFaults(BOARD_PWM_BASEADDR, kPWM_Fault_2, &faultConfig);
    PWM_SetupFaults(BOARD_PWM_BASEADDR, kPWM_Fault_3, &faultConfig);

    /* Set PWM fault disable mapping for submodules 0/1/2 (channel A) */
    PWM_SetupFaultDisableMap(BOARD_PWM_BASEADDR, kPWM_Module_0, kPWM_PwmA, kPWM_faultchannel_0,
							DEMO_PWM_DISABLE_MAP_OP(kPWM_FaultDisable_0 | kPWM_FaultDisable_1 | kPWM_FaultDisable_2 | kPWM_FaultDisable_3));
    PWM_SetupFaultDisableMap(BOARD_PWM_BASEADDR, kPWM_Module_1, kPWM_PwmA, kPWM_faultchannel_0,
							DEMO_PWM_DISABLE_MAP_OP(kPWM_FaultDisable_0 | kPWM_FaultDisable_1 | kPWM_FaultDisable_2 | kPWM_FaultDisable_3));
    PWM_SetupFaultDisableMap(BOARD_PWM_BASEADDR, kPWM_Module_2, kPWM_PwmA, kPWM_faultchannel_0,
							DEMO_PWM_DISABLE_MAP_OP(kPWM_FaultDisable_0 | kPWM_FaultDisable_1 | kPWM_FaultDisable_2 | kPWM_FaultDisable_3));

    /*
     * Recommend to call PWM_SetupPwm after PWM and fault configuration,
     * then enable load OK and start timers.
     */
    PWM_DRV_Init3PhPwm();

    /* Set the load OK bit for all submodules to load registers from their buffer */
    PWM_SetPwmLdok(BOARD_PWM_BASEADDR, kPWM_Control_Module_0 | kPWM_Control_Module_1 | kPWM_Control_Module_2, true);

    /* Start the PWM generation from Submodules 0, 1 and 2 */
    PWM_StartTimer(BOARD_PWM_BASEADDR, kPWM_Control_Module_0 | kPWM_Control_Module_1 | kPWM_Control_Module_2);
}
