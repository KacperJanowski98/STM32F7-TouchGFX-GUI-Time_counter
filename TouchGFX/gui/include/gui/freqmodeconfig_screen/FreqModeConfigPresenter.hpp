#ifndef FREQMODECONFIGPRESENTER_HPP
#define FREQMODECONFIGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class FreqModeConfigView;

class FreqModeConfigPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    FreqModeConfigPresenter(FreqModeConfigView& v);

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

    virtual ~FreqModeConfigPresenter() {};

    /**
     * My function
     */
    virtual void askForDataFreqSingle();

    virtual void askForDataFreqConst();

    virtual void askForDataFreqStamps();

private:
    FreqModeConfigPresenter();

    FreqModeConfigView& view;
};

#endif // FREQMODECONFIGPRESENTER_HPP
