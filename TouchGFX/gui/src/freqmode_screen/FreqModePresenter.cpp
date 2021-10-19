#include <gui/freqmode_screen/FreqModeView.hpp>
#include <gui/freqmode_screen/FreqModePresenter.hpp>

FreqModePresenter::FreqModePresenter(FreqModeView& v)
    : view(v)
{

}

void FreqModePresenter::activate()
{

}

void FreqModePresenter::deactivate()
{

}

void FreqModePresenter::askForReset()
{
	model->getResetFreq();
}

void FreqModePresenter::updateUIContinuousFreq()
{
	view.updateUIContinuousFreq();
}
