#include <gui/timegraphti1_screen/TimeGraphTi1View.hpp>

TimeGraphTi1View::TimeGraphTi1View()
{
	tickCounter = 0;
}

void TimeGraphTi1View::setupScreen()
{
	Unicode::snprintf(textLabelBuffer, TEXTLABEL_SIZE, "%d", numberTiGraph);
	textLabel.invalidate();
    TimeGraphTi1ViewBase::setupScreen();
    dynamicGraph1.clear();
    dynamicGraph1Histogram1.setColor(touchgfx::Color::getColorFrom24BitRGB(colorGraphR, colorGraphG, colorGraphB));
    dynamicGraph1.setGraphRangeY(0.0f, tempMaxRange);
    dynamicGraph1.invalidate();
}

void TimeGraphTi1View::tearDownScreen()
{
    TimeGraphTi1ViewBase::tearDownScreen();
}

void TimeGraphTi1View::handleTickEvent()
{
	if (tickCounter < tempStampsNumber && stampsModeTimeFlag == 1)
	{
		dynamicGraph1.addDataPoint(tempParam.measureBuffer[tickCounter]);
	}
	dynamicGraph1.invalidate();
	tickCounter++;
	osDelay(100);
}
