#include <gui/freqmodeconfig_screen/FreqModeConfigView.hpp>
#include <gui/freqmodeconfig_screen/FreqModeConfigPresenter.hpp>

FreqModeConfigPresenter::FreqModeConfigPresenter(FreqModeConfigView& v)
    : view(v)
{

}

void FreqModeConfigPresenter::activate()
{

}

void FreqModeConfigPresenter::deactivate()
{

}

void FreqModeConfigPresenter::askForDataFreqSingle()
{
	model->getDataFreqSingle();
}

void FreqModeConfigPresenter::askForDataFreqConst()
{
	model->getDataFreqContinuous();
}

void FreqModeConfigPresenter::askForDataFreqStamps()
{
	model->getDataFreqStamps();
}

void FreqModeConfigPresenter::askForDetectedThreshold()
{
	model->getDetectedFreqThreshold();
}
