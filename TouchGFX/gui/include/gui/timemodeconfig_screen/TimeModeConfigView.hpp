#ifndef TIMEMODECONFIGVIEW_HPP
#define TIMEMODECONFIGVIEW_HPP

#include <gui_generated/timemodeconfig_screen/TimeModeConfigViewBase.hpp>
#include <gui/timemodeconfig_screen/TimeModeConfigPresenter.hpp>

class TimeModeConfigView : public TimeModeConfigViewBase
{
public:
    TimeModeConfigView();
    virtual ~TimeModeConfigView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TIMEMODECONFIGVIEW_HPP
