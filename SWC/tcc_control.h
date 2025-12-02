

// =========================================================
//                   DEFINICIONES
// =========================================================
#include "Platform_Types.h"
// Definición de los Modos de Conducción
typedef enum {
    MODO_ECO,
    MODO_NORMAL,
    MODO_SPORT
} ModoConduccion;

// Valores de PWM (Ciclo de Trabajo) para la transición
// Los valores son de ejemplo y deben ajustarse con pruebas reales.
// Asumimos un máximo de 1023 para el ciclo de trabajo (100% PWM)
#define PWM_CERO_PRESION    0       // Solenoide completamente apagado
#define PWM_SUAVE           200     // Cambio suave (presión baja)
#define PWM_SEMI_SUAVE      450     // Cambio semisuave (presión media)
#define PWM_BRUSCO          700     // Cambio brusco (presión alta)
#define PWM_MAX_PRESION     1023    // Solenoide completamente encendido (si es necesario)

// Definición de los pines/canales PWM para los solenoides
// ESTO DEBE COINCIDIR CON LA CONFIGURACIÓN DE TU HARDWARE
#define SOLENOIDE_A_CHANNEL 0
#define SOLENOIDE_B_CHANNEL 1
#define SOLENOIDE_C_CHANNEL 2
#define SOLENOIDE_D_CHANNEL 3

// Estructura para almacenar los valores PWM
typedef struct {
    int s1_pwm;
    int s2_pwm;
    int s3_pwm;
    int s4_pwm;
} ValoresPWM;



ValoresPWM control_solenoides_pwm(uint8 gear, ModoConduccion modo, uint8 velocidad_kmh);



