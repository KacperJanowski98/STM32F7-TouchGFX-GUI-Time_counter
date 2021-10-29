#ifndef TIMEGRAPHTI1PRESENTER_HPP
#define TIMEGRAPHTI1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TimeGraphTi1View;

class TimeGraphTi1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    TimeGraphTi1Presenter(TimeGraphTi1View& v);

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

    virtual ~TimeGraphTi1Presenter() {};

private:
    TimeGraphTi1Presenter();

    TimeGraphTi1View& view;
};

#endif // TIMEGRAPHTI1PRESENTER_HPP
