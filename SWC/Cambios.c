/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Cambios.c
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

#include "rtwtypes.h"
#include "Cambios.h"

/* Named constants for Chart: '<S2>/DriverMode' */
#define proyecto_fin_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define proyecto_final2_IN_Eco         ((uint8_T)1U)
#define proyecto_final2_IN_Normal      ((uint8_T)2U)
#define proyecto_final2_IN_Sport       ((uint8_T)3U)

/* Named constants for Chart: '<S1>/Chart' */
#define proyecto_final2_IN_Drive       ((uint8_T)1U)
#define proyecto_final2_IN_DriverMode  ((uint8_T)2U)
#define proyecto_final2_IN_Fifth       ((uint8_T)1U)
#define proyecto_final2_IN_First       ((uint8_T)2U)
#define proyecto_final2_IN_Fourth      ((uint8_T)3U)
#define proyecto_final2_IN_Neutral     ((uint8_T)3U)
#define proyecto_final2_IN_Parking     ((uint8_T)4U)
#define proyecto_final2_IN_Second      ((uint8_T)4U)
#define proyecto_final2_IN_Third       ((uint8_T)5U)

/* Forward declaration for local functions */
static void proyecto_final2_Drive(uint8_T *B2, uint8_T *B1, boolean_T
  *LogicalOperator, uint8_T rtu_Gear_Lever_Position, uint8_T
  rtu_Brake_Pedal_Switch, uint8_T rtu_Switch, uint8_T rtu_LINE_PRESSURE_PIN,
  uint8_T rtu_TCC_CONTROL_PIN, uint8_T rtu_Selenode_A_PIN, uint8_T
  rtu_Selenode_B_PIN, uint16_T *rty_value3, DW_Cambios_proyecto_final2_T
  *localDW);

/* Output and update for function-call system: '<S2>/Shift_Lock' */
boolean_T proyecto_final2_Shift_Lock(uint8_T rtu_B1, uint8_T rtu_B2)
{
  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  return (rtu_B1 == 1) && (rtu_B2 == 1);
}

/* Output and update for function-call system: '<S3>/Rpm_Limiter2' */
uint16_T proyecto_final2_Rpm_Limiter2(uint16_T rtu_D1)
{
  uint16_T rty_result4_0;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  Switch: '<S5>/Switch1'
   *  Switch: '<S5>/Switch2'
   */
  if (rtu_D1 == 0) {
    rty_result4_0 = 5000U;
  } else if (rtu_D1 == 1) {
    /* Switch: '<S5>/Switch1' incorporates:
     *  Constant: '<S5>/Constant1'
     */
    rty_result4_0 = 2500U;
  } else if (rtu_D1 == 2) {
    /* Switch: '<S5>/Switch2' incorporates:
     *  Constant: '<S5>/Constant2'
     *  Switch: '<S5>/Switch1'
     */
    rty_result4_0 = 6500U;
  } else {
    /* Switch: '<S5>/Switch1' incorporates:
     *  Constant: '<S5>/Constant3'
     *  Switch: '<S5>/Switch2'
     */
    rty_result4_0 = 750U;
  }

  /* End of Switch: '<S5>/Switch' */
  return rty_result4_0;
}

