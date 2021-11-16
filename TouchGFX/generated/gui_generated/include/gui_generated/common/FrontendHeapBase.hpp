/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDHEAPBASE_HPP
#define FRONTENDHEAPBASE_HPP

#include <common/Meta.hpp>
#include <common/Partition.hpp>
#include <mvp/MVPHeap.hpp>

#include <touchgfx/transitions/NoTransition.hpp>
#include <touchgfx/transitions/SlideTransition.hpp>
#include <touchgfx/transitions/CoverTransition.hpp>
#include <touchgfx/transitions/WipeTransition.hpp>

#include <gui/common/FrontendApplication.hpp>
#include <gui/model/Model.hpp>

#include <gui/calibrationprogressbar_screen/CalibrationProgressBarView.hpp>
#include <gui/calibrationprogressbar_screen/CalibrationProgressBarPresenter.hpp>
#include <gui/menu_screen/MenuView.hpp>
#include <gui/menu_screen/MenuPresenter.hpp>
#include <gui/timemode_screen/TimeModeView.hpp>
#include <gui/timemode_screen/TimeModePresenter.hpp>
#include <gui/timemodeconfig_screen/TimeModeConfigView.hpp>
#include <gui/timemodeconfig_screen/TimeModeConfigPresenter.hpp>
#include <gui/freqmode_screen/FreqModeView.hpp>
#include <gui/freqmode_screen/FreqModePresenter.hpp>
#include <gui/freqmodeconfig_screen/FreqModeConfigView.hpp>
#include <gui/freqmodeconfig_screen/FreqModeConfigPresenter.hpp>
#include <gui/timehistogram_screen/TimeHistogramView.hpp>
#include <gui/timehistogram_screen/TimeHistogramPresenter.hpp>
#include <gui/timegraphti1_screen/TimeGraphTi1View.hpp>
#include <gui/timegraphti1_screen/TimeGraphTi1Presenter.hpp>
#include <gui/freqhistogram_screen/FreqHistogramView.hpp>
#include <gui/freqhistogram_screen/FreqHistogramPresenter.hpp>
#include <gui/freqgraph_screen/FreqGraphView.hpp>
#include <gui/freqgraph_screen/FreqGraphPresenter.hpp>
#include <gui/about_screen/AboutView.hpp>
#include <gui/about_screen/AboutPresenter.hpp>


/**
 * This class provides the memory that shall be used for memory allocations
 * in the frontend. A single instance of the FrontendHeap is allocated once (in heap
 * memory), and all other frontend objects such as views, presenters and data model are
 * allocated within the scope of this FrontendHeap. As such, the RAM usage of the entire
 * user interface is sizeof(FrontendHeap).
 *
 * @note The FrontendHeap reserves memory for the most memory-consuming presenter and
 * view only. The largest of these classes are determined at compile-time using template
 * magic. As such, it is important to add all presenters, views and transitions to the
 * type lists in this class.
 *
 */
class FrontendHeapBase : public touchgfx::MVPHeap
{
public:
    /**
     * A list of all view types. Must end with meta::Nil.
     * @note All view types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< CalibrationProgressBarView,
            touchgfx::meta::TypeList< MenuView,
            touchgfx::meta::TypeList< TimeModeView,
            touchgfx::meta::TypeList< TimeModeConfigView,
            touchgfx::meta::TypeList< FreqModeView,
            touchgfx::meta::TypeList< FreqModeConfigView,
            touchgfx::meta::TypeList< TimeHistogramView,
            touchgfx::meta::TypeList< TimeGraphTi1View,
            touchgfx::meta::TypeList< FreqHistogramView,
            touchgfx::meta::TypeList< FreqGraphView,
            touchgfx::meta::TypeList< AboutView,
            touchgfx::meta::Nil > > > > > > > > > >
            > GeneratedViewTypes;

    /**
     * Determine (compile time) the View type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedViewTypes >::type MaxGeneratedViewType;

    /**
     * A list of all presenter types. Must end with meta::Nil.
     * @note All presenter types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< CalibrationProgressBarPresenter,
            touchgfx::meta::TypeList< MenuPresenter,
            touchgfx::meta::TypeList< TimeModePresenter,
            touchgfx::meta::TypeList< TimeModeConfigPresenter,
            touchgfx::meta::TypeList< FreqModePresenter,
            touchgfx::meta::TypeList< FreqModeConfigPresenter,
            touchgfx::meta::TypeList< TimeHistogramPresenter,
            touchgfx::meta::TypeList< TimeGraphTi1Presenter,
            touchgfx::meta::TypeList< FreqHistogramPresenter,
            touchgfx::meta::TypeList< FreqGraphPresenter,
            touchgfx::meta::TypeList< AboutPresenter,
            touchgfx::meta::Nil > > > > > > > > > >
            > GeneratedPresenterTypes;

    /**
     * Determine (compile time) the Presenter type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedPresenterTypes >::type MaxGeneratedPresenterType;

    /**
     * A list of all transition types. Must end with meta::Nil.
     * @note All transition types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< touchgfx::NoTransition,
            touchgfx::meta::TypeList< SlideTransition<EAST>,
            touchgfx::meta::TypeList< CoverTransition<EAST>,
            touchgfx::meta::TypeList< CoverTransition<WEST>,
            touchgfx::meta::TypeList< WipeTransition<WEST>,
            touchgfx::meta::TypeList< WipeTransition<EAST>,
            touchgfx::meta::Nil > > > > >
            > GeneratedTransitionTypes;

    /**
     * Determine (compile time) the Transition type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedTransitionTypes >::type MaxGeneratedTransitionType;

    virtual void gotoStartScreen(FrontendApplication& app)
    {
        app.gotoCalibrationProgressBarScreenNoTransition();
    }
protected:
    FrontendHeapBase(touchgfx::AbstractPartition& presenters, touchgfx::AbstractPartition& views, touchgfx::AbstractPartition& transitions, FrontendApplication& app)
        : MVPHeap(presenters, views, transitions, app)
    {

    }

};

#endif // FRONTENDHEAPBASE_HPP
