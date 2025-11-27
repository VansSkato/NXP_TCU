/*
 * global_signals.c
 *
 *  Created on: Nov 11, 2025
 *      Author: bruno
 */
#include "global_signals.h" // Incluimos su propio.h por consistencia
// --- DEFINICIONES DE SEÑALES GLOBALES ---

// Señales de CAN (entradas a la TCU)
uint16 g_CAN_EngineRPM = 0; 		//RPM del motor
uint8 g_CAN_ThrottlePosition = 0;   //Torque demandado por el conductor
sint16 g_CAN_EngineTorque = 0; 		//Torque del motor
uint8 g_CAN_VehicleSpeed = 0;		//Velocidad del automovil
uint8 g_CAN_DriveMode = 0;			//Tipo de modo (ECO, Sport, etc.)
uint8 g_CAN_IgnitionStatus = 0;		//Estado de la Ignición

// Señales de Hardwired (entradas a la TCU)
uint8 g_HW_LeverPosition = 0;  		//Sensor de posición de palanca de velocidad
uint8 g_HW_BrakeSW = 0;				//Sensor de freno
uint16 g_HW_InputSpeed	= 0;		//Sensor de velocidad de entrada del eje
uint16 g_HW_OutputSpeed = 0;		//Sensor de velocidad de salida del eje
sint8 g_HW_TransmissionTEMP = 0;    //Sensor de Temperatura


// Señales de Salida (controladas por la TCU)
uint8 g_OUT_ShiftSolenoid = 0;			//ON/OFF de los solenoides para la marcha
uint8 g_OUT_LinePressure_Control = 0;	//PWM que controla la presión general
uint8 g_OUT_TCC_ControlSolenoid = 0;	//PWM que controla la presión de los convertidores
uint8 g_OUT_ShiftLock_Solenoid = 0;		//Permite el cambio de marcha si el pedal del freno esta activo
uint8 g_OUT_TorqueReduction_Request = 0; //Reduce temporalmente el giro del motor
uint8 g_OUT_CurrentGear = 0;			//Muestra la marcha actual en el cluster
