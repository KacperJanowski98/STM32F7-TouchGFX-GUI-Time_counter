/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FREQHISTOGRAMVIEWBASE_HPP
#define FREQHISTOGRAMVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/freqhistogram_screen/FreqHistogramPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

class FreqHistogramViewBase : public touchgfx::View<FreqHistogramPresenter>
{
public:
    FreqHistogramViewBase();
    virtual ~FreqHistogramViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void DisplayGraph1()
    {
        // Override and implement this function in FreqHistogram
    }

    virtual void DisplayGraph2()
    {
        // Override and implement this function in FreqHistogram
    }

    virtual void DisplayGraph3()
    {
        // Override and implement this function in FreqHistogram
    }

    virtual void DisplayGraph4()
    {
        // Override and implement this function in FreqHistogram
    }

    virtual void DisplayGraph5()
    {
        // Override and implement this function in FreqHistogram
    }

    virtual void DisplayGraph6()
    {
        // Override and implement this function in FreqHistogram
    }

    virtual void DisplayGraph7()
    {
        // Override and implement this function in FreqHistogram
    }

    virtual void DisplayGraph8()
    {
        // Override and implement this function in FreqHistogram
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
    touchgfx::TextArea textArea1;
    touchgfx::ButtonWithLabel buttonWithLabelM1;
    touchgfx::ButtonWithLabel buttonWithLabelM2;
    touchgfx::ButtonWithLabel buttonWithLabelM3;
    touchgfx::ButtonWithLabel buttonWithLabelM4;
    touchgfx::ButtonWithLabel buttonWithLabelM5;
    touchgfx::ButtonWithLabel buttonWithLabelM6;
    touchgfx::ButtonWithLabel buttonWithLabelM7;
    touchgfx::ButtonWithLabel buttonWithLabelM8;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<FreqHistogramViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // FREQHISTOGRAMVIEWBASE_HPP