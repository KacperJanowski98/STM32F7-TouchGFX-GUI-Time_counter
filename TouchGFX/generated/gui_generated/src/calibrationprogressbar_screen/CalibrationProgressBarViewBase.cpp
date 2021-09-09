/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/calibrationprogressbar_screen/CalibrationProgressBarViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

CalibrationProgressBarViewBase::CalibrationProgressBarViewBase()
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    backgroundCalibration.setPosition(0, 0, 800, 480);
    backgroundCalibration.setColor(touchgfx::Color::getColorFromRGB(50, 51, 66));

    calibrationProgress.setXY(348, 188);
    calibrationProgress.setProgressIndicatorPosition(0, 0, 104, 104);
    calibrationProgress.setRange(0, 100);
    calibrationProgress.setCenter(52, 52);
    calibrationProgress.setRadius(50);
    calibrationProgress.setLineWidth(0);
    calibrationProgress.setStartEndAngle(0, 360);
    calibrationProgress.setBackground(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_CIRCLE_INDICATOR_BG_LINE_FULL_ID));
    calibrationProgressPainter.setBitmap(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_FILL_MEDIUM_CIRCLE_INDICATOR_FILL_LINE_FULL_ID));
    calibrationProgress.setPainter(calibrationProgressPainter);
    calibrationProgress.setValue(0);

    add(__background);
    add(backgroundCalibration);
    add(calibrationProgress);
}

void CalibrationProgressBarViewBase::setupScreen()
{

    //Interaction1
    //When screen transition begins change screen to Screen1
    //Go to Screen1 with screen transition towards East
    application().gotoScreen1ScreenSlideTransitionEast();

}