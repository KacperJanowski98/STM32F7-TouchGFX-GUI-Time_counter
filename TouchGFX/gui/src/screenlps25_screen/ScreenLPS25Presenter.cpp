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

void ScreenLPS25Presenter::lps25hbMsgRdy(int16_t temp1, int16_t temp2, int16_t pres1, int16_t pres2)
{
	view.lps25hbMsgRdy(temp1, temp2, pres1, pres2);
}
