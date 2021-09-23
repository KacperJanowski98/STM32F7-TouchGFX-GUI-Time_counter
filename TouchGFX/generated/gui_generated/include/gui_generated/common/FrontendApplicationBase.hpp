/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    // CalibrationProgressBar
    void gotoCalibrationProgressBarScreenNoTransition();

    // Menu
    void gotoMenuScreenSlideTransitionEast();

    // TimeMode
    void gotoTimeModeScreenCoverTransitionEast();

    void gotoTimeModeScreenNoTransition();

    // TimeModeConfig
    void gotoTimeModeConfigScreenNoTransition();

    // FreqMode
    void gotoFreqModeScreenCoverTransitionEast();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // CalibrationProgressBar
    void gotoCalibrationProgressBarScreenNoTransitionImpl();

    // Menu
    void gotoMenuScreenSlideTransitionEastImpl();

    // TimeMode
    void gotoTimeModeScreenCoverTransitionEastImpl();

    void gotoTimeModeScreenNoTransitionImpl();

    // TimeModeConfig
    void gotoTimeModeConfigScreenNoTransitionImpl();

    // FreqMode
    void gotoFreqModeScreenCoverTransitionEastImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
