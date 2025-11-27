/*
 * RTE_write.h
 *
 *  Created on: Nov 22, 2025
 *      Author: bruno
 */

#ifndef RTE_RTE_WRITE_H_
#define RTE_RTE_WRITE_H_

#include "Platform_Types.h"
#include "set_signals.h"

//Inputs
void Rte_write_g_CAN_EngineRPM(uint16 RPMS);
void Rte_write_g_CAN_ThrottlePosition(uint8 TrtPosition);
void Rte_write_g_CAN_EngineTorque(sint16 Torque);
void Rte_write_g_CAN_VehicleSpeed(sint16 VhSpeed);
void Rte_write_g_CAN_DriveMode(uint8 Mode);
void Rte_write_g_CAN_IgnitionStatus(uint8 IgnStatus);
void Rte_write_g_HW_LeverPosition(uint8 LvrPosition);
void Rte_write_g_HW_BrakeSW(uint8 Brake);
void Rte_write_g_HW_InputSpeed(uint16 InSpeed);
void Rte_write_g_HW_OutputSpeed(uint16 OutSpeed);
void Rte_write_g_HW_TransmissionTEMP(sint8 Temperature);

//Outputs
void Rte_write_g_OUT_ShiftSolenoid(uint8 ShiftSol);
void Rte_write_g_OUT_LinePressure_Control(uint8 Pressure);
void Rte_write_g_OUT_TCC_ControlSolenoid(uint8 CntrlSol);
void Rte_write_g_OUT_ShiftLock_Solenoid(uint8 ShiftLock);
void Rte_write_g_OUT_TorqueReduction_Request(uint8 TrqReduction);
void Rte_write_g_OUT_CurrentGear(uint8 Gear);

#endif /* RTE_RTE_WRITE_H_ */
