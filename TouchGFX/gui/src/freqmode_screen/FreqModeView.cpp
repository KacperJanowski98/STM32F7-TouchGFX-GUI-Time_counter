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

    Unicode::snprintf(textFreq1startBuffer, TEXTFREQ1START_SIZE, "%d", FreqBackend.Channel1.numberChanel);
    textFreq1start.invalidate();

    Unicode::snprintf(textFreq2startBuffer, TEXTFREQ2START_SIZE, "%d", FreqBackend.Channel2.numberChanel);
    textFreq2start.invalidate();

    Unicode::snprintf(textFreq3startBuffer, TEXTFREQ3START_SIZE, "%d", FreqBackend.Channel3.numberChanel);
    textFreq3start.invalidate();

    Unicode::snprintf(textFreq4startBuffer, TEXTFREQ4START_SIZE, "%d", FreqBackend.Channel4.numberChanel);
    textFreq4start.invalidate();

    Unicode::snprintf(textFreq5startBuffer, TEXTFREQ5START_SIZE, "%d", FreqBackend.Channel5.numberChanel);
    textFreq5start.invalidate();

    Unicode::snprintf(textFreq6startBuffer, TEXTFREQ6START_SIZE, "%d", FreqBackend.Channel6.numberChanel);
    textFreq6start.invalidate();

    Unicode::snprintf(textFreq7startBuffer, TEXTFREQ7START_SIZE, "%d", FreqBackend.Channel7.numberChanel);
    textFreq7start.invalidate();

    Unicode::snprintf(textFreq8startBuffer, TEXTFREQ8START_SIZE, "%d", FreqBackend.Channel8.numberChanel);
    textFreq8start.invalidate();

    // Sample

    Unicode::snprintf(textSample1Buffer, TEXTSAMPLE1_SIZE, "%d", FreqBackend.FreqSession.stampsNumber);
    textSample1.invalidate();

    Unicode::snprintf(textSample2Buffer, TEXTSAMPLE2_SIZE, "%d", FreqBackend.FreqSession.stampsNumber);
    textSample2.invalidate();

    Unicode::snprintf(textSample3Buffer, TEXTSAMPLE3_SIZE, "%d", FreqBackend.FreqSession.stampsNumber);
    textSample3.invalidate();

    Unicode::snprintf(textSample4Buffer, TEXTSAMPLE4_SIZE, "%d", FreqBackend.FreqSession.stampsNumber);
    textSample4.invalidate();

    Unicode::snprintf(textSample5Buffer, TEXTSAMPLE5_SIZE, "%d", FreqBackend.FreqSession.stampsNumber);
    textSample5.invalidate();

    Unicode::snprintf(textSample6Buffer, TEXTSAMPLE6_SIZE, "%d", FreqBackend.FreqSession.stampsNumber);
    textSample6.invalidate();

    Unicode::snprintf(textSample7Buffer, TEXTSAMPLE7_SIZE, "%d", FreqBackend.FreqSession.stampsNumber);
    textSample7.invalidate();

    Unicode::snprintf(textSample8Buffer, TEXTSAMPLE8_SIZE, "%d", FreqBackend.FreqSession.stampsNumber);
    textSample8.invalidate();

    // Mean


    // StdDev

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
