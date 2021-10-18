#include <gui/freqmode_screen/FreqModeView.hpp>

FreqModeView::FreqModeView()
{

}

void FreqModeView::setupScreen()
{
    FreqModeViewBase::setupScreen();

    char pHz[] = "pHz";
    char nHz[] = "nHz";
    char uHz[] = "uHz";
    char mHz[] = "mHz";
    char Hz[] = "Hz";
    char kHz[] = "kHz";
    char MHz[] = "MHz";
    char GHz[] = "GHz";

    m_total_freq1 = 0;
    m_frac1_freq1 = 0;
    m_frac2_freq1 = 0;
    m_total_freq2 = 0;
    m_frac1_freq2 = 0;
    m_frac2_freq2 = 0;
    m_total_freq3 = 0;
    m_frac1_freq3 = 0;
    m_frac2_freq3 = 0;
    m_total_freq4 = 0;
    m_frac1_freq4 = 0;
    m_frac2_freq4 = 0;
    m_total_freq5 = 0;
    m_frac1_freq5 = 0;
    m_frac2_freq5 = 0;
    m_total_freq6 = 0;
    m_frac1_freq6 = 0;
    m_frac2_freq6 = 0;
    m_total_freq7 = 0;
    m_frac1_freq7 = 0;
    m_frac2_freq7 = 0;
    m_total_freq8 = 0;
    m_frac1_freq8 = 0;
    m_frac2_freq8 = 0;
    m_totalStdDev1 = 0;
    m_fracStdDev1 = 0;
    m_totalStdDev2 = 0;
    m_fracStdDev2 = 0;
    m_totalStdDev3 = 0;
    m_fracStdDev3 = 0;
    m_totalStdDev4 = 0;
    m_fracStdDev4 = 0;
    m_totalStdDev5 = 0;
    m_fracStdDev5 = 0;
    m_totalStdDev6 = 0;
    m_fracStdDev6 = 0;
    m_totalStdDev7 = 0;
    m_fracStdDev7 = 0;
    m_totalStdDev8 = 0;
    m_fracStdDev8 = 0;

    // Label

//    Unicode::snprintf(textFreq1startBuffer, TEXTFREQ1START_1_SIZE, "%d", FreqBackend.Channel1.);

}

void FreqModeView::tearDownScreen()
{
    FreqModeViewBase::tearDownScreen();
}

void FreqModeView::ResetParameter()
{
	presenter->askForReset();
	FreqModeView::draw();
	FreqModeView::setupScreen();
}
