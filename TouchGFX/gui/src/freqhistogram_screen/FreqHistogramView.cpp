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
	colorGraphR = 200;
	colorGraphG = 168;
	colorGraphB = 206;
	calculateMaxValFreq(FreqBackend.Channel1, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters1;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF2()
{
	numberFreqGraph = 2;
	colorGraphR = 163;
	colorGraphG = 148;
	colorGraphB = 206;
	calculateMaxValFreq(FreqBackend.Channel2, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters2;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF3()
{
	numberFreqGraph = 3;
	colorGraphR = 148;
	colorGraphG = 165;
	colorGraphB = 206;
	calculateMaxValFreq(FreqBackend.Channel3, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters3;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF4()
{
	numberFreqGraph = 4;
	colorGraphR = 146;
	colorGraphG = 204;
	colorGraphB = 210;
	calculateMaxValFreq(FreqBackend.Channel4, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters4;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF5()
{
	numberFreqGraph = 5;
	colorGraphR = 127;
	colorGraphG = 213;
	colorGraphB = 179;
	calculateMaxValFreq(FreqBackend.Channel5, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters5;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF6()
{
	numberFreqGraph = 6;
	colorGraphR = 135;
	colorGraphG = 213;
	colorGraphB = 127;
	calculateMaxValFreq(FreqBackend.Channel6, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters6;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF7()
{
	numberFreqGraph = 7;
	colorGraphR = 229;
	colorGraphG = 225;
	colorGraphB = 106;
	calculateMaxValFreq(FreqBackend.Channel7, &tempMaxRangeF);
	tempParamF = ResultCalcStampsFreq.parameters7;
	tempStampsNumberF = FreqBackend.FreqSession.stampsNumber;
	application().gotoFreqGraphScreenWipeTransitionWest();
}

void FreqHistogramView::DisplayGraphF8()
{
	numberFreqGraph = 8;
	colorGraphR = 246;
	colorGraphG = 177;
	colorGraphB = 108;
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
