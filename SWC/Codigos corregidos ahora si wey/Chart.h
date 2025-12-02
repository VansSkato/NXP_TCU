/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Chart.h
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

#ifndef Chart_h_
#define Chart_h_
#ifndef proyecto_final2_COMMON_INCLUDES_
#define proyecto_final2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* proyecto_final2_COMMON_INCLUDES_ */

/* Block states (default storage) for system '<S1>/Chart' */
typedef struct {
  uint8_T is_active_c3_proyecto_final2;/* '<S1>/Chart' */
  uint8_T is_c3_proyecto_final2;       /* '<S1>/Chart' */
  uint8_T is_Drive;                    /* '<S1>/Chart' */
  uint8_T is_c3_DriverMode_Library;    /* '<S2>/DriverMode' */
} DW_Chart_proyecto_final2_T;

extern boolean_T proyecto_final2_Shift_Lock(uint8_T rtu_B1, uint8_T rtu_B2);
extern uint16_T proyecto_final2_Rpm_Limiter2(void);
extern void proyecto_final2_Chart_Init(uint8_T *rty_Current_Gear, uint16_T
  *rty_value3, boolean_T *rty_value);
extern void proyecto_final2_Chart(uint8_T rtu_Gear_Lever_Position, uint8_T
  rtu_Brake_Pedal_Switch, uint16_T rtu_Driver_Mode_Selection, uint8_T rtu_Switch,
  uint8_T rtu_Selenode_A_PIN, uint8_T rtu_Selenode_B_PIN, uint8_T
  rtu_TCC_CONTROL_PIN, uint8_T rtu_LINE_PRESSURE_PIN, uint8_T *rty_Current_Gear,
  uint16_T *rty_value3, boolean_T *rty_value, DW_Chart_proyecto_final2_T
  *localDW);

#endif                                 /* Chart_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
