#ifndef TIMEMODEVIEW_HPP
#define TIMEMODEVIEW_HPP

#include <gui_generated/timemode_screen/TimeModeViewBase.hpp>
#include <gui/timemode_screen/TimeModePresenter.hpp>

class TimeModeView : public TimeModeViewBase
{
public:
    TimeModeView();
    virtual ~TimeModeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    void calculateFormatMeanTime(float mean, int *pTotal, int *pFrac1, int *pFrac2);
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
};

#endif // TIMEMODEVIEW_HPP
