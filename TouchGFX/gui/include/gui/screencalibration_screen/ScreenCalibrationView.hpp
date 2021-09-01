#ifndef SCREENCALIBRATIONVIEW_HPP
#define SCREENCALIBRATIONVIEW_HPP

#include <gui_generated/screencalibration_screen/ScreenCalibrationViewBase.hpp>
#include <gui/screencalibration_screen/ScreenCalibrationPresenter.hpp>

class ScreenCalibrationView : public ScreenCalibrationViewBase
{
public:
    ScreenCalibrationView();
    virtual ~ScreenCalibrationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    bool increase = true;
    int max;
    int min;
};

#endif // SCREENCALIBRATIONVIEW_HPP
