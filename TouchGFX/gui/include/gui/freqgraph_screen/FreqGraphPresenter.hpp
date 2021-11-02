#ifndef FREQGRAPHPRESENTER_HPP
#define FREQGRAPHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class FreqGraphView;

class FreqGraphPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    FreqGraphPresenter(FreqGraphView& v);

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

    virtual ~FreqGraphPresenter() {};

private:
    FreqGraphPresenter();

    FreqGraphView& view;
};

#endif // FREQGRAPHPRESENTER_HPP
