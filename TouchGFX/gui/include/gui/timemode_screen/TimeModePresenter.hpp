#ifndef TIMEMODEPRESENTER_HPP
#define TIMEMODEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TimeModeView;

class TimeModePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TimeModePresenter(TimeModeView& v);

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

    virtual ~TimeModePresenter() {};

private:
    TimeModePresenter();

    TimeModeView& view;
};

#endif // TIMEMODEPRESENTER_HPP
