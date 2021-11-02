#ifndef FREQGRAPHVIEW_HPP
#define FREQGRAPHVIEW_HPP

#include <gui_generated/freqgraph_screen/FreqGraphViewBase.hpp>
#include <gui/freqgraph_screen/FreqGraphPresenter.hpp>

class FreqGraphView : public FreqGraphViewBase
{
public:
    FreqGraphView();
    virtual ~FreqGraphView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // FREQGRAPHVIEW_HPP
