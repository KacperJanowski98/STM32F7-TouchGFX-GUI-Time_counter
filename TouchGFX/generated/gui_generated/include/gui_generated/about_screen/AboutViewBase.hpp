/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ABOUTVIEWBASE_HPP
#define ABOUTVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/about_screen/AboutPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class AboutViewBase : public touchgfx::View<AboutPresenter>
{
public:
    AboutViewBase();
    virtual ~AboutViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box boxBackground;
    touchgfx::BoxWithBorder boxWithBorderFrame;
    touchgfx::Button buttonBack;
    touchgfx::Image imageInfo;
    touchgfx::TextArea labelAuthor;
    touchgfx::TextArea textAreaAuthor;
    touchgfx::Image LogoWat;
    touchgfx::TextArea LabelWAT;
    touchgfx::TextArea textAreaVersion;
    touchgfx::TextArea textAreaVersionNumber;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<AboutViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // ABOUTVIEWBASE_HPP
