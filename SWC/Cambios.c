/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Cambios.c
 *
 * Code generated for Simulink model 'proyecto_final2'.
 *
 * Model version                  : 1.53
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Dec  1 20:24:52 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "Cambios.h"
#include "Chart.h"

/* System initialize for atomic system: '<Root>/ Cambios' */
void proyecto_final2_Cambios_Init(uint8_T *rty_Current_Gear, uint16_T
  *rty_value3, boolean_T *rty_value)
{
  /* SystemInitialize for Chart: '<S1>/Chart' */
  proyecto_final2_Chart_Init(rty_Current_Gear, rty_value3, rty_value);
}

/* Output and update for atomic system: '<Root>/ Cambios' */
void proyecto_final2_Cambios(uint8_T rtu_Gear_Lever_Position, uint8_T
  rtu_Brake_Pedal_Switch, uint16_T rtu_Driver_Mode_Selection, uint8_T rtu_Switch,
  uint8_T rtu_LINE_PRESSURE_PIN, uint8_T rtu_TCC_CONTROL_PIN, uint8_T
  rtu_Selenode_A_PIN, uint8_T rtu_Selenode_B_PIN, uint8_T *rty_Current_Gear,
  uint16_T *rty_value3, boolean_T *rty_value, DW_Cambios_proyecto_final2_T
  *localDW)
{
  /* Chart: '<S1>/Chart' */
  proyecto_final2_Chart(rtu_Gear_Lever_Position, rtu_Brake_Pedal_Switch,
                        rtu_Driver_Mode_Selection, rtu_Switch,
                        rtu_Selenode_A_PIN, rtu_Selenode_B_PIN,
                        rtu_TCC_CONTROL_PIN, rtu_LINE_PRESSURE_PIN,
                        rty_Current_Gear, rty_value3, rty_value,
                        &localDW->sf_Chart);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
