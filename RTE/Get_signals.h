/*
 * Get_signals.h
 *
 *  Created on: Nov 11, 2025
 *      Author: bruno
 */

#ifndef RTE_GET_SIGNALS_H_
#define RTE_GET_SIGNALS_H_

#include "Platform_Types.h"
#include "global_signals.h"

//Inputs
uint16 Get_g_CAN_EngineRPM(void);
uint8 Get_g_CAN_ThrottlePosition(void);
sint16 Get_g_CAN_EngineTorque(void);
uint8 Get_g_CAN_VehicleSpeed(void);
uint8 Get_g_CAN_DriveMode(void);
uint8 Get_g_CAN_IgnitionStatus(void);
uint8 Get_g_HW_BrakeSW(void);
uint16 Get_g_HW_InputSpeed(void);
uint16 Get_g_HW_OutputSpeed(void);
sint8 Get_g_HW_TransmissionTEMP(void);

//Outputs
uint8 Get_g_OUT_ShiftSolenoid(void);
uint8 Get_g_OUT_LinePressure_Control(void);
uint8 Get_g_OUT_TCC_ControlSolenoid(void);
uint8 Get_g_OUT_ShiftLock_Solenoid(void);
uint8 Get_g_OUT_TorqueReduction_Request(void);
uint8 Get_g_OUT_CurrentGear(void);
#endif /* RTE_GET_SIGNALS_H_ */
