#include <gui/freqmode_screen/FreqModeView.hpp>

FreqModeView::FreqModeView()
{

}

void FreqModeView::setupScreen()
{
    FreqModeViewBase::setupScreen();

    // testy :TODO
    Unicode::snprintf(textMainFBuffer, TEXTMAINF_SIZE, "%d", testDisplayFreq);
    textMainF.invalidate();
}

void FreqModeView::tearDownScreen()
{
    FreqModeViewBase::tearDownScreen();
}
