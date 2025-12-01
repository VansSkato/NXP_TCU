/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: proyecto_final2.c
 *
 * Code generated for Simulink model 'proyecto_final2'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Dec  1 14:57:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "proyecto_final2.h"
#include "Cambios.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_proyecto_final2_T proyecto_final2_B;

/* Block states (default storage) */
DW_proyecto_final2_T proyecto_final2_DW;

/* External inputs (root inport signals with default storage) */
ExtU_proyecto_final2_T proyecto_final2_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_proyecto_final2_T proyecto_final2_Y;

/* Real-time model */
static RT_MODEL_proyecto_final2_T proyecto_final2_M_;
RT_MODEL_proyecto_final2_T *const proyecto_final2_M = &proyecto_final2_M_;

/* Model step function */
void proyecto_final2_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/ Cambios' */

  /* Inport: '<Root>/Gear_Lever_Position' incorporates:
   *  Inport: '<Root>/Brake_Pedal_Switch'
   *  Inport: '<Root>/Driver_Mode_Selection'
   *  Inport: '<Root>/LINE_PRESSURE_PIN'
   *  Inport: '<Root>/Selenode_A_PIN'
   *  Inport: '<Root>/Selenode_B_PIN'
   *  Inport: '<Root>/Switch'
   *  Inport: '<Root>/TCC_CONTROL_PIN'
   *  Outport: '<Root>/value'
   */
  proyecto_final2_Cambios(proyecto_final2_U.Gear_Lever_Position,
    proyecto_final2_U.Brake_Pedal_Switch,
    proyecto_final2_U.Driver_Mode_Selection, proyecto_final2_U.Switch,
    proyecto_final2_U.LINE_PRESSURE_PIN, proyecto_final2_U.TCC_CONTROL_PIN,
    proyecto_final2_U.Selenode_A_PIN, proyecto_final2_U.Selenode_B_PIN,
    &proyecto_final2_B.value3, &proyecto_final2_Y.value,
    &proyecto_final2_DW.Cambios);

  /* End of Outputs for SubSystem: '<Root>/ Cambios' */

  /* Outport: '<Root>/value3' */
  proyecto_final2_Y.value3 = proyecto_final2_B.value3;

  /* Outport: '<Root>/Shift_Solenoid_A_B_C' */
  proyecto_final2_Y.Shift_Solenoid_A_B_C = 0U;
}

/* Model initialize function */
void proyecto_final2_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/ Cambios' */

  /* SystemInitialize for Outport: '<Root>/Current_Gear' incorporates:
   *  Outport: '<Root>/Line_Pressure_Control_Solenoid'
   *  Outport: '<Root>/Shift_Lock_Solenoid'
   *  Outport: '<Root>/Shift_Solenoid_A'
   *  Outport: '<Root>/TCC_Control_Solenoid'
   *  Outport: '<Root>/Transmission_MIL_Status'
   *  Outport: '<Root>/value'
   */
  proyecto_final2_Cambios_Init(&proyecto_final2_Y.Current_Gear,
    &proyecto_final2_Y.Transmission_MIL_Status, &proyecto_final2_B.value3,
    &proyecto_final2_Y.value, &proyecto_final2_Y.TCC_Control_Solenoid,
    &proyecto_final2_Y.Shift_Solenoid_A, &proyecto_final2_Y.Shift_Lock_Solenoid,
    &proyecto_final2_Y.Line_Pressure_Control_Solenoid);

  /* End of SystemInitialize for SubSystem: '<Root>/ Cambios' */
}

/* Model terminate function */
void proyecto_final2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
