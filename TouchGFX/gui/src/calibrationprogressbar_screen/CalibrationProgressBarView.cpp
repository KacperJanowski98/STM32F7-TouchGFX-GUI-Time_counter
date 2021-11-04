#include <gui/calibrationprogressbar_screen/CalibrationProgressBarView.hpp>

CalibrationProgressBarView::CalibrationProgressBarView()
{

}

void CalibrationProgressBarView::setupScreen()
{
    CalibrationProgressBarViewBase::setupScreen();
}

void CalibrationProgressBarView::tearDownScreen()
{
    CalibrationProgressBarViewBase::tearDownScreen();
}

void CalibrationProgressBarView::handleTickEvent()
{
    int currentValue = calibrationProgress.getValue();
    calibrationProgress.getRange(min, max);

    if (currentValue == min)
    {
        increase = true;
    }
    else if (currentValue == max)
    {
        application().gotoMenuScreenSlideTransitionEast();
    }

    int nextValue = increase == true ? currentValue + 1 : currentValue - 1;

    if (nextValue == 21 || nextValue == 34 || nextValue == 71 || nextValue == 93)
    {
    	osDelay(1000);
    }

    calibrationProgress.setValue(nextValue);
    Unicode::snprintf(textAreaValueBuffer, TEXTAREAVALUE_SIZE, "%d", nextValue);
    textAreaValue.invalidate();
}
