#include <gui/screencalibration_screen/ScreenCalibrationView.hpp>

ScreenCalibrationView::ScreenCalibrationView()
{

}

void ScreenCalibrationView::setupScreen()
{
    ScreenCalibrationViewBase::setupScreen();
}

void ScreenCalibrationView::tearDownScreen()
{
    ScreenCalibrationViewBase::tearDownScreen();
}

void ScreenCalibrationView::handleTickEvent()
{
    int currentValue = calibrationProgress.getValue();
    calibrationProgress.getRange(min, max);

    if (currentValue == min)
    {
        increase = true;
    }
    else if (currentValue == max)
    {
        application().gotoScreenLPS25ScreenNoTransition();
    }

    int nextValue = increase == true ? currentValue + 1 : currentValue - 1;

    calibrationProgress.setValue(nextValue);
}
