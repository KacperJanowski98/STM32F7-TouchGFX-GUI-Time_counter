#ifndef FREQMODECONFIGVIEW_HPP
#define FREQMODECONFIGVIEW_HPP

#include <gui_generated/freqmodeconfig_screen/FreqModeConfigViewBase.hpp>
#include <gui/freqmodeconfig_screen/FreqModeConfigPresenter.hpp>

class FreqModeConfigView : public FreqModeConfigViewBase
{
public:
    FreqModeConfigView();
    virtual ~FreqModeConfigView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // FREQMODECONFIGVIEW_HPP
