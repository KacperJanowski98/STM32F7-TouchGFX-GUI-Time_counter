#ifndef SCREENLPS25PRESENTER_HPP
#define SCREENLPS25PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenLPS25View;

class ScreenLPS25Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenLPS25Presenter(ScreenLPS25View& v);

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

    virtual ~ScreenLPS25Presenter() {};

    virtual void lps25hbMsgRdy(LPS25HB_Result_t &result);

private:
    ScreenLPS25Presenter();

    ScreenLPS25View& view;
};

#endif // SCREENLPS25PRESENTER_HPP
