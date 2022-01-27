#ifndef FREQHISTOGRAMVIEW_HPP
#define FREQHISTOGRAMVIEW_HPP

#include <gui_generated/freqhistogram_screen/FreqHistogramViewBase.hpp>
#include <gui/freqhistogram_screen/FreqHistogramPresenter.hpp>

//extern FrequencyMode_t FreqBackend;
//extern ResultStampsCalcFreq_t ResultCalcStampsFreq;
extern DataExchange_t DataExchange;
//extern ResultFreq_t ResultFreqBackend;

extern CalcStampParam_t tempParamF;
extern uint16_t tempStampsNumberF;
extern float tempMaxRangeF;
extern uint8_t numberFreqGraph;
extern uint8_t colorGraphR;
extern uint8_t colorGraphG;
extern uint8_t colorGraphB;
extern Unit_t unitGraph;
extern uint8_t stateFlag;

class FreqHistogramView : public FreqHistogramViewBase
{
public:
    FreqHistogramView();
    virtual ~FreqHistogramView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void DisplayGraphF1();
    virtual void DisplayGraphF2();
    virtual void DisplayGraphF3();
    virtual void DisplayGraphF4();
    virtual void DisplayGraphF5();
    virtual void DisplayGraphF6();
    virtual void DisplayGraphF7();
    virtual void DisplayGraphF8();
protected:

    /**
     * @brief Funkcja okreslajaca zakres wykresu (os Y).
     * 
     * @param freqCh Struktura z konfiguracja wejsc pomiarowych.
     * @param pMaxRange Wartosc zakresu wykresu.
     */
    void calculateMaxValFreq(FreqChannel_t freqCh, float *pMaxRange);
};

#endif // FREQHISTOGRAMVIEW_HPP
