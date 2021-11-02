#ifndef FREQHISTOGRAMPRESENTER_HPP
#define FREQHISTOGRAMPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class FreqHistogramView;

class FreqHistogramPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    FreqHistogramPresenter(FreqHistogramView& v);

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

    virtual ~FreqHistogramPresenter() {};

private:
    FreqHistogramPresenter();

    FreqHistogramView& view;
};

#endif // FREQHISTOGRAMPRESENTER_HPP