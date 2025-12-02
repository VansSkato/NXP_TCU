/*
 * RTE_os.c
 *
 *  Created on: Nov 12, 2025
 *      Author: Emilio Diaz
 */
#include "Rte_os.h"


#include "IoHwAb.h"
#include "IoHwAb_gpio.h"
#include "IoHwAb_adc.h"
#include "IoHwAb_pwm.h"
#include "MCU.h"
#include "Rte_read.h"
#include "MCU.h"
#include "tcc_control.h"
#include "proyecto_final2.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void Rte_task_Init();
static void Rte_task(void *pvParameters);
static void Rte_Task_logic(void *pvParameters);
static void Rte_task_Comm_Tx(void *pvParameters);
static void Rte_task_Comm_Rx(void *pvParameters);
static void Rte_task_swc(void *pvParameters);
/*******************************************************************************
 * defines
 ******************************************************************************/
#define Rte_task_PRIORITY (configMAX_PRIORITIES - 1)
#define Rte_task_Comm_TxPRIORITY (configMAX_PRIORITIES - 1)
#define Rte_task_Comm_RxPRIORITY (configMAX_PRIORITIES - 1)
#define Rte_task_swcPRIORITY (configMAX_PRIORITIES - 1)
#define Rte_Task_logicPRIORITY (configMAX_PRIORITIES - 1)
/*******************************************************************************
 * Code
 ******************************************************************************/


void delay1(void)//checar
{
    volatile uint32_t i = 0;
    for (i = 0; i < 800000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}


void Rte_task_Init()
{
	if (xTaskCreate(Rte_task, "Rte_task", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_PRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_task_Comm_Tx, "Rte_task_Comm_Tx", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_Comm_TxPRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_task_Comm_Rx, "Rte_task_Comm_Rx", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_Comm_RxPRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_task_swc, "Rte_task_swc", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_swcPRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_Task_logic, "Rte_Task_logic", configMINIMAL_STACK_SIZE + 100, NULL, Rte_Task_logicPRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }

    vTaskStartScheduler();
    for (;;)
        ;
}

//Probar modelos del Buen JF
static void Rte_task_Comm_Tx(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
    	//van primero las tareas
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
static void Rte_task_Comm_Rx(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
    	vTaskDelay(pdMS_TO_TICKS(100));
    }
}
static void Rte_task_swc(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
    	vTaskDelay(pdMS_TO_TICKS(100));
    }
}
static void Rte_Task_logic(void *pvParameters)//Probar modelos
{

	ValoresPWM valPwm;
    for (;;)
    {
    	Rte_read_g_HW_LeverPosition(&proyecto_final2_U.Gear_Lever_Position);
    	Rte_read_g_HW_BrakeSW(&proyecto_final2_U.Brake_Pedal_Switch);
    	Rte_read_g_CAN_DriveMode(&proyecto_final2_U.Driver_Mode_Selection);
    	Rte_read_g_CAN_IgnitionStatus(&proyecto_final2_U.Switch);
    	Rte_read_g_OUT_LinePressure_Control(&proyecto_final2_U.LINE_PRESSURE_PIN);



    	proyecto_final2_step();
    	//write
    	Rte_write_g_OUT_CurrentGear(proyecto_final2_Y.Current_Gear);
    	Rte_write_g_CAN_EngineRPM(proyecto_final2_B.value3);
    	Rte_write_g_OUT_ShiftLock_Solenoid(proyecto_final2_Y.value);

    	valPwm = control_solenoides_pwm(proyecto_final2_Y.Current_Gear,proyecto_final2_U.Driver_Mode_Selection,80);

    	vTaskDelay(pdMS_TO_TICKS(100));
    }
}


static void Rte_task(void *pvParameters)
{
	 for (;;)
	 {

		 //Init_IO_pins();
		// Update_IO_pins();

		 vTaskDelay(pdMS_TO_TICKS(100));
	 }

}
