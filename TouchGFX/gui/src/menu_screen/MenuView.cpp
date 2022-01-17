#include <gui/menu_screen/MenuView.hpp>

MenuView::MenuView()
{

}

void MenuView::setupScreen()
{
    MenuViewBase::setupScreen();
    DataExchange.version = 1;
}

void MenuView::tearDownScreen()
{
    MenuViewBase::tearDownScreen();
}

void MenuView::ResetParameters()
{
	presenter->askForCalibration();
}
