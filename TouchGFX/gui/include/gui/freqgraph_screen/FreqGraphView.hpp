#ifndef FREQGRAPHVIEW_HPP
#define FREQGRAPHVIEW_HPP

#include <gui_generated/freqgraph_screen/FreqGraphViewBase.hpp>
#include <gui/freqgraph_screen/FreqGraphPresenter.hpp>
#include <touchgfx/Color.hpp>

extern CalcStampParam_t tempParamF;
extern uint16_t tempStampsNumberF;
extern float tempMaxRangeF;
extern uint8_t numberFreqGraph;
extern uint8_t stampsModeFreqFlag;
extern uint8_t colorGraphR;
extern uint8_t colorGraphG;
extern uint8_t colorGraphB;
extern Unit_t unitGraph;

class FreqGraphView : public FreqGraphViewBase
{
public:
    FreqGraphView();
    virtual ~FreqGraphView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
protected:

private:
    int tickCounterF;
};

#endif // FREQGRAPHVIEW_HPP
