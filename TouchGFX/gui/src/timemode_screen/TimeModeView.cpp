#include <gui/timemode_screen/TimeModeView.hpp>

TimeModeView::TimeModeView()
{

}

void TimeModeView::setupScreen()
{
    TimeModeViewBase::setupScreen();

    // testy
    Unicode::snprintf(textMainBuffer, TEXTMAIN_SIZE, "%d", testDisplay);
    textMain.invalidate();
}

void TimeModeView::tearDownScreen()
{
    TimeModeViewBase::tearDownScreen();
}
