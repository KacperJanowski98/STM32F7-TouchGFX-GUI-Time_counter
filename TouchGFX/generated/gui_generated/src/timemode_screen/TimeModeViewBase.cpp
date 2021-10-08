/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/timemode_screen/TimeModeViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

TimeModeViewBase::TimeModeViewBase() :
    buttonCallback(this, &TimeModeViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxBackgroundTime.setPosition(0, 0, 800, 480);
    boxBackgroundTime.setColor(touchgfx::Color::getColorFromRGB(56, 69, 120));

    buttonBackMenuT.setXY(740, 0);
    buttonBackMenuT.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    buttonBackMenuT.setAction(buttonCallback);

    buttonConfig.setXY(630, 420);
    buttonConfig.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfig.setAction(buttonCallback);

    buttonReset.setXY(447, 420);
    buttonReset.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));

    add(__background);
    add(boxBackgroundTime);
    add(buttonBackMenuT);
    add(buttonConfig);
    add(buttonReset);
}

void TimeModeViewBase::setupScreen()
{

}

void TimeModeViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonBackMenuT)
    {
        //BackToMenu
        //When buttonBackMenuT clicked change screen to Menu
        //Go to Menu with screen transition towards East
        application().gotoMenuScreenSlideTransitionEast();
    }
    else if (&src == &buttonConfig)
    {
        //GoToConfigTime
        //When buttonConfig clicked change screen to TimeModeConfig
        //Go to TimeModeConfig with no screen transition
        application().gotoTimeModeConfigScreenNoTransition();
    }
}
