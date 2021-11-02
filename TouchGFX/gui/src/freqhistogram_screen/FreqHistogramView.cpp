#include <gui/freqhistogram_screen/FreqHistogramView.hpp>

FreqHistogramView::FreqHistogramView()
{

}

void FreqHistogramView::setupScreen()
{
    FreqHistogramViewBase::setupScreen();
}

void FreqHistogramView::tearDownScreen()
{
    FreqHistogramViewBase::tearDownScreen();
}

void FreqHistogramView::DisplayGraphF1()
{
	numberFreqGraph = 1;
	calculateMaxValFreq(FreqBackend.Channel1, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters1;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF2()
{
	numberFreqGraph = 2;
	calculateMaxValFreq(FreqBackend.Channel2, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters2;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF3()
{
	numberFreqGraph = 3;
	calculateMaxValFreq(FreqBackend.Channel3, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters3;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF4()
{
	numberFreqGraph = 4;
	calculateMaxValFreq(FreqBackend.Channel4, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters4;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF5()
{
	numberFreqGraph = 5;
	calculateMaxValFreq(FreqBackend.Channel5, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters5;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF6()
{
	numberFreqGraph = 6;
	calculateMaxValFreq(FreqBackend.Channel6, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters6;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF7()
{
	numberFreqGraph = 7;
	calculateMaxValFreq(FreqBackend.Channel7, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters7;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF8()
{
	numberFreqGraph = 8;
	calculateMaxValFreq(FreqBackend.Channel8, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters8;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::calculateMaxValFreq(FreqChannel_t freqCh, float *pMaxRange)
{
	switch (freqCh.numberChanel)
	{
	case 1:
		*pMaxRange = 8.0f;
		break;
	case 2:
		*pMaxRange = 16.0f;
		break;
	case 3:
		*pMaxRange = 54.0f;
		break;
	case 4:
		*pMaxRange = 34.0f;
		break;
	case 5:
		*pMaxRange = 52.0f;
		break;
	case 6:
		*pMaxRange = 30.0f;
		break;
	case 7:
		*pMaxRange = 52.0f;
		break;
	case 8:
		*pMaxRange = 10.0f;
		break;
	default:
		*pMaxRange = 40.0f;
		break;
	}
}
