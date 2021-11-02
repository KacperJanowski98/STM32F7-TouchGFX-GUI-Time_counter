#include <gui/freqgraph_screen/FreqGraphView.hpp>

FreqGraphView::FreqGraphView()
{
	tickCounterF = 0;
}

void FreqGraphView::setupScreen()
{
	Unicode::snprintf(textLabelBuffer, TEXTLABEL_SIZE, "%d", numberFreqGraph);
	textLabel.invalidate();
    FreqGraphViewBase::setupScreen();
    dynamicGraphFreq.clear();
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
