/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/freqmode_screen/FreqModeViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

FreqModeViewBase::FreqModeViewBase() :
    buttonCallback(this, &FreqModeViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxBackgroungFreq.setPosition(0, 0, 800, 480);
    boxBackgroungFreq.setColor(touchgfx::Color::getColorFromRGB(13, 122, 255));

    buttonToMenuF.setXY(740, 0);
    buttonToMenuF.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    buttonToMenuF.setAction(buttonCallback);

    buttonConfig.setXY(630, 420);
    buttonConfig.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfig.setAction(buttonCallback);

    add(__background);
    add(boxBackgroungFreq);
    add(buttonToMenuF);
    add(buttonConfig);
}

void FreqModeViewBase::setupScreen()
{

}

void FreqModeViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonToMenuF)
    {
        //BackToMenu
        //When buttonToMenuF clicked change screen to Menu
        //Go to Menu with screen transition towards East
        application().gotoMenuScreenSlideTransitionEast();
    }
    else if (&src == &buttonConfig)
    {
        //GoToConfigFreq
        //When buttonConfig clicked change screen to FreqModeConfig
        //Go to FreqModeConfig with no screen transition
        application().gotoFreqModeConfigScreenNoTransition();
    }
}