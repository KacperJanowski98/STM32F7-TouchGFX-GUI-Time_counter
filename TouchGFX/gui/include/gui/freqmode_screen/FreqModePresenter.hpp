#ifndef FREQMODEPRESENTER_HPP
#define FREQMODEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class FreqModeView;

class FreqModePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    FreqModePresenter(FreqModeView& v);

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

    virtual ~FreqModePresenter() {};

    void askForReset();

    virtual void updateUIContinuousFreq();

private:
    FreqModePresenter();

    FreqModeView& view;
};

#endif // FREQMODEPRESENTER_HPP
