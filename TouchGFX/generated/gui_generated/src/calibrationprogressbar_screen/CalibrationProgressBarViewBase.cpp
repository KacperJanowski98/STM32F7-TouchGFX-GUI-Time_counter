/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/calibrationprogressbar_screen/CalibrationProgressBarViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

CalibrationProgressBarViewBase::CalibrationProgressBarViewBase()
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    backgroundCalibration.setPosition(0, 0, 800, 480);
    backgroundCalibration.setColor(touchgfx::Color::getColorFromRGB(49, 64, 82));

    calibrationProgress.setXY(348, 221);
    calibrationProgress.setProgressIndicatorPosition(0, 0, 104, 104);
    calibrationProgress.setRange(0, 100);
    calibrationProgress.setCenter(52, 52);
    calibrationProgress.setRadius(50);
    calibrationProgress.setLineWidth(0);
    calibrationProgress.setStartEndAngle(0, 360);
    calibrationProgress.setBackground(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_CIRCLE_INDICATOR_BG_LINE_FULL_ID));
    calibrationProgressPainter.setBitmap(touchgfx::Bitmap(BITMAP_MY_BLUE_PROGRESSINDICATORS_FILL_MEDIUM_CIRCLE_INDICATOR_FILL_LINE_FULL_ID));
    calibrationProgress.setPainter(calibrationProgressPainter);
    calibrationProgress.setValue(0);

    textLabelName.setXY(312, 62);
    textLabelName.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelName.setLinespacing(0);
    textLabelName.setTypedText(touchgfx::TypedText(T_SINGLEUSEID275));

    textLabelDescription.setXY(209, 153);
    textLabelDescription.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelDescription.setLinespacing(0);
    textLabelDescription.setTypedText(touchgfx::TypedText(T_SINGLEUSEID276));

    add(__background);
    add(backgroundCalibration);
    add(calibrationProgress);
    add(textLabelName);
    add(textLabelDescription);
}

void CalibrationProgressBarViewBase::setupScreen()
{

    //Interaction1
    //When screen transition begins change screen to Menu
    //Go to Menu with screen transition towards East
    application().gotoMenuScreenSlideTransitionEast();

}
