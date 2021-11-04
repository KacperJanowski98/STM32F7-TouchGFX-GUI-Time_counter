#ifndef TIMEGRAPHTI1VIEW_HPP
#define TIMEGRAPHTI1VIEW_HPP

#include <gui_generated/timegraphti1_screen/TimeGraphTi1ViewBase.hpp>
#include <gui/timegraphti1_screen/TimeGraphTi1Presenter.hpp>
#include <gui/timehistogram_screen/TimeHistogramView.hpp>
#include <touchgfx/Color.hpp>

extern CalcStampParam_t tempParam;
extern uint16_t tempStampsNumber;
extern float tempMaxRange;
extern uint8_t numberTiGraph;
extern uint8_t stampsModeTimeFlag;
extern uint8_t colorGraphR;
extern uint8_t colorGraphG;
extern uint8_t colorGraphB;

class TimeGraphTi1View : public TimeGraphTi1ViewBase
{
public:
    TimeGraphTi1View();
    virtual ~TimeGraphTi1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
protected:

private:
    int tickCounter;
};

#endif // TIMEGRAPHTI1VIEW_HPP