/* Function for Chart: '<S1>/Chart' */
static void proyecto_final2_Drive(uint8_T *B2, uint8_T *B1, boolean_T
  *LogicalOperator, uint8_T rtu_Gear_Lever_Position, uint8_T
  rtu_Brake_Pedal_Switch, uint8_T rtu_Switch, uint8_T rtu_LINE_PRESSURE_PIN,
  uint8_T rtu_TCC_CONTROL_PIN, uint8_T rtu_Selenode_A_PIN, uint8_T
  rtu_Selenode_B_PIN, uint16_T *rty_value3, DW_Cambios_proyecto_final2_T
  *localDW)
{
  boolean_T b;

  /* Chart: '<S1>/Chart' */
  *B1 = rtu_Brake_Pedal_Switch;
  *B2 = rtu_Switch;

  /* Outputs for Function Call SubSystem: '<S2>/Shift_Lock' */
  *LogicalOperator = proyecto_final2_Shift_Lock(*B1, *B2);

  /* End of Outputs for SubSystem: '<S2>/Shift_Lock' */
  switch (localDW->is_Drive) {
   case proyecto_final2_IN_Fifth:
    localDW->is_Drive = proyecto_final2_IN_Fourth;
    break;

   case proyecto_final2_IN_First:
    /* Chart: '<S1>/Chart' */
    b = ((*rty_value3 == 2500) || (*rty_value3 == 5000) || ((*rty_value3 == 6500)
          && (rtu_Gear_Lever_Position != 4) && (rtu_Gear_Lever_Position != 5) &&
          (rtu_Gear_Lever_Position != 6) && (rtu_LINE_PRESSURE_PIN == 1) &&
          (rtu_TCC_CONTROL_PIN == 0) && (rtu_Selenode_A_PIN == 0) &&
          (rtu_Selenode_B_PIN == 1)));
    if (b) {
      localDW->is_Drive = proyecto_final2_IN_Second;
    }
    break;

   case proyecto_final2_IN_Fourth:
    localDW->is_Drive = proyecto_final2_IN_Third;
    break;

   case proyecto_final2_IN_Second:
    /* Chart: '<S1>/Chart' */
    b = ((*rty_value3 == 2500) || (*rty_value3 == 5000) || ((*rty_value3 == 6500)
          && (rtu_Gear_Lever_Position != 4) && (rtu_Gear_Lever_Position != 5) &&
          (rtu_Gear_Lever_Position != 6) && (rtu_LINE_PRESSURE_PIN == 1) &&
          (rtu_TCC_CONTROL_PIN == 0) && (rtu_Selenode_A_PIN == 1) &&
          (rtu_Selenode_B_PIN == 1)));
    if (b) {
      localDW->is_Drive = proyecto_final2_IN_Third;
    } else {
      localDW->is_Drive = proyecto_final2_IN_First;
    }
    break;

   case proyecto_final2_IN_Third:
    localDW->is_Drive = proyecto_final2_IN_Second;
    break;

   default:
    /* case IN_sixth: */
    localDW->is_Drive = proyecto_final2_IN_Fifth;
    break;
  }
}

/* System initialize for atomic system: '<Root>/ Cambios' */
void proyecto_final2_Cambios_Init(uint8_T *rty_Current_Gear, uint8_T
  *rty_Transmission_MIL_Status, uint16_T *rty_value3, boolean_T *rty_value,
  uint8_T *rty_TCC_Control_Solenoid, uint8_T *rty_Shift_Solenoid_A, uint8_T
  *rty_Shift_Lock_Solenoid, uint8_T *rty_Line_Pressure_Control_Solen, uint8_T
  *rty_Shift_Solenoid_A_B_C)
{
  /* SystemInitialize for Chart: '<S1>/Chart' */
  *rty_Current_Gear = 0U;
  *rty_Transmission_MIL_Status = 0U;
  *rty_value3 = 0U;
  *rty_value = false;
  *rty_TCC_Control_Solenoid = 0U;
  *rty_Shift_Solenoid_A = 0U;
  *rty_Shift_Lock_Solenoid = 0U;
  *rty_Line_Pressure_Control_Solen = 0U;
  *rty_Shift_Solenoid_A_B_C = 0U;
}

