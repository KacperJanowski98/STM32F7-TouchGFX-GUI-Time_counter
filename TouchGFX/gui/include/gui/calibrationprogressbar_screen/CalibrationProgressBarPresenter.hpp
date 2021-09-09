#ifndef CALIBRATIONPROGRESSBARPRESENTER_HPP
#define CALIBRATIONPROGRESSBARPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class CalibrationProgressBarView;

class CalibrationProgressBarPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    CalibrationProgressBarPresenter(CalibrationProgressBarView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~CalibrationProgressBarPresenter() {};

private:
    CalibrationProgressBarPresenter();

    CalibrationProgressBarView& view;
};

#endif // CALIBRATIONPROGRESSBARPRESENTER_HPP
