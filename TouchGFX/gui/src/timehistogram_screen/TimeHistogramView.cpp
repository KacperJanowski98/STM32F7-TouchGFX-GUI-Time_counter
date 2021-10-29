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
	calculateMaxVal(TimeBackend.TiSetup1, &tempMaxRange);
	tempParam = ResultCalcStampsTime.parameters1;
	tempStampsNumber = TimeBackend.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph2()
{
	numberTiGraph = 2;
	calculateMaxVal(TimeBackend.TiSetup2, &tempMaxRange);
	tempParam = ResultCalcStampsTime.parameters2;
	tempStampsNumber = TimeBackend.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph3()
{
	numberTiGraph = 3;
	calculateMaxVal(TimeBackend.TiSetup3, &tempMaxRange);
	tempParam = ResultCalcStampsTime.parameters3;
	tempStampsNumber = TimeBackend.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph4()
{
	numberTiGraph = 4;
	calculateMaxVal(TimeBackend.TiSetup4, &tempMaxRange);
	tempParam = ResultCalcStampsTime.parameters4;
	tempStampsNumber = TimeBackend.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph5()
{
	numberTiGraph = 5;
	calculateMaxVal(TimeBackend.TiSetup5, &tempMaxRange);
	tempParam = ResultCalcStampsTime.parameters5;
	tempStampsNumber = TimeBackend.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph6()
{
	numberTiGraph = 6;
	calculateMaxVal(TimeBackend.TiSetup6, &tempMaxRange);
	tempParam = ResultCalcStampsTime.parameters6;
	tempStampsNumber = TimeBackend.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::DisplayGraph7()
{
	numberTiGraph = 7;
	calculateMaxVal(TimeBackend.TiSetup7, &tempMaxRange);
	tempParam = ResultCalcStampsTime.parameters7;
	tempStampsNumber = TimeBackend.TimeSession.stampsNumber;
	application().gotoTimeGraphTi1ScreenWipeTransitionWest();
}

void TimeHistogramView::calculateMaxVal(TimeTi_t ti, float *pMaxRange)
{
	int distance = ti.stopIn - ti.startIn;
	switch (distance)
	{
	case 1:
		*pMaxRange = 54.0f;
		break;
	case 2:
		*pMaxRange = 10.0f;
		break;
	case 3:
		*pMaxRange = 28.0f;
		break;
	case 4:
		*pMaxRange = 104.0f;
		break;
	case 5:
		*pMaxRange = 8.0f;
		break;
	case 6:
		*pMaxRange = 14.0f;
		break;
	case 7:
		*pMaxRange = 104.0f;
		break;
	default:
		*pMaxRange = 40.0f;
		break;
	}
}