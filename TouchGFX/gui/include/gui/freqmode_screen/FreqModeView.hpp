#ifndef FREQMODEVIEW_HPP
#define FREQMODEVIEW_HPP

#include <gui_generated/freqmode_screen/FreqModeViewBase.hpp>
#include <gui/freqmode_screen/FreqModePresenter.hpp>
#include <touchgfx/Color.hpp>

class FreqModeView : public FreqModeViewBase
{
public:
    FreqModeView();
    virtual ~FreqModeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void ResetParameter();

    virtual void updateUIContinuousFreq();
protected:
    void calculateFormatMeanFreq(float mean, int *pTotal, int *pFrac1, int *pFrac2);
    void calculateFormatStdDevFreq(float stdDev, int *pTotal, int *pFrac);

    void setLabelFreq(touchgfx::Unicode::UnicodeChar *textBuffer, uint16_t size, uint8_t numberCh, touchgfx::TextAreaWithOneWildcard *text);
    void setLabelColorFreq(bool channelState, touchgfx::TextArea *label, touchgfx::TextArea *labelStart);
    void setSampleFreq(FreqChannel_t *pFreqCh, touchgfx::TextAreaWithOneWildcard *textSample, touchgfx::Unicode::UnicodeChar *textSampleBuffer,
						uint16_t sizeSample, SessionSetup_t *session);
    void setMeanResultFreq(MeasFreq_t *measure, int *total, int *fraction1, int *fraction2, touchgfx::Unicode::UnicodeChar *textMeanBuffer,
    						uint16_t sizeMean, touchgfx::TextAreaWithOneWildcard *textMean, touchgfx::Unicode::UnicodeChar *textUnitMeanBuffer,
							uint16_t sizeUnitMean, touchgfx::TextAreaWithOneWildcard *textUnitMean);
    void setStdDevResultFreq(touchgfx::Unicode::UnicodeChar *textStdDevBuffer, uint16_t sizeStdDev, touchgfx::TextAreaWithOneWildcard *textStdDev,
    						touchgfx::Unicode::UnicodeChar *textUnitStdDevBuffer, uint16_t sizeUnitStdDev, touchgfx::TextAreaWithOneWildcard *textUnitStdDev,
							MeasFreq_t *measure, int *total, int *fraction);
private:
    std::string pHz;
    std::string nHz;
    std::string uHz;
    std::string mHz;
    std::string Hz;
    std::string kHz;
    std::string MHz;
    std::string GHz;

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
