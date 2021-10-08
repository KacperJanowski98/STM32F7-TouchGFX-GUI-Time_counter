#include <gui/timemodeconfig_screen/TimeModeConfigView.hpp>
#include <gui/timemodeconfig_screen/TimeModeConfigPresenter.hpp>

TimeModeConfigPresenter::TimeModeConfigPresenter(TimeModeConfigView& v)
    : view(v)
{

}

void TimeModeConfigPresenter::activate()
{

}

void TimeModeConfigPresenter::deactivate()
{

}

void TimeModeConfigPresenter::askForDataTimeSingle()
{
	model->getDataTimeSingle();
}

void TimeModeConfigPresenter::askForDataTimeConst()
{
	model->getDataTimeContinuous();
}

void TimeModeConfigPresenter::askForDataTimeStamps()
{
	model->getDataTimeStamps();
}
