/*
 * set_signals.c
 *
 *  Created on: Nov 11, 2025
 *      Author: bruno
 */

#include "set_signals.h"

void Set_g_CAN_EngineRPM(uint16 RPMS)
{
	g_CAN_EngineRPM = RPMS;
}
void Set_g_CAN_ThrottlePosition(uint8 TrtPosition)
{
	g_CAN_ThrottlePosition = TrtPosition;
}
void Set_g_CAN_EngineTorque(sint16 Torque)
{
	g_CAN_EngineTorque = Torque;
}
void Set_g_CAN_VehicleSpeed(uint8 VhSpeed)
{
	g_CAN_VehicleSpeed = VhSpeed;
}
void Set_g_CAN_DriveMode(uint8 Mode)
{
	g_CAN_DriveMode = Mode;
}
void Set_g_CAN_IgnitionStatus(uint8 IgnStatus)
{
	g_CAN_IgnitionStatus = IgnStatus;
}
void Set_g_HW_LeverPosition(uint8 LvrPosition)
{
	g_HW_LeverPosition = LvrPosition;
}
void Set_g_HW_BrakeSW(uint8 Brake)
{
	g_HW_BrakeSW = Brake;
}
void Set_g_HW_InputSpeed(uint16 InSpeed)
{
	g_HW_InputSpeed = InSpeed;
}
void Set_g_HW_OutputSpeed(uint16 OutSpeed)
{
	g_HW_OutputSpeed = OutSpeed;
}
void Set_g_HW_TransmissionTEMP(sint8 Temperature)
{
	g_HW_TransmissionTEMP = Temperature;
}
void Set_g_OUT_ShiftSolenoid(uint8 ShiftSol)
{
	g_OUT_ShiftSolenoid = ShiftSol;
}
void Set_g_OUT_LinePressure_Control(uint8 Pressure)
{
	g_OUT_LinePressure_Control = Pressure;
}
void Set_g_OUT_TCC_ControlSolenoid(uint8 CntrlSol)
{
	g_OUT_TCC_ControlSolenoid = CntrlSol;
}
void Set_g_OUT_ShiftLock_Solenoid(uint8 ShiftLock)
{
	g_OUT_ShiftLock_Solenoid = ShiftLock;
}
void Set_g_OUT_TorqueReduction_Request(uint8 TrqReduction)
{
	g_OUT_TorqueReduction_Request = TrqReduction;
}
void Set_g_OUT_CurrentGear(uint8 Gear)
{
	g_OUT_CurrentGear = Gear;
}
