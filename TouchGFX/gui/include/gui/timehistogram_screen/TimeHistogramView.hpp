#ifndef TIMEHISTOGRAMVIEW_HPP
#define TIMEHISTOGRAMVIEW_HPP

#include <gui_generated/timehistogram_screen/TimeHistogramViewBase.hpp>
#include <gui/timehistogram_screen/TimeHistogramPresenter.hpp>

//extern ResultStampsCalc_t ResultCalcStampsTime;
//extern ResultTime_t ResultTimeBackend;
//extern TimeMode_t TimeBackend;

extern CalcStampParam_t tempParam;
extern uint16_t tempStampsNumber;
extern float tempMaxRange;
extern uint8_t numberTiGraph;
extern uint8_t colorGraphR;
extern uint8_t colorGraphG;
extern uint8_t colorGraphB;
extern Unit_t unitGraph;
extern uint8_t stateFlag;

class TimeHistogramView : public TimeHistogramViewBase
{
public:
    TimeHistogramView();
    virtual ~TimeHistogramView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void DisplayGraph1();
    virtual void DisplayGraph2();
    virtual void DisplayGraph3();
    virtual void DisplayGraph4();
    virtual void DisplayGraph5();
    virtual void DisplayGraph6();
    virtual void DisplayGraph7();
protected:

    /**
     * @brief Funkcja okreslajaca zakres wykresu (os Y).
     * 
     * @param ti Struktura z konfiguracja relacji czasowych.
     * @param pMaxRange Wartosc zakresu wykresu.
     */
    void calculateMaxVal(TimeTi_t ti, float *pMaxRange);

    void setUnitTime(Unit_t unit, char *buffer);
};

#endif // TIMEHISTOGRAMVIEW_HPP
