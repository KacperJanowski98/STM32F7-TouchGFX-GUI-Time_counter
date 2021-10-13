/*
 * Session.h
 *
 *  Created on: 12 paź 2021
 *      Author: kacpe
 */

#ifndef TIMECOUNTER_SESSION_H_
#define TIMECOUNTER_SESSION_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef enum
{
    INTERNAL_QUARTZ = 1,
    INTERNAL_RUBID = 2,
    EXTERNAL = 3
} Clock_t;

typedef enum
{
    UP = 1,
    DOWN = 2
} Slope_t;

typedef enum
{
    PICO = 1,
    NANO = 2,
    MICRO = 3,
    MILLI = 4
} Unit_t;

typedef struct
{
	bool maxRange;
    Clock_t clock;
    uint16_t tiRange;
    uint16_t stampsNumber;
    uint16_t repeat;
} SessionSetup_t;

void SessionInit(SessionSetup_t *pSessionSetup);

#endif /* TIMECOUNTER_SESSION_H_ */