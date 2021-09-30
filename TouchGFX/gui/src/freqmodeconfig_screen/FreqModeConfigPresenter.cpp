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

void FreqModeConfigPresenter::askForDataFreq()
{
	model->getDataFreq();
}
