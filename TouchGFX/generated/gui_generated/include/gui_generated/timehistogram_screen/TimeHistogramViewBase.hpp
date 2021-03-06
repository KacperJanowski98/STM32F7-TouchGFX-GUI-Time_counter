/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TIMEHISTOGRAMVIEWBASE_HPP
#define TIMEHISTOGRAMVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/timehistogram_screen/TimeHistogramPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/Image.hpp>

class TimeHistogramViewBase : public touchgfx::View<TimeHistogramPresenter>
{
public:
    TimeHistogramViewBase();
    virtual ~TimeHistogramViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void DisplayGraph2()
    {
        // Override and implement this function in TimeHistogram
    }

    virtual void DisplayGraph1()
    {
        // Override and implement this function in TimeHistogram
    }

    virtual void DisplayGraph3()
    {
        // Override and implement this function in TimeHistogram
    }

    virtual void DisplayGraph4()
    {
        // Override and implement this function in TimeHistogram
    }

    virtual void DisplayGraph5()
    {
        // Override and implement this function in TimeHistogram
    }

    virtual void DisplayGraph6()
    {
        // Override and implement this function in TimeHistogram
    }

    virtual void DisplayGraph7()
    {
        // Override and implement this function in TimeHistogram
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::Button buttonBack;
    touchgfx::TextArea textAreaMain;
    touchgfx::ButtonWithLabel buttonWithLabelTi1;
    touchgfx::ButtonWithLabel buttonWithLabelTi2;
    touchgfx::ButtonWithLabel buttonWithLabelTi3;
    touchgfx::ButtonWithLabel buttonWithLabelTi4;
    touchgfx::ButtonWithLabel buttonWithLabelTi5;
    touchgfx::ButtonWithLabel buttonWithLabelTi6;
    touchgfx::ButtonWithLabel buttonWithLabelTi7;
    touchgfx::BoxWithBorder boxWithBorderLabelT;
    touchgfx::Image imageGraph;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TimeHistogramViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // TIMEHISTOGRAMVIEWBASE_HPP
