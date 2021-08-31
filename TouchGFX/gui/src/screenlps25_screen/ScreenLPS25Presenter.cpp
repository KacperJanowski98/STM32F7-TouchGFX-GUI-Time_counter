#include <gui/screenlps25_screen/ScreenLPS25View.hpp>
#include <gui/screenlps25_screen/ScreenLPS25Presenter.hpp>

ScreenLPS25Presenter::ScreenLPS25Presenter(ScreenLPS25View& v)
    : view(v)
{

}

void ScreenLPS25Presenter::activate()
{

}

void ScreenLPS25Presenter::deactivate()
{

}

void ScreenLPS25Presenter::lps25hbMsgRdy(LPS25HB_Result_t &result)
{
	view.lps25hbMsgRdy(result);
}
