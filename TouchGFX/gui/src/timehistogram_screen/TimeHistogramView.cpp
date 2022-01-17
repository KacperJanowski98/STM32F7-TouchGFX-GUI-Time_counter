#include <gui/timehistogram_screen/TimeHistogramView.hpp>

TimeHistogramView::TimeHistogramView()
{

}

void TimeHistogramView::setupScreen()
{
    TimeHistogramViewBase::setupScreen();
}

void TimeHistogramView::tearDownScreen()
{
    TimeHistogramViewBase::tearDownScreen();
}

void TimeHistogramView::DisplayGraph1()
{
	numberTiGraph = 1;
	colorGraphR = 116;
	colorGraphG = 242;
	colorGraphB = 145;
	unitGraph = DataExchange.ResultTimeData.measure1.meanUnit;
	stateFlag = DataExchange.TimeData.TiSetup1.tiState;
	calculateMaxVal(DataExchange.TimeData.TiSetup1, &tempMaxRange);
	tempParam = DataExchange.ResultCalcStampsTime.parameters1;
	tempStampsNumber = DataExchange.TimeData.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph2()
{
	numberTiGraph = 2;
	colorGraphR = 200;
	colorGraphG = 242;
	colorGraphB = 116;
	stateFlag = DataExchange.TimeData.TiSetup2.tiState;
	unitGraph = DataExchange.ResultTimeData.measure2.meanUnit;
	calculateMaxVal(DataExchange.TimeData.TiSetup2, &tempMaxRange);
	tempParam = DataExchange.ResultCalcStampsTime.parameters2;
	tempStampsNumber = DataExchange.TimeData.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph3()
{
	numberTiGraph = 3;
	colorGraphR = 242;
	colorGraphG = 208;
	colorGraphB = 116;
	stateFlag = DataExchange.TimeData.TiSetup3.tiState;
	unitGraph = DataExchange.ResultTimeData.measure3.meanUnit;
	calculateMaxVal(DataExchange.TimeData.TiSetup3, &tempMaxRange);
	tempParam = DataExchange.ResultCalcStampsTime.parameters3;
	tempStampsNumber = DataExchange.TimeData.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph4()
{
	numberTiGraph = 4;
	colorGraphR = 242;
	colorGraphG = 128;
	colorGraphB = 116;
	stateFlag = DataExchange.TimeData.TiSetup4.tiState;
	unitGraph = DataExchange.ResultTimeData.measure4.meanUnit;
	calculateMaxVal(DataExchange.TimeData.TiSetup4, &tempMaxRange);
	tempParam = DataExchange.ResultCalcStampsTime.parameters4;
	tempStampsNumber = DataExchange.TimeData.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph5()
{
	numberTiGraph = 5;
	colorGraphR = 116;
	colorGraphG = 225;
	colorGraphB = 242;
	stateFlag = DataExchange.TimeData.TiSetup5.tiState;
	unitGraph = DataExchange.ResultTimeData.measure5.meanUnit;
	calculateMaxVal(DataExchange.TimeData.TiSetup5, &tempMaxRange);
	tempParam = DataExchange.ResultCalcStampsTime.parameters5;
	tempStampsNumber = DataExchange.TimeData.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph6()
{
	numberTiGraph = 6;
	colorGraphR = 116;
	colorGraphG = 145;
	colorGraphB = 242;
	stateFlag = DataExchange.TimeData.TiSetup6.tiState;
	unitGraph = DataExchange.ResultTimeData.measure6.meanUnit;
	calculateMaxVal(DataExchange.TimeData.TiSetup6, &tempMaxRange);
	tempParam = DataExchange.ResultCalcStampsTime.parameters6;
	tempStampsNumber = DataExchange.TimeData.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph7()
{
	numberTiGraph = 7;
	colorGraphR = 179;
	colorGraphG = 116;
	colorGraphB = 242;
	stateFlag = DataExchange.TimeData.TiSetup7.tiState;
	unitGraph = DataExchange.ResultTimeData.measure7.meanUnit;
	calculateMaxVal(DataExchange.TimeData.TiSetup7, &tempMaxRange);
	tempParam = DataExchange.ResultCalcStampsTime.parameters7;
	tempStampsNumber = DataExchange.TimeData.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::calculateMaxVal(TimeTi_t ti, float *pMaxRange)
{
	int distance = ti.stopIn - ti.startIn;
	switch (abs(distance))
	{
	case 1:
		*pMaxRange = 48.0f;
		break;
	case 2:
		*pMaxRange = 8.0f;
		break;
	case 3:
		*pMaxRange = 22.0f;
		break;
	case 4:
		*pMaxRange = 102.0f;
		break;
	case 5:
		*pMaxRange = 8.0f;
		break;
	case 6:
		*pMaxRange = 12.0f;
		break;
	case 7:
		*pMaxRange = 104.0f;
		break;
	default:
		*pMaxRange = 40.0f;
		break;
	}
}
