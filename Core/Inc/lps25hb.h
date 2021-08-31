/*
 * lps25hb.h
 *
 *  Created on: Aug 26, 2021
 *      Author: Kacper Janowski
 */

#ifndef INC_LPS25HB_H_
#define INC_LPS25HB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdio.h"
#include "stdlib.h"
#include "stm32f7xx_hal.h"
#include "cmsis_os.h"
#include "cmsis_os2.h"
#include "lps25hb_spi_lib.h"

typedef struct {
	int16_t result1T;
	int16_t result2T;
	int16_t result1P;
	int16_t result2P;
} LPS25HB_Result_t;

typedef struct {
	int32_t pressure;
	int16_t temperature;
} LPS25HB_measurement_t;

void lps25hbInit(LPS25HB_measurement_t *hMeasure, LPS25HB_Result_t *hResult, LPS25_ODR_TypeDef odrReg, LPS25_SPIMode_TypeDef SPIMode);
void lps25hb(LPS25HB_measurement_t *hMeasure, LPS25HB_Result_t *hResult);

#ifdef __cplusplus
}
#endif

#endif /* INC_LPS25HB_H_ */
