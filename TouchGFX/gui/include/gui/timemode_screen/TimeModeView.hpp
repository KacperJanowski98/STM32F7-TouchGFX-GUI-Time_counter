#ifndef TIMEMODEVIEW_HPP
#define TIMEMODEVIEW_HPP

#include <gui_generated/timemode_screen/TimeModeViewBase.hpp>
#include <gui/timemode_screen/TimeModePresenter.hpp>
#include <string.h>
#include <gui/lib/TimeModeParameter.hpp>
#include <gui/lib/SessionSetup.hpp>
#include <gui/model/Model.hpp>

class TimeModeView : public TimeModeViewBase
{
public:
    TimeModeView();
    virtual ~TimeModeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void ResetParameter();

    virtual void updateUIContinuousTime();
protected:
    void calculateFormatMeanTime(float mean, int *pTotal, int *pFrac1, int *pFrac2);
    void calculateFormatStdDevTime(float stdDev, int *pTotal, int *pFrac);

    void setLabelTi(touchgfx::Unicode::UnicodeChar *textBuffer, uint16_t size, uint8_t startIn, touchgfx::TextAreaWithOneWildcard *text);
    void setStampsSampleTi(touchgfx::Unicode::UnicodeChar *textBufferStart, uint16_t sizeStart, touchgfx::TextAreaWithOneWildcard *textStart,
			touchgfx::Unicode::UnicodeChar *textBufferStop, uint16_t sizeStop, touchgfx::TextAreaWithOneWildcard *textStop,
			touchgfx::Unicode::UnicodeChar *textBufferSample, uint16_t sizeSample, touchgfx::TextAreaWithOneWildcard *textSample,
			TimeTi_t *Ti, SessionSetup_t *session);
private:
    int m_total_ti1;
    int m_frac1_ti1;
    int m_frac2_ti1;
    int m_total_ti2;
    int m_frac1_ti2;
    int m_frac2_ti2;
    int m_total_ti3;
    int m_frac1_ti3;
    int m_frac2_ti3;
    int m_total_ti4;
    int m_frac1_ti4;
    int m_frac2_ti4;
    int m_total_ti5;
    int m_frac1_ti5;
    int m_frac2_ti5;
    int m_total_ti6;
    int m_frac1_ti6;
    int m_frac2_ti6;
    int m_total_ti7;
    int m_frac1_ti7;
    int m_frac2_ti7;
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
};

#endif // TIMEMODEVIEW_HPP
