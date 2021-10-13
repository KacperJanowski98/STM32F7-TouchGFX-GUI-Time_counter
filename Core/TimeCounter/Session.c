/*
 * Session.c
 *
 *  Created on: 12 paź 2021
 *      Author: kacpe
 */

#include "Session.h"

void SessionInit(SessionSetup_t *pSessionSetup)
{
	pSessionSetup->maxRange = false;
    pSessionSetup->clock = INTERNAL_QUARTZ;
    pSessionSetup->repeat = 0;
    pSessionSetup->stampsNumber = 0;
    pSessionSetup->tiRange = 0;
}
