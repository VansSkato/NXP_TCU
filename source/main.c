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
#include "Rte_os.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"
#include "CAN_signals_simulations.h"

#include "IoHwAb_gpio.h"
#include "IoHwAb_adc.h"
#include "IoHwAb_pwm.h"
#include "MCU.h"
#include "Chart.h"
#include "proyecto_final2.h"
#include "proyecto_final2_types.h"
#include "proyecto_final2_private.h"


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

    Rte_task_Init();
}
//
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
    	proyecto_final2_step();
    	delay();



    }
}
