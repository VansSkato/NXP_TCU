#ifndef IOHWAB_ADC_H
#define IOHWAB_ADC_H

#include "app.h"
#include "fsl_port.h"
#include "board.h"
#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_lpadc.h"
#include "Platform_Types.h"

#include "Rte_Write.h"

/* Inicialización principal */
void Init_ADC_Pins(void);
void TCM_LPADC_InitSensors(void);
//void Write_TCM_OutputSpeed_OSS();
//void Write_TCM_FluidTemp_TFT();


/* Lecturas de sensores (valor crudo ADC 12 bits) */
void TCM_Read_OutputSpeedSensor(void);
void TCM_Read_FluidTempSensor(void);
void TCM_Read_TurbineSpeedSensor(void);




#endif /* IOHWAB_ADC_H */
