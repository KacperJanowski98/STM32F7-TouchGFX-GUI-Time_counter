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

void lps25hbInit();
void lps25hb();

#ifdef __cplusplus
}
#endif

#endif /* INC_LPS25HB_H_ */
