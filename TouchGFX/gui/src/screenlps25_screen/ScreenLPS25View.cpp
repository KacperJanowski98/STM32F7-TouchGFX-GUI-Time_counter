#include <gui/screenlps25_screen/ScreenLPS25View.hpp>
#include "string.h"

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

void ScreenLPS25View::lps25hbMsgRdy(LPS25HB_Result_t &result)
{
	if ((20400+(int32_t)Measure.temperature)<0)
		Unicode::snprintf(textAreaTempBuffer, TEXTAREATEMP_SIZE, "-%d.%d", result.result1T, result.result2T);
	else
		Unicode::snprintf(textAreaTempBuffer, TEXTAREATEMP_SIZE, "%d.%d", result.result1T, result.result2T);

	Unicode::snprintf(textAreaPresBuffer, TEXTAREAPRES_SIZE, "%d.%d", result.result1P, result.result2P);

	textAreaTemp.invalidate();
	textAreaPres.invalidate();
}