/* Output and update for atomic system: '<Root>/ Cambios' */
void proyecto_final2_Cambios(uint8_T rtu_Gear_Lever_Position, uint8_T
  rtu_Brake_Pedal_Switch, uint16_T rtu_Driver_Mode_Selection, uint8_T rtu_Switch,
  uint8_T rtu_LINE_PRESSURE_PIN, uint8_T rtu_TCC_CONTROL_PIN, uint8_T
  rtu_Selenode_A_PIN, uint8_T rtu_Selenode_B_PIN, uint16_T *rty_value3,
  boolean_T *rty_value, DW_Cambios_proyecto_final2_T *localDW)
{
  uint16_T Switch;
  uint8_T B1;
  uint8_T B2;
  boolean_T LogicalOperator;

  /* Chart: '<S1>/Chart' */
  if (localDW->is_active_c3_proyecto_final2 == 0) {
    localDW->is_active_c3_proyecto_final2 = 1U;
    localDW->is_c3_proyecto_final2 = proyecto_final2_IN_Parking;
  } else {
    switch (localDW->is_c3_proyecto_final2) {
     case proyecto_final2_IN_Drive:
      proyecto_final2_Drive(&B2, &B1, &LogicalOperator, rtu_Gear_Lever_Position,
                            rtu_Brake_Pedal_Switch, rtu_Switch,
                            rtu_LINE_PRESSURE_PIN, rtu_TCC_CONTROL_PIN,
                            rtu_Selenode_A_PIN, rtu_Selenode_B_PIN, rty_value3,
                            localDW);
      break;

     case proyecto_final2_IN_DriverMode:
      if (rtu_Switch == 1) {
        localDW->is_c3_DriverMode_Library = proyecto_fin_IN_NO_ACTIVE_CHILD;
        localDW->is_c3_proyecto_final2 = proyecto_final2_IN_Drive;
        localDW->is_Drive = proyecto_final2_IN_First;
      } else {
        switch (localDW->is_c3_DriverMode_Library) {
         case proyecto_final2_IN_Eco:
          switch (rtu_Driver_Mode_Selection) {
           case 0U:
            localDW->is_c3_DriverMode_Library = proyecto_final2_IN_Normal;
            break;

           case 2U:
            localDW->is_c3_DriverMode_Library = proyecto_final2_IN_Sport;
            break;

           default:
            /* Outputs for Function Call SubSystem: '<S3>/Rpm_Limiter2' */
            Switch = proyecto_final2_Rpm_Limiter2(rtu_Driver_Mode_Selection);

            /* End of Outputs for SubSystem: '<S3>/Rpm_Limiter2' */
            *rty_value3 = Switch;
            break;
          }
          break;

         case proyecto_final2_IN_Normal:
          switch (rtu_Driver_Mode_Selection) {
           case 1U:
            localDW->is_c3_DriverMode_Library = proyecto_final2_IN_Eco;
            break;

           case 2U:
            localDW->is_c3_DriverMode_Library = proyecto_final2_IN_Sport;
            break;

           default:
            /* Outputs for Function Call SubSystem: '<S3>/Rpm_Limiter2' */
            Switch = proyecto_final2_Rpm_Limiter2(rtu_Driver_Mode_Selection);

            /* End of Outputs for SubSystem: '<S3>/Rpm_Limiter2' */
            *rty_value3 = Switch;
            break;
          }
          break;

         default:
          /* case IN_Sport: */
          switch (rtu_Driver_Mode_Selection) {
           case 0U:
            localDW->is_c3_DriverMode_Library = proyecto_final2_IN_Normal;
            break;

           case 1U:
            localDW->is_c3_DriverMode_Library = proyecto_final2_IN_Eco;
            break;

           default:
            /* Outputs for Function Call SubSystem: '<S3>/Rpm_Limiter2' */
            Switch = proyecto_final2_Rpm_Limiter2(rtu_Driver_Mode_Selection);

            /* End of Outputs for SubSystem: '<S3>/Rpm_Limiter2' */
            *rty_value3 = Switch;
            break;
          }
          break;
        }
      }
      break;

     case proyecto_final2_IN_Neutral:
      /* Outputs for Function Call SubSystem: '<S2>/Shift_Lock' */
      LogicalOperator = proyecto_final2_Shift_Lock(rtu_Brake_Pedal_Switch,
        rtu_Switch);

      /* End of Outputs for SubSystem: '<S2>/Shift_Lock' */
      *rty_value = LogicalOperator;
      break;

     case proyecto_final2_IN_Parking:
      /* Outputs for Function Call SubSystem: '<S2>/Shift_Lock' */
      LogicalOperator = proyecto_final2_Shift_Lock(rtu_Brake_Pedal_Switch,
        rtu_Switch);

      /* End of Outputs for SubSystem: '<S2>/Shift_Lock' */
      *rty_value = LogicalOperator;
      break;

     default:
      /* Outputs for Function Call SubSystem: '<S2>/Shift_Lock' */
      /* case IN_Reverse: */
      LogicalOperator = proyecto_final2_Shift_Lock(rtu_Brake_Pedal_Switch,
        rtu_Switch);

      /* End of Outputs for SubSystem: '<S2>/Shift_Lock' */
      *rty_value = LogicalOperator;
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
