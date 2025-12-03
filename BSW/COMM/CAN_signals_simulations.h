#ifndef _CAN_SIGNALS_SIMULATIONS_H_
#define _CAN_SIGNALS_SIMULATIONS_H_

#include "Platform_Types.h"

void Simulate_CAN_Bus_Update(int step_index);
void Print_System_State(int time_step);

// =========================================================
// 1. DEFINICIÓN DE TIPOS DE DATOS (Basado en las imágenes)
// =========================================================

// Enum para Gear Lever Position (0-7)
typedef enum {
    GEAR_POS_P = 0,
    GEAR_POS_R = 1,
    GEAR_POS_N = 2,
    GEAR_POS_D = 3,
    GEAR_POS_LOW = 4,
    // Otros estados reservados...
} GearLeverPos_t;

// Enum para Driver Mode Selection
typedef enum {
    DRIVE_MODE_ECO = 0,
    DRIVE_MODE_SPORT = 1
} DriveMode_t;

// Estructura que representa todas las entradas que el Microcontrolador recibe
// (Tanto las que vendrían por CAN como las Hardwired simuladas)
typedef struct {
    // --- Señales CAN (Simuladas) ---
	uint16 engine_rpm;        // 0 - 8000 RPM
	uint16  throttle_pos;      // 0 - 100 %
	sint16  engine_torque;     // -50 a 400 Nm
    uint8  vehicle_speed_ref; // 0 - 250 kph (ABS)
    DriveMode_t drive_mode;     // Eco/Sport

    // --- Señales Hardwired (Simuladas para coherencia) ---
    // Aunque son hardwired, necesitas inyectar valores para probar tu lógica
    GearLeverPos_t gear_lever;
    boolean     brake_pedal_sw;    // 0 o 1
    uint16 turbine_speed;     // Entrada a la transmisión
    uint16 output_speed;      // Salida de la transmisión
    sint16  trans_fluid_temp;  // -40 a 150 C
} TCU_Input_Signals_t;

// Variable Global que representa el estado actual de las entradas del Micro
extern TCU_Input_Signals_t current_inputs;

// Escenario: El auto está en Parking, se enciende, pasa a Drive,
// acelera suavemente pasando por 1ra y 2da marcha, y luego suelta el acelerador.
// Asumimos un muestreo cada 100ms (0.1s).
#define SCENARIO_STEPS 25

#endif /*_CAN_SIGNALS_SIMULATIONS_H_*/
