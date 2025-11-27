/*
 * RTE_read.c
 *
 *  Created on: Nov 20, 2025
 *      Author: bruno
 */

#include "RTE_read.h"


void Rte_read_g_HW_LeverPosition(uint8 *LvrPosition)
{
//	*LvrPosition = Get_g_HW_LvrPosition();
}
void Rte_read_g_CAN_EngineRPM(uint16 *RPMS)
{
	*RPMS = Get_g_CAN_EngineRPM();
}
void Rte_read_g_CAN_ThrottlePosition(uint8 *TrtPosition)
{
	*TrtPosition = Get_g_CAN_ThrottlePosition();
}
void Rte_read_g_CAN_EngineTorque(sint16 *Torque)
{
	*Torque = Get_g_CAN_EngineTorque();
}
void Rte_read_g_CAN_VehicleSpeed(sint16 *VhSpeed)
{
	*VhSpeed = Get_g_CAN_VehicleSpeed();
}
void Rte_read_g_CAN_DriveMode(uint8 *Mode)
{
	 *Mode = Get_g_CAN_DriveMode();
}
void Rte_read_g_CAN_IgnitionStatus(uint8 *IgnStatus)
{
	*IgnStatus = Get_g_CAN_IgnitionStatus();
}
//void Rte_read_g_HW_LeverPosition(uint8 *LvrPosition)
//{
//	*LvrPosition = Get_g_HW_LeverPosition();
//}
void Rte_read_g_HW_BrakeSW(uint8 *Brake)
{
	*Brake = Get_g_HW_BrakeSW();
}
void Rte_read_g_HW_InputSpeed(uint16 *InSpeed)
{
	 *InSpeed = Get_g_HW_InputSpeed();
}
void Rte_read_g_HW_OutputSpeed(uint16 *OutSpeed)
{
	*OutSpeed = Get_g_HW_OutputSpeed();
}
void Rte_read_g_HW_TransmissionTEMP(sint8 *Temperature)
{
	 *Temperature = Get_g_HW_TransmissionTEMP();
}
void Rte_read_g_OUT_ShiftSolenoid(uint8 *ShiftSol)
{
	 *ShiftSol = Get_g_OUT_ShiftSolenoid();
}
void Rte_read_g_OUT_LinePressure_Control(uint8 *Pressure)
{
	 *Pressure = Get_g_OUT_LinePressure_Control();
}
void Rte_read_g_OUT_TCC_ControlSolenoid(uint8 *CntrlSol)
{
	 *CntrlSol = Get_g_OUT_TCC_ControlSolenoid();
}
void Rte_read_g_OUT_ShiftLock_Solenoid(uint8 *ShiftLock)
{
	 *ShiftLock = Get_g_OUT_ShiftLock_Solenoid();
}
void Rte_read_g_OUT_TorqueReduction_Request(uint8 *TrqReduction)
{
	 *TrqReduction = Get_g_OUT_TorqueReduction_Request();
}
void Rte_read_g_OUT_CurrentGear(uint8 *Gear)
{
	 *Gear = Get_g_OUT_CurrentGear();
}
