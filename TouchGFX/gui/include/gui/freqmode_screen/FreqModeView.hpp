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
protected:
};

#endif // FREQMODEVIEW_HPP
