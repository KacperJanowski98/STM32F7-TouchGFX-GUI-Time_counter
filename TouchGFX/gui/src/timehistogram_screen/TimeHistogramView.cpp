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

void TimeHistogramView::DisplayGraph2()
{
	numberTiGraph = 2;
	calculateMaxVal(TimeBackend.TiSetup2, &tempMaxRange);
	tempParam = ResultCalcStampsTime.parameters2;
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
