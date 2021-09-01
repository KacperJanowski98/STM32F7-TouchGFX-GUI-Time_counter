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
    currentValue = calibrationProgress.getValue();
    calibrationProgress.getRange(min, max);

    if (currentValue == min)
    {
        increase = true;
    }
    else if (currentValue == max)
    {
        application().gotoScreenLPS25ScreenNoTransition();
    }

    nextValue = increase == true ? currentValue + 1 : currentValue - 1;

    if (nextValue == 20 || nextValue == 38 || nextValue == 70 || nextValue == 92)
    {
    	osDelay(1000);
    }

    calibrationProgress.setValue(nextValue);
}
