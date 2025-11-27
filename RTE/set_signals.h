/*
 * set_signals.h
 *
 *  Created on: Nov 11, 2025
 *      Author: bruno
 */

#ifndef RTE_SET_SIGNALS_H_
#define RTE_SET_SIGNALS_H_

#include "Platform_Types.h"
#include "global_signals.h"

//Inputs
void Set_g_CAN_EngineRPM(uint16 RPMS);
void Set_g_CAN_ThrottlePosition(uint8 TrtPosition);
void Set_g_CAN_EngineTorque(sint16 Torque);
void Set_g_CAN_VehicleSpeed(uint8 VhSpeed);
void Set_g_CAN_DriveMode(uint8 Mode);
void Set_g_CAN_IgnitionStatus(uint8 IgnStatus);
void Set_g_HW_LeverPosition(uint8 LvrPosition);
void Set_g_HW_BrakeSW(uint8 Brake);
void Set_g_HW_InputSpeed(uint16 InSpeed);
void Set_g_HW_OutputSpeed(uint16 OutSpeed);
void Set_g_HW_TransmissionTEMP(sint8 Temperature);

//Outputs
void Set_g_OUT_ShiftSolenoid(uint8 ShiftSol);
void Set_g_OUT_LinePressure_Control(uint8 Pressure);
void Set_g_OUT_TCC_ControlSolenoid(uint8 CntrlSol);
void Set_g_OUT_ShiftLock_Solenoid(uint8 ShiftLock);
void Set_g_OUT_TorqueReduction_Request(uint8 TrqReduction);
void Set_g_OUT_CurrentGear(uint8 Gear);

#endif /* RTE_SET_SIGNALS_H_ */
