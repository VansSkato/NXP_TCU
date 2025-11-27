/*
 * RTE_write.c
 *
 *  Created on: Nov 22, 2025
 *      Author: bruno
 */
#include "RTE_write.h"

void Rte_write_g_HW_LeverPosition(uint8 LvrPosition)
{
	Set_g_HW_LeverPosition(LvrPosition);
}

void Rte_write_g_CAN_EngineRPM(uint16 RPMS)
{
    Set_g_CAN_EngineRPM(RPMS);
}

void Rte_write_g_CAN_ThrottlePosition(uint8 TrtPosition)
{
	Set_g_CAN_ThrottlePosition(TrtPosition);
}
void Rte_write_g_CAN_EngineTorque(sint16 Torque)
{
	Set_g_CAN_EngineTorque(Torque);
}
void Rte_write_g_CAN_VehicleSpeed(sint16 VhSpeed)
{
	Set_g_CAN_VehicleSpeed(VhSpeed);
}
void Rte_write_g_CAN_DriveMode(uint8 Mode)
{
	Set_g_CAN_DriveMode(Mode);
}
void Rte_write_g_CAN_IgnitionStatus(uint8 IgnStatus)
{
	Set_g_CAN_IgnitionStatus(IgnStatus);
}
//void Rte_write_g_HW_LeverPosition(uint8 LvrPosition)
//{
//	set_g_HW_LeverPosition(LvrPosition);
//}
void Rte_write_g_HW_BrakeSW(uint8 Brake)
{
	Set_g_HW_BrakeSW(Brake);
}
void Rte_write_g_HW_InputSpeed(uint16 InSpeed)
{
	Set_g_HW_InputSpeed(InSpeed);
}
void Rte_write_g_HW_OutputSpeed(uint16 OutSpeed)
{
	Set_g_HW_OutputSpeed(OutSpeed);
}
void Rte_write_g_HW_TransmissionTEMP(sint8 Temperature)
{
	Set_g_HW_TransmissionTEMP(Temperature);
}
void Rte_write_g_OUT_ShiftSolenoid(uint8 ShiftSol)
{
	Set_g_OUT_ShiftSolenoid(ShiftSol);
}
void Rte_write_g_OUT_LinePressure_Control(uint8 Pressure)
{
	Set_g_OUT_LinePressure_Control(Pressure);
}
void Rte_write_g_OUT_TCC_ControlSolenoid(uint8 CntrlSol)
{
	Set_g_OUT_TCC_ControlSolenoid(CntrlSol);
}
void Rte_write_g_OUT_ShiftLock_Solenoid(uint8 ShiftLock)
{
	Set_g_OUT_ShiftLock_Solenoid(ShiftLock);
}
void Rte_write_g_OUT_TorqueReduction_Request(uint8 TrqReduction)
{
	Set_g_OUT_TorqueReduction_Request(TrqReduction);
}
void Rte_write_g_OUT_CurrentGear(uint8 Gear)
{
	Set_g_OUT_CurrentGear(Gear);
}
