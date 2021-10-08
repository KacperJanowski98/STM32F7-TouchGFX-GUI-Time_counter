#ifndef TIMEMODECONFIGPRESENTER_HPP
#define TIMEMODECONFIGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TimeModeConfigView;

class TimeModeConfigPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TimeModeConfigPresenter(TimeModeConfigView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~TimeModeConfigPresenter() {};

    /**
     * My function
     */
    virtual void askForDataTimeSingle();

    virtual void askForDataTimeConst();

    virtual void askForDataTimeStamps();

private:
    TimeModeConfigPresenter();

    TimeModeConfigView& view;
};

#endif // TIMEMODECONFIGPRESENTER_HPP
