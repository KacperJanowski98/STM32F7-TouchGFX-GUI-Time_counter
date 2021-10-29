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

    void gotoCalibrationProgressBarScreenCoverTransitionEast();

    // Menu
    void gotoMenuScreenSlideTransitionEast();

    // TimeMode
    void gotoTimeModeScreenCoverTransitionEast();

    void gotoTimeModeScreenCoverTransitionWest();

    void gotoTimeModeScreenWipeTransitionEast();

    // TimeModeConfig
    void gotoTimeModeConfigScreenNoTransition();

    // FreqMode
    void gotoFreqModeScreenCoverTransitionEast();

    void gotoFreqModeScreenCoverTransitionWest();

    // FreqModeConfig
    void gotoFreqModeConfigScreenNoTransition();

    // TimeHistogram
    void gotoTimeHistogramScreenWipeTransitionWest();

    void gotoTimeHistogramScreenWipeTransitionEast();

    // TimeGraphTi1
    void gotoTimeGraphTi1ScreenWipeTransitionWest();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // CalibrationProgressBar
    void gotoCalibrationProgressBarScreenNoTransitionImpl();

    void gotoCalibrationProgressBarScreenCoverTransitionEastImpl();

    // Menu
    void gotoMenuScreenSlideTransitionEastImpl();

    // TimeMode
    void gotoTimeModeScreenCoverTransitionEastImpl();

    void gotoTimeModeScreenCoverTransitionWestImpl();

    void gotoTimeModeScreenWipeTransitionEastImpl();

    // TimeModeConfig
    void gotoTimeModeConfigScreenNoTransitionImpl();

    // FreqMode
    void gotoFreqModeScreenCoverTransitionEastImpl();

    void gotoFreqModeScreenCoverTransitionWestImpl();

    // FreqModeConfig
    void gotoFreqModeConfigScreenNoTransitionImpl();

    // TimeHistogram
    void gotoTimeHistogramScreenWipeTransitionWestImpl();

    void gotoTimeHistogramScreenWipeTransitionEastImpl();

    // TimeGraphTi1
    void gotoTimeGraphTi1ScreenWipeTransitionWestImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
