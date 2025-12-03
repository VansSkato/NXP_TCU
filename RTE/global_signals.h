/*
 * global_signals.h
 *
 *  Created on: Nov 11, 2025
 *      Author: bruno
 */

#ifndef RTE_GLOBAL_SIGNALS_H_
#define RTE_GLOBAL_SIGNALS_H_


#include <Platform_Types.h> // Para uint16, uint8
#include "tcu_types.h" // (Asumiendo que aquí defines GearEnum)

// --- DECLARACIONES EXTERNAS DE SEÑALES GLOBALES ---
// "extern" significa: "Esta variable está definida en OTRO archivo.c"


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
extern uint32 g_TCM_TurbineSpeed_TSS;        // Turbine/Input Speed Sensor
extern uint32 g_TCM_OutputSpeed_OSS;         // Output Speed Sensor
extern sint32 g_TCM_FluidTemp_TFT;           // Transmission Fluid Temperature


// Señales de CAN (entradas a la TCU)
extern uint16 g_CAN_EngineRPM; 		//RPM del motor
extern uint8 g_CAN_ThrottlePosition;   //Torque demandado por el conductor
extern sint16 g_CAN_EngineTorque; 		//Torque del motor
extern uint8 g_CAN_VehicleSpeed;		//Velocidad del automovil
extern uint8 g_CAN_DriveMode;			//Tipo de modo (ECO, Sport, etc.)
extern uint8 g_CAN_IgnitionStatus;		//Estado de la Ignición

// Señales de Hardwired (entradas a la TCU)
extern uint8 g_HW_LeverPosition;  		//Sensor de posición de palanca de velocidad
extern uint8 g_HW_BrakeSW;				//Sensor de freno
extern uint16 g_HW_InputSpeed;		//Sensor de velocidad de entrada del eje
extern uint16 g_HW_OutputSpeed;		//Sensor de velocidad de salida del eje
extern sint8 g_HW_TransmissionTEMP;    //Sensor de Temperatura


// Señales de Salida (controladas por la TCU)
extern uint8 g_OUT_ShiftSolenoid;			//ON/OFF de los solenoides para la marcha
extern uint8 g_OUT_LinePressure_Control;	//PWM que controla la presión general
extern uint8 g_OUT_TCC_ControlSolenoid;	//PWM que controla la presión de los convertidores
extern uint8 g_OUT_ShiftLock_Solenoid;		//Permite el cambio de marcha si el pedal del freno esta activo
extern uint8 g_OUT_TorqueReduction_Request; //Reduce temporalmente el giro del motor
extern uint8 g_OUT_CurrentGear;			//Muestra la marcha actual en el cluster
//cambios de dirve
extern uint8 g_OUT_Drive_gear;//esta yo la cree



//selonoides:


extern uint8 g_OUT_a;
extern uint8 g_OUT_b;
extern uint8 g_OUT_c;
extern uint8 g_OUT_d;
#endif /* RTE_GLOBAL_SIGNALS_H_ */
