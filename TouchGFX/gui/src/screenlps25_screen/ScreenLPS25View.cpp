#include <gui/screenlps25_screen/ScreenLPS25View.hpp>
#include "string.h"

extern int16_t temperature;

ScreenLPS25View::ScreenLPS25View()
{

}

void ScreenLPS25View::setupScreen()
{
    ScreenLPS25ViewBase::setupScreen();
}

void ScreenLPS25View::tearDownScreen()
{
    ScreenLPS25ViewBase::tearDownScreen();
}

void ScreenLPS25View::lps25hbMsgRdy(int16_t temp1, int16_t temp2, int16_t pres1, int16_t pres2)
{
	if ((20400+(int32_t)temperature)<0)
		Unicode::snprintf(textAreaTempBuffer, TEXTAREATEMP_SIZE, "-%d.%d", temp1, temp2);
	else
		Unicode::snprintf(textAreaTempBuffer, TEXTAREATEMP_SIZE, "%d.%d", temp1, temp2);

	Unicode::snprintf(textAreaPresBuffer, TEXTAREAPRES_SIZE, "%d.%d", pres1, pres2);

	textAreaTemp.invalidate();
	textAreaPres.invalidate();
}
