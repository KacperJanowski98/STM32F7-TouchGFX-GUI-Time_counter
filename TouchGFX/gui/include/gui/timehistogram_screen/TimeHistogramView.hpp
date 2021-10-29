#ifndef TIMEHISTOGRAMVIEW_HPP
#define TIMEHISTOGRAMVIEW_HPP

#include <gui_generated/timehistogram_screen/TimeHistogramViewBase.hpp>
#include <gui/timehistogram_screen/TimeHistogramPresenter.hpp>

extern ResultStampsCalc_t ResultCalcStampsTime;
extern TimeMode_t TimeBackend;

extern CalcStampParam_t tempParam;
extern uint16_t tempStampsNumber;
extern float tempMaxRange;
extern uint8_t numberTiGraph;

class TimeHistogramView : public TimeHistogramViewBase
{
public:
    TimeHistogramView();
    virtual ~TimeHistogramView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void DisplayGraph2();
protected:
    void calculateMaxVal(TimeTi_t ti, float *pMaxRange);
};

#endif // TIMEHISTOGRAMVIEW_HPP
