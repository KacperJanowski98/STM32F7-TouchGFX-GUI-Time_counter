/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TIMEMODECONFIGVIEWBASE_HPP
#define TIMEMODECONFIGVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/timemodeconfig_screen/TimeModeConfigPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>

class TimeModeConfigViewBase : public touchgfx::View<TimeModeConfigPresenter>
{
public:
    TimeModeConfigViewBase();
    virtual ~TimeModeConfigViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box boxLeftBackG;
    touchgfx::Box boxRightBackG;
    touchgfx::Box boxConfigTime;
    touchgfx::Button buttonBackTime;
    touchgfx::TextArea textArea1;
    touchgfx::Box boxBacgroundTC;
    touchgfx::SwipeContainer swipeContainerTime;
    touchgfx::Container swipeContainerTimeINPUT;
    touchgfx::Box boxINPUT;
    touchgfx::Image imageArrowR;
    touchgfx::TextArea labelINPUT;
    touchgfx::Container swipeContainerTimeCLOCK;
    touchgfx::Box boxCLOCK;
    touchgfx::Image imageArrowCL;
    touchgfx::Image imageArrowCR;
    touchgfx::TextArea labelCLOCK;
    touchgfx::Container swipeContainerTimeTISETUP;
    touchgfx::Box boxTISETUP;
    touchgfx::Image imageArrowTL;
    touchgfx::Image imageArrowTR;
    touchgfx::TextArea labelTISETUP;
    touchgfx::Container swipeContainerTimeSESSION;
    touchgfx::Box boxSESSIONSETUP;
    touchgfx::Image imageArrowSL;
    touchgfx::TextArea labelSESSIONSETUP;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TimeModeConfigViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // TIMEMODECONFIGVIEWBASE_HPP
