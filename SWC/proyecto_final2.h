/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: proyecto_final2.h
 *
 * Code generated for Simulink model 'proyecto_final2'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Nov 27 20:32:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef proyecto_final2_h_
#define proyecto_final2_h_
#ifndef proyecto_final2_COMMON_INCLUDES_
#define proyecto_final2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* proyecto_final2_COMMON_INCLUDES_ */

#include "proyecto_final2_types.h"
#include "Cambios.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint16_T value3;                     /* '<S1>/Chart' */
} B_proyecto_final2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_Cambios_proyecto_final2_T Cambios;/* '<Root>/ Cambios' */
} DW_proyecto_final2_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T Gear_Lever_Position;         /* '<Root>/Gear_Lever_Position' */
  uint8_T Brake_Pedal_Switch;          /* '<Root>/Brake_Pedal_Switch' */
  uint8_T Output_Speed_Sensor;         /* '<Root>/Output_Speed_Sensor' */
  uint8_T Engine_Rpm;                  /* '<Root>/Engine_Rpm' */
  uint8_T Throttle_Position_Sensor;    /* '<Root>/Throttle_Position_Sensor' */
  uint8_T Vehicle_Speed_Reference;     /* '<Root>/Vehicle_Speed_Reference' */
  uint16_T Driver_Mode_Selection;      /* '<Root>/Driver_Mode_Selection' */
  uint8_T Switch;                      /* '<Root>/Switch' */
  uint8_T LINE_PRESSURE_PIN;           /* '<Root>/LINE_PRESSURE_PIN' */
  uint8_T TCC_CONTROL_PIN;             /* '<Root>/TCC_CONTROL_PIN' */
  uint8_T Selenode_A_PIN;              /* '<Root>/Selenode_A_PIN' */
  uint8_T Selenode_B_PIN;              /* '<Root>/Selenode_B_PIN' */
} ExtU_proyecto_final2_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T Current_Gear;                /* '<Root>/Current_Gear' */
  uint8_T Transmission_MIL_Status;     /* '<Root>/Transmission_MIL_Status' */
  uint16_T value3;                     /* '<Root>/value3' */
  boolean_T value;                     /* '<Root>/value' */
  uint8_T TCC_Control_Solenoid;        /* '<Root>/TCC_Control_Solenoid' */
  uint8_T Shift_Solenoid_A;            /* '<Root>/Shift_Solenoid_A' */
  uint8_T Shift_Lock_Solenoid;         /* '<Root>/Shift_Lock_Solenoid' */
  uint8_T Line_Pressure_Control_Solenoid;
                                   /* '<Root>/Line_Pressure_Control_Solenoid' */
  uint8_T Shift_Solenoid_A_B_C;        /* '<Root>/Shift_Solenoid_A_B_C' */
} ExtY_proyecto_final2_T;

/* Real-time Model Data Structure */
struct tag_RTM_proyecto_final2_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_proyecto_final2_T proyecto_final2_B;

/* Block states (default storage) */
extern DW_proyecto_final2_T proyecto_final2_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_proyecto_final2_T proyecto_final2_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_proyecto_final2_T proyecto_final2_Y;

/* Model entry point functions */
extern void proyecto_final2_initialize(void);
extern void proyecto_final2_step(void);
extern void proyecto_final2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_proyecto_final2_T *const proyecto_final2_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'proyecto_final2'
 * '<S1>'   : 'proyecto_final2/ Cambios'
 * '<S2>'   : 'proyecto_final2/ Cambios/Chart'
 * '<S3>'   : 'proyecto_final2/ Cambios/Chart/DriverMode'
 * '<S4>'   : 'proyecto_final2/ Cambios/Chart/Shift_Lock'
 * '<S5>'   : 'proyecto_final2/ Cambios/Chart/DriverMode/Rpm_Limiter2'
 * '<S6>'   : 'proyecto_final2/ Cambios/Chart/DriverMode/Rpm_Limiter2/Compare To Constant'
 * '<S7>'   : 'proyecto_final2/ Cambios/Chart/DriverMode/Rpm_Limiter2/Compare To Constant1'
 * '<S8>'   : 'proyecto_final2/ Cambios/Chart/DriverMode/Rpm_Limiter2/Compare To Constant2'
 * '<S9>'   : 'proyecto_final2/ Cambios/Chart/Shift_Lock/Compare To Constant'
 * '<S10>'  : 'proyecto_final2/ Cambios/Chart/Shift_Lock/Compare To Constant1'
 */
#endif                                 /* proyecto_final2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
