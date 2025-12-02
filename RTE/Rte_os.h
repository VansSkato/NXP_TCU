/*
 * Rte_os.h
 *
 *  Created on: 27 nov. 2025
 *      Author: bruno
 */

#ifndef RTE_OS_H_
#define RTE_OS_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

//Esto es del video de platon
//#include "tcu.h"

void Rte_task_Init();
static void Rte_task(void *pvParameters);
static void Rte_Task_logic(void *pvParameters);
static void Rte_task_Comm_Tx(void *pvParameters);
static void Rte_task_Comm_Rx(void *pvParameters);
static void Rte_task_swc(void *pvParameters);


#endif /* RTE_OS_H_ */
