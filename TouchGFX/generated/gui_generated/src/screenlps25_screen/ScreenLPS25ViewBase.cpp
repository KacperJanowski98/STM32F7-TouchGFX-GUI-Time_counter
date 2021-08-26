/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screenlps25_screen/ScreenLPS25ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

ScreenLPS25ViewBase::ScreenLPS25ViewBase() :
    buttonCallback(this, &ScreenLPS25ViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(64, 62, 62));

    buttonLPS25.setXY(595, 392);
    buttonLPS25.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonLPS25.setAction(buttonCallback);

    textAreaTemp.setPosition(90, 93, 550, 38);
    textAreaTemp.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTemp.setLinespacing(0);
    textAreaTempBuffer[0] = 0;
    textAreaTemp.setWildcard(textAreaTempBuffer);
    textAreaTemp.setTypedText(touchgfx::TypedText(T_SINGLEUSEID1));

    textAreaPres.setPosition(90, 138, 550, 40);
    textAreaPres.setColor(touchgfx::Color::getColorFromRGB(245, 245, 245));
    textAreaPres.setLinespacing(0);
    textAreaPres.setTypedText(touchgfx::TypedText(T_SINGLEUSEID2));

    add(__background);
    add(box1);
    add(buttonLPS25);
    add(textAreaTemp);
    add(textAreaPres);
}

void ScreenLPS25ViewBase::setupScreen()
{

}

void ScreenLPS25ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonLPS25)
    {
        //ChangeLPS25Screen
        //When buttonLPS25 clicked change screen to Screen1
        //Go to Screen1 with screen transition towards East
        application().gotoScreen1ScreenCoverTransitionEast();
    }
}
