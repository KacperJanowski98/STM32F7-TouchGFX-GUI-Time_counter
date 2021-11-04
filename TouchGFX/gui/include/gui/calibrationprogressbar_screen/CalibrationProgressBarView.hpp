#ifndef CALIBRATIONPROGRESSBARVIEW_HPP
#define CALIBRATIONPROGRESSBARVIEW_HPP

#include <gui_generated/calibrationprogressbar_screen/CalibrationProgressBarViewBase.hpp>
#include <gui/calibrationprogressbar_screen/CalibrationProgressBarPresenter.hpp>

class CalibrationProgressBarView : public CalibrationProgressBarViewBase
{
public:
    CalibrationProgressBarView();
    virtual ~CalibrationProgressBarView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    bool increase = true;
    int max;
    int min;
    int currentValue;
    int nextValue;
    int randPause1;
    int randPause2;
    int randPause3;
    int randPause4;
};

#endif // CALIBRATIONPROGRESSBARVIEW_HPP
