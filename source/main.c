/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"


#include "IoHwAb_gpio.h"
#include "IoHwAb_adc.h"
#include "IoHwAb_pwm.h"
#include "MCU.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Task priorities. */
#define hello_task_PRIORITY (configMAX_PRIORITIES - 1)
#define TCM_LPADC0_BASE  	ADC0
#define TCM_LPADC1_BASE  	ADC1

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void hello_task(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */

void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 800000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

uint16_t value1 = 0;
uint32_t triggerMask1 = (1UL << 0);
uint16_t value2 = 0;
uint32_t triggerMask2 = (1UL << 1);
uint16_t value3 = 0;
uint32_t triggerMask3 = (1UL << 2);
uint32_t pwmVal = 4;
const uint32_t g_LpadcResultShift = 3U;

int main(void)
{
    /* Init board hardware. */
    BOARD_InitHardware();
    Init_Clock_Ports();

    if (xTaskCreate(hello_task, "Hello_task", configMINIMAL_STACK_SIZE + 100, NULL, hello_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    vTaskStartScheduler();
    for (;;)
        ;
}

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void hello_task(void *pvParameters)
{

    Init_Pin_BreakPedal();
    Init_Pin_GearPossition();
    Init_Pin_ShiftSolenoids();
    Init_Pin_ShiftLockSolenoid();
	Init_ADC_Pins();
    Init_Pin_PWM();

    lpadc_conv_result_t result1;
    lpadc_conv_result_t result2;
    lpadc_conv_result_t result3;


    for (;;)
    {
    	delay();

//        /* Delay at least 100 PWM periods. */
//        SDK_DelayAtLeastUs((1000000U / APP_DEFAULT_PWM_FREQUENCY) * 100, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
//
//        pwmVal = pwmVal + 4;
//
//        /* Reset the duty cycle percentage */
//        if (pwmVal > 100)
//        {
//            pwmVal = 4;
//        }
//
//        /* Update duty cycles for all 3 PWM signals */
//        PWM_UpdatePwmDutycycle(BOARD_PWM_BASEADDR, kPWM_Module_0, kPWM_PwmA, kPWM_SignedCenterAligned, pwmVal);
//        PWM_UpdatePwmDutycycle(BOARD_PWM_BASEADDR, kPWM_Module_1, kPWM_PwmA, kPWM_SignedCenterAligned, (pwmVal >> 1));
//        PWM_UpdatePwmDutycycle(BOARD_PWM_BASEADDR, kPWM_Module_2, kPWM_PwmA, kPWM_SignedCenterAligned, (pwmVal >> 2));
//
//        /* Set the load okay bit for all submodules to load registers from their buffer */
//        PWM_SetPwmLdok(BOARD_PWM_BASEADDR, kPWM_Control_Module_0 | kPWM_Control_Module_1 | kPWM_Control_Module_2, true);

/*PRUEBAS ADC*/
    	LPADC_DoSoftwareTrigger(TCM_LPADC0_BASE, triggerMask1);
    	LPADC_DoSoftwareTrigger(TCM_LPADC0_BASE, triggerMask2);
    	LPADC_DoSoftwareTrigger(TCM_LPADC1_BASE, triggerMask3);

    	while (!LPADC_GetConvResult(TCM_LPADC0_BASE, &result1, 0U))
    	{
    	}
    	value1 = ( (result1.convValue) >> g_LpadcResultShift  );

    	while (!LPADC_GetConvResult(TCM_LPADC0_BASE, &result2, 0U))
    	{
    	}
    	value2 = ( (result2.convValue) >> g_LpadcResultShift  );

    	while (!LPADC_GetConvResult(TCM_LPADC1_BASE, &result3, 0U))
    	{
    	}
    	value3 = ( (result3.convValue) >> g_LpadcResultShift  );

/*PRUEBAS GPIOS*/
//    	GPIO_PortToggle(GPIO5, 1u << LOCK_SOLENOID);
//   	value1 = GPIO_PinRead(GPIO1,  SECOND_PIN);

    }
}
