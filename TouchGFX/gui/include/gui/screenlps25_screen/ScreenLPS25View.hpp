#ifndef SCREENLPS25VIEW_HPP
#define SCREENLPS25VIEW_HPP

#include <gui_generated/screenlps25_screen/ScreenLPS25ViewBase.hpp>
#include <gui/screenlps25_screen/ScreenLPS25Presenter.hpp>

class ScreenLPS25View : public ScreenLPS25ViewBase
{
public:
    ScreenLPS25View();
    virtual ~ScreenLPS25View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void lps25hbMsgRdy(LPS25HB_Result_t &result);
protected:
};

#endif // SCREENLPS25VIEW_HPP
