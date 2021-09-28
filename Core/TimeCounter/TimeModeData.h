/*
 * TimeModeData.h
 *
 *  Created on: 28 wrz 2021
 *      Author: kacpe
 */

#ifndef INC_TIMEMODEDATA_H_
#define INC_TIMEMODEDATA_H_

typedef struct {
	uint8_t startIn;
	uint8_t stopIn;
	uint16_t stampsNumber;
	uint16_t stampleNumber;
	// mean float or double or uint?
	// stdDev float or double or uint?
}TimeMode_t;

#endif /* INC_TIMEMODEDATA_H_ */
