/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MENUVIEWBASE_HPP
#define MENUVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/menu_screen/MenuPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>

class MenuViewBase : public touchgfx::View<MenuPresenter>
{
public:
    MenuViewBase();
    virtual ~MenuViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void ResetParameters()
    {
        // Override and implement this function in Menu
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box boxBackgroundMenu;
    touchgfx::ButtonWithLabel buttonFrequency;
    touchgfx::ButtonWithLabel buttonTime;
    touchgfx::ButtonWithLabel buttonCalibration;
    touchgfx::BoxWithBorder boxWithBorderFrame;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MenuViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MENUVIEWBASE_HPP
