#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

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
    uint16_t engine_rpm;        // 0 - 8000 RPM
    uint8_t  throttle_pos;      // 0 - 100 %
    int16_t  engine_torque;     // -50 a 400 Nm
    uint8_t  vehicle_speed_ref; // 0 - 250 kph (ABS)
    DriveMode_t drive_mode;     // Eco/Sport

    // --- Señales Hardwired (Simuladas para coherencia) ---
    // Aunque son hardwired, necesitas inyectar valores para probar tu lógica
    GearLeverPos_t gear_lever;
    bool     brake_pedal_sw;    // 0 o 1
    uint16_t turbine_speed;     // Entrada a la transmisión
    uint16_t output_speed;      // Salida de la transmisión
    int16_t  trans_fluid_temp;  // -40 a 150 C
} TCU_Input_Signals_t;

// Variable Global que representa el estado actual de las entradas del Micro
TCU_Input_Signals_t current_inputs;

// =========================================================
// 2. ARREGLOS DE DATOS DE ESCENARIO (SIMULACIÓN)
// =========================================================
// Escenario: El auto está en Parking, se enciende, pasa a Drive,
// acelera suavemente pasando por 1ra y 2da marcha, y luego suelta el acelerador.
// Asumimos un muestreo cada 100ms (0.1s).
#define SCENARIO_STEPS 25

// Paso 0-4: Idle en Parking
// Paso 5: Cambio a Drive
// Paso 6-20: Aceleración (Cambio de marcha simulado en el paso 13)
// Paso 21-24: Soltar acelerador (Coasting)

const uint16_t DATA_ENGINE_RPM[SCENARIO_STEPS] = { 
    800, 800, 800, 800, 800,              // Idle
    850, 1200, 1500, 1800, 2200, 2500,    // Acelerando en 1ra
    2800, 3000,                           // Punto de cambio
    1800, 1900, 2100, 2300, 2500, 2700,   // Cayó RPM (entró 2da) y sigue subiendo
    2800, 2000, 1500, 1200, 1000, 800     // Soltó acelerador
};

const uint8_t DATA_THROTTLE[SCENARIO_STEPS] = {
    0, 0, 0, 0, 0,                        // Sin pie en acelerador
    10, 20, 30, 35, 35, 40,               // Pisando acelerador
    40, 40,                               // Manteniendo
    45, 45, 50, 50, 50, 50,               // Acelerando más
    50, 0, 0, 0, 0, 0                     // Soltó de golpe
};

const uint8_t DATA_VEHICLE_SPEED[SCENARIO_STEPS] = {
    0, 0, 0, 0, 0,                        // Quieto
    0, 2, 5, 10, 15, 20,                  // Ganando velocidad
    25, 30,                               // Momento del cambio (30kph)
    32, 35, 40, 45, 50, 55,               // Sigue ganando velocidad en 2da
    58, 57, 55, 53, 50, 48                // Desacelerando por fricción
};

const int16_t DATA_TORQUE[SCENARIO_STEPS] = {
    10, 10, 10, 10, 10,                   // Torque base idle
    50, 100, 150, 180, 190, 200,          // Torque sube con carga
    150, 100,                             // Torque baja momentáneamente en el cambio (Torque reduction request)
    180, 190, 200, 210, 210, 210,         // Torque vuelve
    210, -10, -20, -25, -30, -30          // Torque negativo (Freno de motor)
};

const GearLeverPos_t DATA_GEAR_LEVER[SCENARIO_STEPS] = {
    GEAR_POS_P, GEAR_POS_P, GEAR_POS_P,       // Parking
    GEAR_POS_N, GEAR_POS_D,                   // Pasa a Neutro, luego Drive
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D,
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D,
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D,
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D
};

const bool DATA_BRAKE_SW[SCENARIO_STEPS] = {
    1, 1, 1,                              // Freno pisado para mover palanca
    0, 0,                                 // Suelta freno
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      // Manejando
    0, 0, 0, 0, 0, 0, 0, 0, 0             // Sigue sin frenar (coasting)
};


// =========================================================
// 3. FUNCIONES DE SIMULACIÓN E INTERFAZ
// =========================================================

