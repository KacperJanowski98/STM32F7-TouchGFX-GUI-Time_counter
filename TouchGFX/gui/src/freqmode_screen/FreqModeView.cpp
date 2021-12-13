#include <gui/freqmode_screen/FreqModeView.hpp>

FreqModeView::FreqModeView()
{

}

void FreqModeView::setupScreen()
{
    FreqModeViewBase::setupScreen();

    pHz = "pHz";
    nHz = "nHz";
    uHz = "uHz";
    mHz = "mHz";
    Hz = "Hz";
    kHz = "kHz";
    MHz = "MHz";
    GHz = "GHz";

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

    setLabelFreq(textFreq1startBuffer, TEXTFREQ1START_SIZE, FreqBackend.Channel1.numberChanel, &textFreq1start);
    setLabelColorFreq(FreqBackend.Channel1.channelState, &textLabelFreq1, &textFreq1start);
    setMeasColorFreq(FreqBackend.Channel1.channelState, &textMeanVal1, &textStdDevVal1);

    setLabelFreq(textFreq2startBuffer, TEXTFREQ2START_SIZE, FreqBackend.Channel2.numberChanel, &textFreq2start);
    setLabelColorFreq(FreqBackend.Channel2.channelState, &textLabelFreq2, &textFreq2start);
    setMeasColorFreq(FreqBackend.Channel2.channelState, &textMeanVal2, &textStdDevVal2);

    setLabelFreq(textFreq3startBuffer, TEXTFREQ3START_SIZE, FreqBackend.Channel3.numberChanel, &textFreq3start);
    setLabelColorFreq(FreqBackend.Channel3.channelState, &textLabelFreq3, &textFreq3start);
    setMeasColorFreq(FreqBackend.Channel3.channelState, &textMeanVal3, &textStdDevVal3);

    setLabelFreq(textFreq4startBuffer, TEXTFREQ4START_SIZE, FreqBackend.Channel4.numberChanel, &textFreq4start);
    setLabelColorFreq(FreqBackend.Channel4.channelState, &textLabelFreq4, &textFreq4start);
    setMeasColorFreq(FreqBackend.Channel4.channelState, &textMeanVal4, &textStdDevVal4);

    setLabelFreq(textFreq5startBuffer, TEXTFREQ5START_SIZE, FreqBackend.Channel5.numberChanel, &textFreq5start);
    setLabelColorFreq(FreqBackend.Channel5.channelState, &textLabelFreq5, &textFreq5start);
    setMeasColorFreq(FreqBackend.Channel5.channelState, &textMeanVal5, &textStdDevVal5);

    setLabelFreq(textFreq6startBuffer, TEXTFREQ6START_SIZE, FreqBackend.Channel6.numberChanel, &textFreq6start);
    setLabelColorFreq(FreqBackend.Channel6.channelState, &textLabelFreq6, &textFreq6start);
    setMeasColorFreq(FreqBackend.Channel6.channelState, &textMeanVal6, &textStdDevVal6);

    setLabelFreq(textFreq7startBuffer, TEXTFREQ7START_SIZE, FreqBackend.Channel7.numberChanel, &textFreq7start);
    setLabelColorFreq(FreqBackend.Channel7.channelState, &textLabelFreq7, &textFreq7start);
    setMeasColorFreq(FreqBackend.Channel7.channelState, &textMeanVal7, &textStdDevVal7);

    setLabelFreq(textFreq8startBuffer, TEXTFREQ8START_SIZE, FreqBackend.Channel8.numberChanel, &textFreq8start);
    setLabelColorFreq(FreqBackend.Channel8.channelState, &textLabelFreq8, &textFreq8start);
    setMeasColorFreq(FreqBackend.Channel8.channelState, &textMeanVal8, &textStdDevVal8);

    // Sample

    setSampleFreq(&FreqBackend.Channel1, &textSample1, textSample1Buffer, TEXTSAMPLE1_SIZE, &FreqBackend.FreqSession);

    setSampleFreq(&FreqBackend.Channel2, &textSample2, textSample2Buffer, TEXTSAMPLE2_SIZE, &FreqBackend.FreqSession);

    setSampleFreq(&FreqBackend.Channel3, &textSample3, textSample3Buffer, TEXTSAMPLE3_SIZE, &FreqBackend.FreqSession);

    setSampleFreq(&FreqBackend.Channel4, &textSample4, textSample4Buffer, TEXTSAMPLE4_SIZE, &FreqBackend.FreqSession);

    setSampleFreq(&FreqBackend.Channel5, &textSample5, textSample5Buffer, TEXTSAMPLE5_SIZE, &FreqBackend.FreqSession);

    setSampleFreq(&FreqBackend.Channel6, &textSample6, textSample6Buffer, TEXTSAMPLE6_SIZE, &FreqBackend.FreqSession);

    setSampleFreq(&FreqBackend.Channel7, &textSample7, textSample7Buffer, TEXTSAMPLE7_SIZE, &FreqBackend.FreqSession);

    setSampleFreq(&FreqBackend.Channel8, &textSample8, textSample8Buffer, TEXTSAMPLE8_SIZE, &FreqBackend.FreqSession);

    // Mean

    calculateFormatMeanFreq(ResultFreqBackend.measure1.mean, &m_total_freq1, &m_frac1_freq1, &m_frac2_freq1);
    setMeanResultFreq(&ResultFreqBackend.measure1, &m_total_freq1, &m_frac1_freq1, &m_frac2_freq1, textMeanVal1Buffer, TEXTMEANVAL1_SIZE, &textMeanVal1,
    					textUnitMean1Buffer, TEXTUNITMEAN1_SIZE, &textUnitMean1);

    calculateFormatMeanFreq(ResultFreqBackend.measure2.mean, &m_total_freq2, &m_frac1_freq2, &m_frac2_freq2);
    setMeanResultFreq(&ResultFreqBackend.measure2, &m_total_freq2, &m_frac1_freq2, &m_frac2_freq2, textMeanVal2Buffer, TEXTMEANVAL2_SIZE, &textMeanVal2,
    					textUnitMean2Buffer, TEXTUNITMEAN2_SIZE, &textUnitMean2);

    calculateFormatMeanFreq(ResultFreqBackend.measure3.mean, &m_total_freq3, &m_frac1_freq3, &m_frac2_freq3);
    setMeanResultFreq(&ResultFreqBackend.measure3, &m_total_freq3, &m_frac1_freq3, &m_frac2_freq3, textMeanVal3Buffer, TEXTMEANVAL3_SIZE, &textMeanVal3,
    					textUnitMean3Buffer, TEXTUNITMEAN3_SIZE, &textUnitMean3);

    calculateFormatMeanFreq(ResultFreqBackend.measure4.mean, &m_total_freq4, &m_frac1_freq4, &m_frac2_freq4);
    setMeanResultFreq(&ResultFreqBackend.measure4, &m_total_freq4, &m_frac1_freq4, &m_frac2_freq4, textMeanVal4Buffer, TEXTMEANVAL4_SIZE, &textMeanVal4,
    					textUnitMean4Buffer, TEXTUNITMEAN4_SIZE, &textUnitMean4);

    calculateFormatMeanFreq(ResultFreqBackend.measure5.mean, &m_total_freq5, &m_frac1_freq5, &m_frac2_freq5);
    setMeanResultFreq(&ResultFreqBackend.measure5, &m_total_freq5, &m_frac1_freq5, &m_frac2_freq5, textMeanVal5Buffer, TEXTMEANVAL5_SIZE, &textMeanVal5,
    					textUnitMean5Buffer, TEXTUNITMEAN5_SIZE, &textUnitMean5);

    calculateFormatMeanFreq(ResultFreqBackend.measure6.mean, &m_total_freq6, &m_frac1_freq6, &m_frac2_freq6);
    setMeanResultFreq(&ResultFreqBackend.measure6, &m_total_freq6, &m_frac1_freq6, &m_frac2_freq6, textMeanVal6Buffer, TEXTMEANVAL6_SIZE, &textMeanVal6,
    					textUnitMean6Buffer, TEXTUNITMEAN6_SIZE, &textUnitMean6);

    calculateFormatMeanFreq(ResultFreqBackend.measure7.mean, &m_total_freq7, &m_frac1_freq7, &m_frac2_freq7);
    setMeanResultFreq(&ResultFreqBackend.measure7, &m_total_freq7, &m_frac1_freq7, &m_frac2_freq7, textMeanVal7Buffer, TEXTMEANVAL7_SIZE, &textMeanVal7,
    					textUnitMean7Buffer, TEXTUNITMEAN7_SIZE, &textUnitMean7);

    calculateFormatMeanFreq(ResultFreqBackend.measure8.mean, &m_total_freq8, &m_frac1_freq8, &m_frac2_freq8);
    setMeanResultFreq(&ResultFreqBackend.measure8, &m_total_freq8, &m_frac1_freq8, &m_frac2_freq8, textMeanVal8Buffer, TEXTMEANVAL8_SIZE, &textMeanVal8,
    					textUnitMean8Buffer, TEXTUNITMEAN8_SIZE, &textUnitMean8);

    // StdDev

    calculateFormatStdDevFreq(ResultFreqBackend.measure1.stdDev, &m_totalStdDev1, &m_fracStdDev1);
    setStdDevResultFreq(textStdDevVal1Buffer, TEXTSTDDEVVAL1_SIZE, &textStdDevVal1, textUnitSD1Buffer, TEXTUNITSD1_SIZE, &textUnitSD1,
    					&ResultFreqBackend.measure1, &m_totalStdDev1, &m_fracStdDev1);

    calculateFormatStdDevFreq(ResultFreqBackend.measure2.stdDev, &m_totalStdDev2, &m_fracStdDev2);
    setStdDevResultFreq(textStdDevVal2Buffer, TEXTSTDDEVVAL2_SIZE, &textStdDevVal2, textUnitSD2Buffer, TEXTUNITSD2_SIZE, &textUnitSD2,
    					&ResultFreqBackend.measure2, &m_totalStdDev2, &m_fracStdDev2);

    calculateFormatStdDevFreq(ResultFreqBackend.measure3.stdDev, &m_totalStdDev3, &m_fracStdDev3);
    setStdDevResultFreq(textStdDevVal3Buffer, TEXTSTDDEVVAL3_SIZE, &textStdDevVal3, textUnitSD3Buffer, TEXTUNITSD3_SIZE, &textUnitSD3,
    					&ResultFreqBackend.measure3, &m_totalStdDev3, &m_fracStdDev3);

    calculateFormatStdDevFreq(ResultFreqBackend.measure4.stdDev, &m_totalStdDev4, &m_fracStdDev4);
    setStdDevResultFreq(textStdDevVal4Buffer, TEXTSTDDEVVAL4_SIZE, &textStdDevVal4, textUnitSD4Buffer, TEXTUNITSD4_SIZE, &textUnitSD4,
    					&ResultFreqBackend.measure4, &m_totalStdDev4, &m_fracStdDev4);

    calculateFormatStdDevFreq(ResultFreqBackend.measure5.stdDev, &m_totalStdDev5, &m_fracStdDev5);
    setStdDevResultFreq(textStdDevVal5Buffer, TEXTSTDDEVVAL5_SIZE, &textStdDevVal5, textUnitSD5Buffer, TEXTUNITSD5_SIZE, &textUnitSD5,
    					&ResultFreqBackend.measure5, &m_totalStdDev5, &m_fracStdDev5);

    calculateFormatStdDevFreq(ResultFreqBackend.measure6.stdDev, &m_totalStdDev6, &m_fracStdDev6);
    setStdDevResultFreq(textStdDevVal6Buffer, TEXTSTDDEVVAL6_SIZE, &textStdDevVal6, textUnitSD6Buffer, TEXTUNITSD6_SIZE, &textUnitSD6,
    					&ResultFreqBackend.measure6, &m_totalStdDev6, &m_fracStdDev6);

    calculateFormatStdDevFreq(ResultFreqBackend.measure7.stdDev, &m_totalStdDev7, &m_fracStdDev7);
    setStdDevResultFreq(textStdDevVal7Buffer, TEXTSTDDEVVAL7_SIZE, &textStdDevVal7, textUnitSD7Buffer, TEXTUNITSD7_SIZE, &textUnitSD7,
    					&ResultFreqBackend.measure7, &m_totalStdDev7, &m_fracStdDev7);

    calculateFormatStdDevFreq(ResultFreqBackend.measure8.stdDev, &m_totalStdDev8, &m_fracStdDev8);
    setStdDevResultFreq(textStdDevVal8Buffer, TEXTSTDDEVVAL8_SIZE, &textStdDevVal8, textUnitSD8Buffer, TEXTUNITSD8_SIZE, &textUnitSD8,
    					&ResultFreqBackend.measure8, &m_totalStdDev8, &m_fracStdDev8);
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

void FreqModeView::setLabelFreq(touchgfx::Unicode::UnicodeChar *textBuffer, uint16_t size, uint8_t numberCh, touchgfx::TextAreaWithOneWildcard *text)
{
	Unicode::snprintf(textBuffer, size, "%d", numberCh);
	text->invalidate();
}

void FreqModeView::setLabelColorFreq(bool channelState, touchgfx::TextArea *label, touchgfx::TextArea *labelStart)
{
	if (channelState == true)
	{
		label->setColor(touchgfx::Color::getColorFrom24BitRGB(42, 237, 148));
		labelStart->setColor(touchgfx::Color::getColorFrom24BitRGB(42, 237, 148));
	}
	else
	{
		label->setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
		labelStart->setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
	}
}

void FreqModeView::setMeasColorFreq(bool channelState, touchgfx::TextAreaWithOneWildcard *mean, touchgfx::TextAreaWithOneWildcard *stdDev)
{
	if (channelState == true)
	{
		mean->setColor(touchgfx::Color::getColorFrom24BitRGB(185, 239, 164));
		stdDev->setColor(touchgfx::Color::getColorFrom24BitRGB(185, 239, 164));
	}
	else
	{
		mean->setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
		stdDev->setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
	}
}

void FreqModeView::setSampleFreq(FreqChannel_t *pFreqCh, touchgfx::TextAreaWithOneWildcard *textSample, touchgfx::Unicode::UnicodeChar *textSampleBuffer,
								uint16_t sizeSample, SessionSetup_t *session)
{
    if (pFreqCh->channelState == false)
    {
    	textSample->setVisible(false);
    }
    else
    {
    	textSample->setVisible(true);
        Unicode::snprintf(textSampleBuffer, sizeSample, "%d", session->stampsNumber);
        textSample->invalidate();
    }
}

void FreqModeView::setMeanResultFreq(MeasFreq_t *measure, int *total, int *fraction1, int *fraction2, touchgfx::Unicode::UnicodeChar *textMeanBuffer,
									uint16_t sizeMean, touchgfx::TextAreaWithOneWildcard *textMean, touchgfx::Unicode::UnicodeChar *textUnitMeanBuffer,
									uint16_t sizeUnitMean, touchgfx::TextAreaWithOneWildcard *textUnitMean)
{
	switch (measure->meanUnit)
	{
	case HZ:
		Unicode::snprintf(textMeanBuffer, sizeMean, "%d.%d %d", *total, *fraction1, *fraction2);
	    Unicode::strncpy(textUnitMeanBuffer, Hz.c_str(), sizeUnitMean - 1);
	   	break;
	case KILO:
	    Unicode::snprintf(textMeanBuffer, sizeMean, "%d.%d %d", *total, *fraction1, *fraction2);
	   	Unicode::strncpy(textUnitMeanBuffer, kHz.c_str(), sizeUnitMean - 1);
	   	break;
	case MEGA:
	    Unicode::snprintf(textMeanBuffer, sizeMean, "%d.%d %d", *total, *fraction1, *fraction2);
	   	Unicode::strncpy(textUnitMeanBuffer, MHz.c_str(), sizeUnitMean - 1);
	   	break;
	case GIGA:
	    Unicode::snprintf(textMeanBuffer, sizeMean, "%d.%d %d", *total, *fraction1, *fraction2);
	   	Unicode::strncpy(textUnitMeanBuffer, GHz.c_str(), sizeUnitMean - 1);
	   	break;
	default:
	    Unicode::snprintf(textMeanBuffer, sizeMean, "%d.%d %d", 0, 0, 0);
	   	Unicode::strncpy(textUnitMeanBuffer, kHz.c_str(), sizeUnitMean - 1);
	   	break;
	}
	textMean->invalidate();
	textUnitMean->invalidate();
}

void FreqModeView::setStdDevResultFreq(touchgfx::Unicode::UnicodeChar *textStdDevBuffer, uint16_t sizeStdDev, touchgfx::TextAreaWithOneWildcard *textStdDev,
							touchgfx::Unicode::UnicodeChar *textUnitStdDevBuffer, uint16_t sizeUnitStdDev, touchgfx::TextAreaWithOneWildcard *textUnitStdDev,
							MeasFreq_t *measure, int *total, int *fraction)
{
	Unicode::snprintf(textStdDevBuffer, sizeStdDev, "%d.%d", *total, *fraction);
	textStdDev->invalidate();
	switch (measure->stdDevUnit)
	{
	case PICO:
		Unicode::strncpy(textUnitStdDevBuffer, pHz.c_str(), sizeUnitStdDev - 1);
	    break;
	case NANO:
	    Unicode::strncpy(textUnitStdDevBuffer, nHz.c_str(), sizeUnitStdDev - 1);
	   	break;
	case MICRO:
	    Unicode::strncpy(textUnitStdDevBuffer, uHz.c_str(), sizeUnitStdDev - 1);
	   	break;
	case MILLI:
	    Unicode::strncpy(textUnitStdDevBuffer, mHz.c_str(), sizeUnitStdDev - 1);
	   	break;
	case HZ:
	    Unicode::strncpy(textUnitStdDevBuffer, Hz.c_str(), sizeUnitStdDev - 1);
	    break;
	default:
	    Unicode::strncpy(textUnitStdDevBuffer, pHz.c_str(), sizeUnitStdDev - 1);
	   	break;
	}
	textUnitStdDev->invalidate();
}
