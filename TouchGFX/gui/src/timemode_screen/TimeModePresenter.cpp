#include <gui/timemode_screen/TimeModeView.hpp>
#include <gui/timemode_screen/TimeModePresenter.hpp>

TimeModePresenter::TimeModePresenter(TimeModeView& v)
    : view(v)
{

}

void TimeModePresenter::activate()
{

}

void TimeModePresenter::deactivate()
{

}

void TimeModePresenter::askForReset()
{
	model->getResetTime();
}

void TimeModePresenter::updateUIContinuousTime()
{
	view.updateUIContinuousTime();
}