/**
 * @brief Simula la recepción de tramas CAN y lectura de sensores.
 * Esta función debe ser llamada periódicamente (ej. cada 100ms) en tu loop principal de prueba.
 * * @param step_index El índice actual del tiempo de simulación.
 */
void Simulate_CAN_Bus_Update(int step_index) {
    if (step_index < 0 || step_index >= SCENARIO_STEPS) {
        // Si se acaba el escenario, mantenemos los últimos valores seguros (Idle)
        current_inputs.engine_rpm = 800;
        current_inputs.throttle_pos = 0;
        current_inputs.engine_torque = 10;
        current_inputs.vehicle_speed_ref = 0;
        return;
    }

    // --- 1. Cargar señales CAN desde los arreglos ---
    current_inputs.engine_rpm = DATA_ENGINE_RPM[step_index];
    current_inputs.throttle_pos = DATA_THROTTLE[step_index];
    current_inputs.engine_torque = DATA_TORQUE[step_index];
    current_inputs.vehicle_speed_ref = DATA_VEHICLE_SPEED[step_index];
    current_inputs.drive_mode = DRIVE_MODE_ECO; // Valor fijo para este test
    
    // --- 2. Cargar señales Hardwired ---
    current_inputs.gear_lever = DATA_GEAR_LEVER[step_index];
    current_inputs.brake_pedal_sw = DATA_BRAKE_SW[step_index];

    // --- 3. Calcular Lógica de Sensores Internos (Coherencia) ---
    // Para que la simulación "haga sentido", los sensores internos deben coincidir con el CAN.
    
    // Turbine Speed: Generalmente igual a Engine RPM (si el convertidor está bloqueado)
    // o ligeramente menor (si hay resbalamiento). Simulamos un resbalamiento del 5%.
    if (current_inputs.engine_rpm > 0) {
        current_inputs.turbine_speed = current_inputs.engine_rpm * 0.95;
    } else {
        current_inputs.turbine_speed = 0;
    }

    // Output Speed: Directamente proporcional a la velocidad del vehículo.
    // Asumimos un factor de conversión arbitrario (ej. RPM = KPH * 30 para el diferencial)
    current_inputs.output_speed = current_inputs.vehicle_speed_ref * 30; 

    // Temperatura: Simulamos un calentamiento lento
    current_inputs.trans_fluid_temp = 40 + (step_index / 2); // Sube 0.5 grados por step
}

/**
 * @brief Función auxiliar para imprimir el estado (Como si fuera un Log)
 */
void Print_System_State(int time_step) {
    printf("T=%02d | GearLv: %d | Mode: %s | RPM: %04d | Speed: %03d km/h | Trq: %03d Nm | Thr: %03d%% | Brake: %d\n", 
           time_step,
           current_inputs.gear_lever,
           (current_inputs.drive_mode == DRIVE_MODE_SPORT) ? "SPT" : "ECO",
           current_inputs.engine_rpm,
           current_inputs.vehicle_speed_ref,
           current_inputs.engine_torque,
           current_inputs.throttle_pos,
           current_inputs.brake_pedal_sw);
           
    // Detección simple de cambio de marcha basado en la caída de RPM mientras se acelera
    if(time_step == 12) printf("      >> LOGIC EVENT: Preparando Shift UP \n");
    if(time_step == 13) printf("      >> LOGIC EVENT: Shift Executed (RPM Drop) \n");
}

// =========================================================
// 4. FUNCIÓN MAIN (EJEMPLO DE EJECUCIÓN)
// =========================================================

// int main() {
//     printf("--- INICIO DE SIMULACIÓN DE TCU (CAN BUS SUBSTITUTE) ---\n");
//     printf("Simulando: Arranque -> Aceleración (Shift 1-2) -> Coasting\n\n");

    // for (int i = 0; i < SCENARIO_STEPS; i++) {
    //     // 1. Actualizar las entradas simuladas
    //     Simulate_CAN_Bus_Update(i);

    //     // 2. Aquí iría la llamada a tu lógica de control real
    //     // TCU_Main_Control_Loop(); 

    //     // 3. Imprimir resultados para verificar
    //     //Print_System_State(i);
        
    //     // // Simular retardo de tiempo si se corriera en tiempo real
    //     // delay_ms(100); 
    // }

//     printf("\n--- FIN DE SIMULACIÓN ---\n");
//     return 0;
// }