

#include "tcc_control.h"




// =========================================================
//                   FUNCION PRINCIPAL
// =========================================================

/**
 * @brief Calcula y aplica los valores PWM para los 4 solenoides.
 * * La lógica asume que la presión necesaria para una transición (cambio de gear) 
 * debe ser aplicada en un conjunto específico de solenoides que controlan el 
 * flujo hidráulico para acoplar o desacoplar un clutch/banda.
 * * @param gear La velocidad actual de la transmisión (1 a N).
 * @param modo El modo de conducción (MODO_ECO, MODO_NORMAL, MODO_SPORT).
 * @param velocidad_kmh La velocidad actual del vehículo en km/h (no usada en esta versión).
 * @return ValoresPWM Retorna la estructura con los valores PWM aplicados.
 */
ValoresPWM control_solenoides_pwm(uint8 gear, ModoConduccion modo, uint8 velocidad_kmh) {
    ValoresPWM nuevos_pwm = {0, 0, 0, 0};
    int valor_base_pwm = 0;

    // 1. Determinar el valor base de presión (PWM) según el Modo de Conducción
    switch (modo) {
        case MODO_ECO:
            // En modo ECO, los cambios deben ser suaves para ahorrar combustible
            valor_base_pwm = PWM_SUAVE;
            break;
        case MODO_NORMAL:
            // En modo NORMAL, un equilibrio (semi-suave)
            valor_base_pwm = PWM_SEMI_SUAVE;
            break;
        case MODO_SPORT:
            // En modo SPORT, los cambios deben ser más bruscos/rápidos para rendimiento
            valor_base_pwm = PWM_BRUSCO;
            break;
        default:
            // Valor por defecto de seguridad
            valor_base_pwm = PWM_SEMI_SUAVE;
            break;
    }

    // 2. Asignar los valores PWM a los solenoides según el Gear y la lógica de la transmisión
    // **********************************************************************************
    // NOTA IMPORTANTE: Esta lógica (qué solenoide tiene qué valor en cada gear)
    // depende COMPLETAMENTE del *diagrama hidráulico* y la *tabla de solenoides*
    // de tu transmisión automática específica. ESTOS SON VALORES DE EJEMPLO.
    // **********************************************************************************
    switch (gear) {
        case 1:
            // Gear 1: Solenoide A y B activados con la presión base
            nuevos_pwm.s1_pwm = valor_base_pwm;
            nuevos_pwm.s2_pwm = valor_base_pwm;
            nuevos_pwm.s3_pwm = PWM_CERO_PRESION;
            nuevos_pwm.s4_pwm = PWM_CERO_PRESION;
            break;
        case 2:
            // Gear 2: Solenoide B y C activados. Se puede refinar el PWM
            // para una transición de 1 a 2 ligeramente diferente.
            nuevos_pwm.s1_pwm = PWM_CERO_PRESION;
            nuevos_pwm.s2_pwm = valor_base_pwm + (valor_base_pwm / 4); // Ligeramente más alto
            nuevos_pwm.s3_pwm = valor_base_pwm;
            nuevos_pwm.s4_pwm = PWM_CERO_PRESION;
            break;
        case 3:
            // Gear 3: Solenoide A, C y D activados.
            nuevos_pwm.s1_pwm = valor_base_pwm;
            nuevos_pwm.s2_pwm = PWM_CERO_PRESION;
            nuevos_pwm.s3_pwm = valor_base_pwm;
            nuevos_pwm.s4_pwm = valor_base_pwm;
            break;
        case 4:
            // Gear 4: Solenoide D activado, A y C en valores de retención
            nuevos_pwm.s1_pwm = valor_base_pwm / 2; // Menor presión
            nuevos_pwm.s2_pwm = PWM_CERO_PRESION;
            nuevos_pwm.s3_pwm = valor_base_pwm / 2;
            nuevos_pwm.s4_pwm = valor_base_pwm;
            break;
        default:
            // Neutro/Fallo: Todos apagados o en un estado de seguridad.
            nuevos_pwm.s1_pwm = PWM_CERO_PRESION;
            nuevos_pwm.s2_pwm = PWM_CERO_PRESION;
            nuevos_pwm.s3_pwm = PWM_CERO_PRESION;
            nuevos_pwm.s4_pwm = PWM_CERO_PRESION;
            break;
    }

    return nuevos_pwm;
}

/*
// Ejemplo de cómo llamar la función en tu 'main' o 'loop'

void main_loop() {
    int current_gear = 3;
    ModoConduccion current_mode = MODO_SPORT;
    int current_speed = 60; // km/h

    ValoresPWM aplicados = control_solenoides_pwm(current_gear, current_mode, current_speed);

    // Puedes imprimir los valores para debug si tienes una UART
    // printf("Gear %d en modo %d. PWMs aplicados: S1=%d, S2=%d, S3=%d, S4=%d\n", 
    //        current_gear, current_mode, 
    //        aplicados.s1_pwm, aplicados.s2_pwm, aplicados.s3_pwm, aplicados.s4_pwm);
}
*/
