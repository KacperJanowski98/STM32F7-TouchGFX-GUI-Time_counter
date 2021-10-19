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

    calculateFormatMeanFreq(ResultFreqBackend.measure1.mean, &m_total_freq1, &m_frac1_freq1, &m_frac2_freq1);
    switch (ResultFreqBackend.measure1.meanUnit)
    {
    case HZ:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.%d %d", m_total_freq1, m_frac1_freq1, m_frac2_freq1);
    	Unicode::strncpy(textUnitMean1Buffer, (char*)Hz, TEXTUNITMEAN1_SIZE - 1);
    	break;
    case KILO:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.%d %d", m_total_freq1, m_frac1_freq1, m_frac2_freq1);
    	Unicode::strncpy(textUnitMean1Buffer, (char*)kHz, TEXTUNITMEAN1_SIZE - 1);
    	break;
    case MEGA:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.%d %d", m_total_freq1, m_frac1_freq1, m_frac2_freq1);
    	Unicode::strncpy(textUnitMean1Buffer, (char*)MHz, TEXTUNITMEAN1_SIZE - 1);
    	break;
    case GIGA:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.%d %d", m_total_freq1, m_frac1_freq1, m_frac2_freq1);
    	Unicode::strncpy(textUnitMean1Buffer, (char*)GHz, TEXTUNITMEAN1_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean1Buffer, (char*)kHz, TEXTUNITMEAN1_SIZE - 1);
    	break;
    }
    textMeanVal1.invalidate();
    textUnitMean1.invalidate();

    calculateFormatMeanFreq(ResultFreqBackend.measure2.mean, &m_total_freq2, &m_frac1_freq2, &m_frac2_freq2);
    switch (ResultFreqBackend.measure2.meanUnit)
    {
    case HZ:
    	Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.%d %d", m_total_freq2, m_frac1_freq2, m_frac2_freq2);
    	Unicode::strncpy(textUnitMean2Buffer, (char*)Hz, TEXTUNITMEAN2_SIZE - 1);
    	break;
    case KILO:
    	Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.%d %d", m_total_freq2, m_frac1_freq2, m_frac2_freq2);
    	Unicode::strncpy(textUnitMean2Buffer, (char*)kHz, TEXTUNITMEAN2_SIZE - 1);
    	break;
    case MEGA:
    	Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.%d %d", m_total_freq2, m_frac1_freq2, m_frac2_freq2);
    	Unicode::strncpy(textUnitMean2Buffer, (char*)MHz, TEXTUNITMEAN2_SIZE - 1);
    	break;
    case GIGA:
    	Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.%d %d", m_total_freq2, m_frac1_freq2, m_frac2_freq2);
    	Unicode::strncpy(textUnitMean2Buffer, (char*)GHz, TEXTUNITMEAN2_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean2Buffer, (char*)kHz, TEXTUNITMEAN2_SIZE - 1);
    	break;
    }
    textMeanVal2.invalidate();
    textUnitMean2.invalidate();

    calculateFormatMeanFreq(ResultFreqBackend.measure3.mean, &m_total_freq3, &m_frac1_freq3, &m_frac2_freq3);
    switch (ResultFreqBackend.measure3.meanUnit)
    {
    case HZ:
    	Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.%d %d", m_total_freq3, m_frac1_freq3, m_frac2_freq3);
    	Unicode::strncpy(textUnitMean3Buffer, (char*)Hz, TEXTUNITMEAN3_SIZE - 1);
    	break;
    case KILO:
    	Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.%d %d", m_total_freq3, m_frac1_freq3, m_frac2_freq3);
    	Unicode::strncpy(textUnitMean3Buffer, (char*)kHz, TEXTUNITMEAN3_SIZE - 1);
    	break;
    case MEGA:
    	Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.%d %d", m_total_freq3, m_frac1_freq3, m_frac2_freq3);
    	Unicode::strncpy(textUnitMean3Buffer, (char*)MHz, TEXTUNITMEAN3_SIZE - 1);
    	break;
    case GIGA:
    	Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.%d %d", m_total_freq3, m_frac1_freq3, m_frac2_freq3);
    	Unicode::strncpy(textUnitMean3Buffer, (char*)GHz, TEXTUNITMEAN3_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean3Buffer, (char*)kHz, TEXTUNITMEAN3_SIZE - 1);
    	break;
    }
    textMeanVal3.invalidate();
    textUnitMean3.invalidate();

    calculateFormatMeanFreq(ResultFreqBackend.measure4.mean, &m_total_freq4, &m_frac1_freq4, &m_frac2_freq4);
    switch (ResultFreqBackend.measure4.meanUnit)
    {
    case HZ:
    	Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.%d %d", m_total_freq4, m_frac1_freq4, m_frac2_freq4);
    	Unicode::strncpy(textUnitMean4Buffer, (char*)Hz, TEXTUNITMEAN4_SIZE - 1);
    	break;
    case KILO:
    	Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.%d %d", m_total_freq4, m_frac1_freq4, m_frac2_freq4);
    	Unicode::strncpy(textUnitMean4Buffer, (char*)kHz, TEXTUNITMEAN4_SIZE - 1);
    	break;
    case MEGA:
    	Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.%d %d", m_total_freq4, m_frac1_freq4, m_frac2_freq4);
    	Unicode::strncpy(textUnitMean4Buffer, (char*)MHz, TEXTUNITMEAN4_SIZE - 1);
    	break;
    case GIGA:
    	Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.%d %d", m_total_freq4, m_frac1_freq4, m_frac2_freq4);
    	Unicode::strncpy(textUnitMean4Buffer, (char*)GHz, TEXTUNITMEAN4_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean4Buffer, (char*)kHz, TEXTUNITMEAN4_SIZE - 1);
    	break;
    }
    textMeanVal4.invalidate();
    textUnitMean4.invalidate();

    calculateFormatMeanFreq(ResultFreqBackend.measure5.mean, &m_total_freq5, &m_frac1_freq5, &m_frac2_freq5);
    switch (ResultFreqBackend.measure5.meanUnit)
    {
    case HZ:
    	Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.%d %d", m_total_freq5, m_frac1_freq5, m_frac2_freq5);
    	Unicode::strncpy(textUnitMean5Buffer, (char*)Hz, TEXTUNITMEAN5_SIZE - 1);
    	break;
    case KILO:
    	Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.%d %d", m_total_freq5, m_frac1_freq5, m_frac2_freq5);
    	Unicode::strncpy(textUnitMean5Buffer, (char*)kHz, TEXTUNITMEAN5_SIZE - 1);
    	break;
    case MEGA:
    	Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.%d %d", m_total_freq5, m_frac1_freq5, m_frac2_freq5);
    	Unicode::strncpy(textUnitMean5Buffer, (char*)MHz, TEXTUNITMEAN5_SIZE - 1);
    	break;
    case GIGA:
    	Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.%d %d", m_total_freq5, m_frac1_freq5, m_frac2_freq5);
    	Unicode::strncpy(textUnitMean5Buffer, (char*)GHz, TEXTUNITMEAN5_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean5Buffer, (char*)kHz, TEXTUNITMEAN5_SIZE - 1);
    	break;
    }
    textMeanVal5.invalidate();
    textUnitMean5.invalidate();

    calculateFormatMeanFreq(ResultFreqBackend.measure6.mean, &m_total_freq6, &m_frac1_freq6, &m_frac2_freq6);
    switch (ResultFreqBackend.measure6.meanUnit)
    {
    case HZ:
    	Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.%d %d", m_total_freq6, m_frac1_freq6, m_frac2_freq6);
    	Unicode::strncpy(textUnitMean6Buffer, (char*)Hz, TEXTUNITMEAN6_SIZE - 1);
    	break;
    case KILO:
    	Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.%d %d", m_total_freq6, m_frac1_freq6, m_frac2_freq6);
    	Unicode::strncpy(textUnitMean6Buffer, (char*)kHz, TEXTUNITMEAN6_SIZE - 1);
    	break;
    case MEGA:
    	Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.%d %d", m_total_freq6, m_frac1_freq6, m_frac2_freq6);
    	Unicode::strncpy(textUnitMean6Buffer, (char*)MHz, TEXTUNITMEAN6_SIZE - 1);
    	break;
    case GIGA:
    	Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.%d %d", m_total_freq6, m_frac1_freq6, m_frac2_freq6);
    	Unicode::strncpy(textUnitMean6Buffer, (char*)GHz, TEXTUNITMEAN6_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean6Buffer, (char*)kHz, TEXTUNITMEAN6_SIZE - 1);
    	break;
    }
    textMeanVal6.invalidate();
    textUnitMean6.invalidate();

    calculateFormatMeanFreq(ResultFreqBackend.measure7.mean, &m_total_freq7, &m_frac1_freq7, &m_frac2_freq7);
    switch (ResultFreqBackend.measure7.meanUnit)
    {
    case HZ:
    	Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", m_total_freq7, m_frac1_freq7, m_frac2_freq7);
    	Unicode::strncpy(textUnitMean7Buffer, (char*)Hz, TEXTUNITMEAN7_SIZE - 1);
    	break;
    case KILO:
    	Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", m_total_freq7, m_frac1_freq7, m_frac2_freq7);
    	Unicode::strncpy(textUnitMean7Buffer, (char*)kHz, TEXTUNITMEAN7_SIZE - 1);
    	break;
    case MEGA:
    	Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", m_total_freq7, m_frac1_freq7, m_frac2_freq7);
    	Unicode::strncpy(textUnitMean7Buffer, (char*)MHz, TEXTUNITMEAN7_SIZE - 1);
    	break;
    case GIGA:
    	Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", m_total_freq7, m_frac1_freq7, m_frac2_freq7);
    	Unicode::strncpy(textUnitMean7Buffer, (char*)GHz, TEXTUNITMEAN7_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean7Buffer, (char*)kHz, TEXTUNITMEAN7_SIZE - 1);
    	break;
    }
    textMeanVal7.invalidate();
    textUnitMean7.invalidate();

    calculateFormatMeanFreq(ResultFreqBackend.measure8.mean, &m_total_freq8, &m_frac1_freq8, &m_frac2_freq8);
    switch (ResultFreqBackend.measure8.meanUnit)
    {
    case HZ:
    	Unicode::snprintf(textMeanVal8Buffer, TEXTMEANVAL8_SIZE, "%d.%d %d", m_total_freq8, m_frac1_freq8, m_frac2_freq8);
    	Unicode::strncpy(textUnitMean8Buffer, (char*)Hz, TEXTUNITMEAN8_SIZE - 1);
    	break;
    case KILO:
    	Unicode::snprintf(textMeanVal8Buffer, TEXTMEANVAL8_SIZE, "%d.%d %d", m_total_freq8, m_frac1_freq8, m_frac2_freq8);
    	Unicode::strncpy(textUnitMean8Buffer, (char*)kHz, TEXTUNITMEAN8_SIZE - 1);
    	break;
    case MEGA:
    	Unicode::snprintf(textMeanVal8Buffer, TEXTMEANVAL8_SIZE, "%d.%d %d", m_total_freq8, m_frac1_freq8, m_frac2_freq8);
    	Unicode::strncpy(textUnitMean8Buffer, (char*)MHz, TEXTUNITMEAN8_SIZE - 1);
    	break;
    case GIGA:
    	Unicode::snprintf(textMeanVal8Buffer, TEXTMEANVAL8_SIZE, "%d.%d %d", m_total_freq8, m_frac1_freq8, m_frac2_freq8);
    	Unicode::strncpy(textUnitMean8Buffer, (char*)GHz, TEXTUNITMEAN8_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal8Buffer, TEXTMEANVAL8_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean8Buffer, (char*)kHz, TEXTUNITMEAN8_SIZE - 1);
    	break;
    }
    textMeanVal8.invalidate();
    textUnitMean8.invalidate();

    // StdDev

    calculateFormatStdDevFreq(ResultFreqBackend.measure1.stdDev, &m_totalStdDev1, &m_fracStdDev1);
    Unicode::snprintf(textStdDevVal1Buffer, TEXTSTDDEVVAL1_SIZE, "%d.%d", m_totalStdDev1, m_fracStdDev1);
    textStdDevVal1.invalidate();
    switch (ResultFreqBackend.measure1.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)pHz, TEXTUNITSD1_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)nHz, TEXTUNITSD1_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)uHz, TEXTUNITSD1_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)mHz, TEXTUNITSD1_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)pHz, TEXTUNITSD1_SIZE - 1);
    	break;
    }
    textUnitSD1.invalidate();

    calculateFormatStdDevFreq(ResultFreqBackend.measure2.stdDev, &m_totalStdDev2, &m_fracStdDev2);
    Unicode::snprintf(textStdDevVal2Buffer, TEXTSTDDEVVAL2_SIZE, "%d.%d", m_totalStdDev2, m_fracStdDev2);
    textStdDevVal2.invalidate();
    switch (ResultFreqBackend.measure2.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)pHz, TEXTUNITSD2_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)nHz, TEXTUNITSD2_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)uHz, TEXTUNITSD2_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)mHz, TEXTUNITSD2_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)pHz, TEXTUNITSD2_SIZE - 1);
    	break;
    }
    textUnitSD2.invalidate();

    calculateFormatStdDevFreq(ResultFreqBackend.measure3.stdDev, &m_totalStdDev3, &m_fracStdDev3);
    Unicode::snprintf(textStdDevVal3Buffer, TEXTSTDDEVVAL3_SIZE, "%d.%d", m_totalStdDev3, m_fracStdDev3);
    textStdDevVal3.invalidate();
    switch (ResultFreqBackend.measure3.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)pHz, TEXTUNITSD3_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)nHz, TEXTUNITSD3_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)uHz, TEXTUNITSD3_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)mHz, TEXTUNITSD3_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)pHz, TEXTUNITSD3_SIZE - 1);
    	break;
    }
    textUnitSD3.invalidate();

    calculateFormatStdDevFreq(ResultFreqBackend.measure4.stdDev, &m_totalStdDev4, &m_fracStdDev4);
    Unicode::snprintf(textStdDevVal4Buffer, TEXTSTDDEVVAL4_SIZE, "%d.%d", m_totalStdDev4, m_fracStdDev4);
    textStdDevVal4.invalidate();
    switch (ResultFreqBackend.measure4.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)pHz, TEXTUNITSD4_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)nHz, TEXTUNITSD4_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)uHz, TEXTUNITSD4_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)mHz, TEXTUNITSD4_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)pHz, TEXTUNITSD4_SIZE - 1);
    	break;
    }
    textUnitSD4.invalidate();

    calculateFormatStdDevFreq(ResultFreqBackend.measure5.stdDev, &m_totalStdDev5, &m_fracStdDev5);
    Unicode::snprintf(textStdDevVal5Buffer, TEXTSTDDEVVAL5_SIZE, "%d.%d", m_totalStdDev5, m_fracStdDev5);
    textStdDevVal5.invalidate();
    switch (ResultFreqBackend.measure5.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)pHz, TEXTUNITSD5_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)nHz, TEXTUNITSD5_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)uHz, TEXTUNITSD5_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)mHz, TEXTUNITSD5_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)pHz, TEXTUNITSD5_SIZE - 1);
    	break;
    }
    textUnitSD5.invalidate();

    calculateFormatStdDevFreq(ResultFreqBackend.measure6.stdDev, &m_totalStdDev6, &m_fracStdDev6);
    Unicode::snprintf(textStdDevVal6Buffer, TEXTSTDDEVVAL6_SIZE, "%d.%d", m_totalStdDev6, m_fracStdDev6);
    textStdDevVal6.invalidate();
    switch (ResultFreqBackend.measure6.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)pHz, TEXTUNITSD6_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)nHz, TEXTUNITSD6_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)uHz, TEXTUNITSD6_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)mHz, TEXTUNITSD6_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)pHz, TEXTUNITSD6_SIZE - 1);
    	break;
    }
    textUnitSD6.invalidate();

    calculateFormatStdDevFreq(ResultFreqBackend.measure7.stdDev, &m_totalStdDev7, &m_fracStdDev7);
    Unicode::snprintf(textStdDevVal7Buffer, TEXTSTDDEVVAL7_SIZE, "%d.%d", m_totalStdDev7, m_fracStdDev7);
    textStdDevVal7.invalidate();
    switch (ResultFreqBackend.measure7.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)pHz, TEXTUNITSD7_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)nHz, TEXTUNITSD7_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)uHz, TEXTUNITSD7_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)mHz, TEXTUNITSD7_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)pHz, TEXTUNITSD7_SIZE - 1);
    	break;
    }
    textUnitSD7.invalidate();

    calculateFormatStdDevFreq(ResultFreqBackend.measure8.stdDev, &m_totalStdDev8, &m_fracStdDev8);
    Unicode::snprintf(textStdDevVal8Buffer, TEXTSTDDEVVAL8_SIZE, "%d.%d", m_totalStdDev8, m_fracStdDev8);
    textStdDevVal8.invalidate();
    switch (ResultFreqBackend.measure8.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD8Buffer, (char*)pHz, TEXTUNITSD8_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD8Buffer, (char*)nHz, TEXTUNITSD8_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD8Buffer, (char*)uHz, TEXTUNITSD8_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD8Buffer, (char*)mHz, TEXTUNITSD8_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD8Buffer, (char*)pHz, TEXTUNITSD8_SIZE - 1);
    	break;
    }
    textUnitSD8.invalidate();

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

void FreqModeView::updateUIContinuousFreq()
{
	FreqModeView::draw();
	FreqModeView::setupScreen();
}

void FreqModeView::calculateFormatMeanFreq(float mean, int *pTotal, int *pFrac1, int *pFrac2)
{
    int a = 0, b = 0, c = 0;
    *pTotal = mean;
    float tempFrac = mean - *pTotal;
    int tempInt2 = trunc(tempFrac * 1000000);
    *pFrac1 = tempInt2;
    *pFrac1 /= 1000;
    a = tempInt2 / 100 % 10;
    b = tempInt2 / 10  % 10;
    c = tempInt2 / 1 % 10;
    *pFrac2 = a * 100 + b * 10 + c;
}

void FreqModeView::calculateFormatStdDevFreq(float stdDev, int *pTotal, int *pFrac)
{
	*pTotal = stdDev;
	float tempFrac = stdDev - *pTotal;
	*pFrac = trunc(tempFrac * 100);
}
