/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/menu_screen/MenuViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

MenuViewBase::MenuViewBase() :
    buttonCallback(this, &MenuViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxBackgroundMenu.setPosition(0, 0, 800, 480);
    boxBackgroundMenu.setColor(touchgfx::Color::getColorFromRGB(63, 62, 112));

    buttonFrequency.setXY(220, 297);
    buttonFrequency.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_LARGE_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_LARGE_PRESSED_ID));
    buttonFrequency.setLabelText(touchgfx::TypedText(T_SINGLEUSEID2));
    buttonFrequency.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonFrequency.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonFrequency.setAction(buttonCallback);

    buttonTime.setXY(220, 180);
    buttonTime.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_LARGE_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_LARGE_PRESSED_ID));
    buttonTime.setLabelText(touchgfx::TypedText(T_SINGLEUSEID1));
    buttonTime.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonTime.setLabelColorPressed(touchgfx::Color::getColorFromRGB(153, 153, 153));
    buttonTime.setAction(buttonCallback);

    buttonCalibration.setXY(220, 70);
    buttonCalibration.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_LARGE_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_LARGE_PRESSED_ID));
    buttonCalibration.setLabelText(touchgfx::TypedText(T_SINGLEUSEID13));
    buttonCalibration.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonCalibration.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonCalibration.setAction(buttonCallback);

    add(__background);
    add(boxBackgroundMenu);
    add(buttonFrequency);
    add(buttonTime);
    add(buttonCalibration);
}

void MenuViewBase::setupScreen()
{

}

void MenuViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonFrequency)
    {
        //OpenFreqMode
        //When buttonFrequency clicked change screen to FreqMode
        //Go to FreqMode with screen transition towards East
        application().gotoFreqModeScreenCoverTransitionEast();
    }
    else if (&src == &buttonTime)
    {
        //OpenTimeMode
        //When buttonTime clicked change screen to TimeMode
        //Go to TimeMode with screen transition towards East
        application().gotoTimeModeScreenCoverTransitionEast();
    }
    else if (&src == &buttonCalibration)
    {
        //OpenCalibration
        //When buttonCalibration clicked change screen to CalibrationProgressBar
        //Go to CalibrationProgressBar with screen transition towards East
        application().gotoCalibrationProgressBarScreenCoverTransitionEast();
    }
}
