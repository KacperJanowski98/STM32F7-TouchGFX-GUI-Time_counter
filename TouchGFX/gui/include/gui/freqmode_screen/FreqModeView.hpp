#ifndef FREQMODEVIEW_HPP
#define FREQMODEVIEW_HPP

#include <gui_generated/freqmode_screen/FreqModeViewBase.hpp>
#include <gui/freqmode_screen/FreqModePresenter.hpp>

class FreqModeView : public FreqModeViewBase
{
public:
    FreqModeView();
    virtual ~FreqModeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void ResetParameter();

protected:
    void calculateFormatMeanFreq(float mean, int *pTotal, int *pFrac1, int *pFrac2);
    void calculateFormatStdDevFreq(float stdDev, int *pTotal, int *pFrac);
private:
    int m_total_freq1;
    int m_frac1_freq1;
    int m_frac2_freq1;
    int m_total_freq2;
    int m_frac1_freq2;
    int m_frac2_freq2;
    int m_total_freq3;
    int m_frac1_freq3;
    int m_frac2_freq3;
    int m_total_freq4;
    int m_frac1_freq4;
    int m_frac2_freq4;
    int m_total_freq5;
    int m_frac1_freq5;
    int m_frac2_freq5;
    int m_total_freq6;
    int m_frac1_freq6;
    int m_frac2_freq6;
    int m_total_freq7;
    int m_frac1_freq7;
    int m_frac2_freq7;
    int m_total_freq8;
    int m_frac1_freq8;
    int m_frac2_freq8;
    int m_totalStdDev1;
    int m_fracStdDev1;
    int m_totalStdDev2;
    int m_fracStdDev2;
    int m_totalStdDev3;
    int m_fracStdDev3;
    int m_totalStdDev4;
    int m_fracStdDev4;
    int m_totalStdDev5;
    int m_fracStdDev5;
    int m_totalStdDev6;
    int m_fracStdDev6;
    int m_totalStdDev7;
    int m_fracStdDev7;
    int m_totalStdDev8;
    int m_fracStdDev8;
};

#endif // FREQMODEVIEW_HPP
