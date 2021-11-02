#ifndef FREQHISTOGRAMVIEW_HPP
#define FREQHISTOGRAMVIEW_HPP

#include <gui_generated/freqhistogram_screen/FreqHistogramViewBase.hpp>
#include <gui/freqhistogram_screen/FreqHistogramPresenter.hpp>

class FreqHistogramView : public FreqHistogramViewBase
{
public:
    FreqHistogramView();
    virtual ~FreqHistogramView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // FREQHISTOGRAMVIEW_HPP
