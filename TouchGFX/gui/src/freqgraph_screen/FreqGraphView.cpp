#include <gui/freqgraph_screen/FreqGraphView.hpp>

FreqGraphView::FreqGraphView()
{
	tickCounterF = 0;
}

void FreqGraphView::setupScreen()
{
	Unicode::snprintf(textLabelBuffer, TEXTLABEL_SIZE, "%d", numberFreqGraph);
	textLabel.invalidate();
	switch (unitGraph)
	{
	case GIGA:
		Unicode::strncpy(textAreaLabelYBuffer, (char*)"GHz", TEXTAREALABELY_SIZE - 1);
		break;
	case MEGA:
		Unicode::strncpy(textAreaLabelYBuffer, (char*)"MHZ", TEXTAREALABELY_SIZE - 1);
		break;
	case KILO:
		Unicode::strncpy(textAreaLabelYBuffer, (char*)"kHz", TEXTAREALABELY_SIZE - 1);
		break;
	case HZ:
		Unicode::strncpy(textAreaLabelYBuffer, (char*)"Hz", TEXTAREALABELY_SIZE - 1);
		break;
	default:
		Unicode::strncpy(textAreaLabelYBuffer, (char*)"kHz", TEXTAREALABELY_SIZE - 1);
		break;
	}
    FreqGraphViewBase::setupScreen();
    dynamicGraphFreq.clear();
    dynamicGraphFreqHistogram1.setColor(touchgfx::Color::getColorFrom24BitRGB(colorGraphR, colorGraphG, colorGraphB));
    dynamicGraphFreq.setGraphRangeY(0.0f, tempMaxRangeF);
    dynamicGraphFreq.invalidate();
}

void FreqGraphView::tearDownScreen()
{
    FreqGraphViewBase::tearDownScreen();
}

void FreqGraphView::handleTickEvent()
{
	if (tickCounterF < tempStampsNumberF && stampsModeFreqFlag == 1)
	{
		dynamicGraphFreq.addDataPoint(tempParamF.measureBuffer[tickCounterF]);
	}
	dynamicGraphFreq.invalidate();
	tickCounterF++;
	osDelay(100);
}
