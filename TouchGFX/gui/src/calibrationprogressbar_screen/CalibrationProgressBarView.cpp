#include <gui/calibrationprogressbar_screen/CalibrationProgressBarView.hpp>

CalibrationProgressBarView::CalibrationProgressBarView()
{

}

void CalibrationProgressBarView::setupScreen()
{
    CalibrationProgressBarViewBase::setupScreen();
    randPause1 = (rand() % (23 + 1 - 18)) + 18;
    randPause2 = (rand() % (37 + 1 - 32)) + 32;
    randPause3 = (rand() % (73 + 1 - 68)) + 68;
    randPause4 = (rand() % (93 + 1 - 86)) + 86;
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

    if (nextValue == randPause1 || nextValue == randPause2 || nextValue == randPause3 || nextValue == randPause4)
    {
    	osDelay(1000);
    }

    calibrationProgress.setValue(nextValue);
    Unicode::snprintf(textAreaValueBuffer, TEXTAREAVALUE_SIZE, "%d", nextValue);
    textAreaValue.invalidate();
}
