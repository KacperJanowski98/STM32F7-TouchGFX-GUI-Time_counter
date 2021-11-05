#include <gui/timemode_screen/TimeModeView.hpp>

TimeModeView::TimeModeView()
{

}

void TimeModeView::setupScreen()
{
    TimeModeViewBase::setupScreen();

    ps = "ps";
    ns = "ns";
    us = "us";
    ms = "ms";
    sec = "s";

    m_total_ti1 = 0;
    m_frac1_ti1 = 0;
    m_frac2_ti1 = 0;
    m_total_ti2 = 0;
    m_frac1_ti2 = 0;
    m_frac2_ti2 = 0;
    m_total_ti3 = 0;
    m_frac1_ti3 = 0;
    m_frac2_ti3 = 0;
    m_total_ti4 = 0;
    m_frac1_ti4 = 0;
    m_frac2_ti4 = 0;
    m_total_ti5 = 0;
    m_frac1_ti5 = 0;
    m_frac2_ti5 = 0;
    m_total_ti6 = 0;
    m_frac1_ti6 = 0;
    m_frac2_ti6 = 0;
    m_total_ti7 = 0;
    m_frac1_ti7 = 0;
    m_frac2_ti7 = 0;
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

    // Label

    setLabelTi(textTi1startBuffer, TEXTTI1START_SIZE, TimeBackend.TiSetup1.startIn, &textTi1start);
    setLabelTi(textTi1stopBuffer, TEXTTI1STOP_SIZE, TimeBackend.TiSetup1.stopIn, &textTi1stop);

    setLabelTi(textTi2startBuffer, TEXTTI2START_SIZE, TimeBackend.TiSetup2.startIn, &textTi2start);
    setLabelTi(textTi2stopBuffer, TEXTTI2STOP_SIZE, TimeBackend.TiSetup2.stopIn, &textTi2stop);

    setLabelTi(textTi3startBuffer, TEXTTI3START_SIZE, TimeBackend.TiSetup3.startIn, &textTi3start);
    setLabelTi(textTi3stopBuffer, TEXTTI3STOP_SIZE, TimeBackend.TiSetup3.stopIn, &textTi3stop);

    setLabelTi(textTi4startBuffer, TEXTTI4START_SIZE, TimeBackend.TiSetup4.startIn, &textTi4start);
    setLabelTi(textTi4stopBuffer, TEXTTI4STOP_SIZE, TimeBackend.TiSetup4.stopIn, &textTi4stop);

    setLabelTi(textTi5startBuffer, TEXTTI5START_SIZE, TimeBackend.TiSetup5.startIn, &textTi5start);
    setLabelTi(textTi5stopBuffer, TEXTTI5STOP_SIZE, TimeBackend.TiSetup5.stopIn, &textTi5stop);

    setLabelTi(textTi6startBuffer, TEXTTI6START_SIZE, TimeBackend.TiSetup6.startIn, &textTi6start);
    setLabelTi(textTi6stopBuffer, TEXTTI6STOP_SIZE, TimeBackend.TiSetup6.stopIn, &textTi6stop);

    setLabelTi(textTi7startBuffer, TEXTTI7START_SIZE, TimeBackend.TiSetup7.startIn, &textTi7start);
    setLabelTi(textTi7stopBuffer, TEXTTI7STOP_SIZE, TimeBackend.TiSetup7.stopIn, &textTi7stop);

    // Stamps and sample

    setLabelTi(textStamps1startBuffer, TEXTSTAMPS1START_SIZE, TimeBackend.TiSetup1.startIn, &textStamps1start);
    setLabelTi(textStamps1stopBuffer, TEXTSTAMPS1STOP_SIZE, TimeBackend.TiSetup1.stopIn, &textStamps1stop);
    setStampsSampleTi(textStamps1startValBuffer, TEXTSTAMPS1STARTVAL_SIZE, &textStamps1startVal, textStamps1stopValBuffer, TEXTSTAMPS1STOPVAL_SIZE,
    		&textStamps1stopVal, textSample1Buffer, TEXTSAMPLE1_SIZE, &textSample1, &TimeBackend.TiSetup1, &TimeBackend.TimeSession);

    setLabelTi(textStamps2startBuffer, TEXTSTAMPS2START_SIZE, TimeBackend.TiSetup2.startIn, &textStamps2start);
    setLabelTi(textStamps2stopBuffer, TEXTSTAMPS2STOP_SIZE, TimeBackend.TiSetup2.stopIn, &textStamps2stop);
    setStampsSampleTi(textStamps2startValBuffer, TEXTSTAMPS2STARTVAL_SIZE, &textStamps2startVal, textStamps2stopValBuffer, TEXTSTAMPS2STOPVAL_SIZE,
    		&textStamps2stopVal, textSample2Buffer, TEXTSAMPLE2_SIZE, &textSample2, &TimeBackend.TiSetup2, &TimeBackend.TimeSession);

    setLabelTi(textStamps3startBuffer, TEXTSTAMPS3START_SIZE, TimeBackend.TiSetup3.startIn, &textStamps3start);
    setLabelTi(textStamps3stopBuffer, TEXTSTAMPS3STOP_SIZE, TimeBackend.TiSetup3.stopIn, &textStamps3stop);
    setStampsSampleTi(textStamps3startValBuffer, TEXTSTAMPS3STARTVAL_SIZE, &textStamps3startVal, textStamps3stopValBuffer, TEXTSTAMPS3STOPVAL_SIZE,
    		&textStamps3stopVal, textSample3Buffer, TEXTSAMPLE3_SIZE, &textSample3, &TimeBackend.TiSetup3, &TimeBackend.TimeSession);

    setLabelTi(textStamps4startBuffer, TEXTSTAMPS4START_SIZE, TimeBackend.TiSetup4.startIn, &textStamps4start);
    setLabelTi(textStamps4stopBuffer, TEXTSTAMPS4STOP_SIZE, TimeBackend.TiSetup4.stopIn, &textStamps4stop);
    setStampsSampleTi(textStamps4startValBuffer, TEXTSTAMPS4STARTVAL_SIZE, &textStamps4startVal, textStamps4stopValBuffer, TEXTSTAMPS4STOPVAL_SIZE,
    		&textStamps4stopVal, textSample4Buffer, TEXTSAMPLE4_SIZE, &textSample4, &TimeBackend.TiSetup4, &TimeBackend.TimeSession);

    setLabelTi(textStamps5startBuffer, TEXTSTAMPS5START_SIZE, TimeBackend.TiSetup5.startIn, &textStamps5start);
    setLabelTi(textStamps5stopBuffer, TEXTSTAMPS5STOP_SIZE, TimeBackend.TiSetup5.stopIn, &textStamps5stop);
    setStampsSampleTi(textStamps5startValBuffer, TEXTSTAMPS5STARTVAL_SIZE, &textStamps5startVal, textStamps5stopValBuffer, TEXTSTAMPS5STOPVAL_SIZE,
    		&textStamps5stopVal, textSample5Buffer, TEXTSAMPLE5_SIZE, &textSample5, &TimeBackend.TiSetup5, &TimeBackend.TimeSession);

    setLabelTi(textStamps6startBuffer, TEXTSTAMPS6START_SIZE, TimeBackend.TiSetup6.startIn, &textStamps6start);
    setLabelTi(textStamps6stopBuffer, TEXTSTAMPS6STOP_SIZE, TimeBackend.TiSetup6.stopIn, &textStamps6stop);
    setStampsSampleTi(textStamps6startValBuffer, TEXTSTAMPS6STARTVAL_SIZE, &textStamps6startVal, textStamps6stopValBuffer, TEXTSTAMPS6STOPVAL_SIZE,
    		&textStamps6stopVal, textSample6Buffer, TEXTSAMPLE6_SIZE, &textSample6, &TimeBackend.TiSetup6, &TimeBackend.TimeSession);

    setLabelTi(textStamps7startBuffer, TEXTSTAMPS7START_SIZE, TimeBackend.TiSetup7.startIn, &textStamps7start);
    setLabelTi(textStamps7stopBuffer, TEXTSTAMPS7STOP_SIZE, TimeBackend.TiSetup7.stopIn, &textStamps7stop);
    setStampsSampleTi(textStamps7startValBuffer, TEXTSTAMPS7STARTVAL_SIZE, &textStamps7startVal, textStamps7stopValBuffer, TEXTSTAMPS7STOPVAL_SIZE,
    		&textStamps7stopVal, textSample7Buffer, TEXTSAMPLE7_SIZE, &textSample7, &TimeBackend.TiSetup7, &TimeBackend.TimeSession);

    // Mean

    calculateFormatMeanTime(ResultTimeBackend.measure1.mean, &m_total_ti1, &m_frac1_ti1, &m_frac2_ti1);
    setMeanResultTime(&ResultTimeBackend.measure1, &m_total_ti1, &m_frac1_ti1, &m_frac2_ti1, textMeanVal1Buffer, TEXTMEANVAL1_SIZE, &textMeanVal1,
    		textUnitMean1Buffer, TEXTUNITMEAN1_SIZE, &textUnitMean1);

    calculateFormatMeanTime(ResultTimeBackend.measure2.mean, &m_total_ti2, &m_frac1_ti2, &m_frac2_ti2);
    setMeanResultTime(&ResultTimeBackend.measure2, &m_total_ti2, &m_frac1_ti2, &m_frac2_ti2, textMeanVal2Buffer, TEXTMEANVAL2_SIZE, &textMeanVal2,
    		textUnitMean2Buffer, TEXTUNITMEAN2_SIZE, &textUnitMean2);

    calculateFormatMeanTime(ResultTimeBackend.measure3.mean, &m_total_ti3, &m_frac1_ti3, &m_frac2_ti3);
    setMeanResultTime(&ResultTimeBackend.measure3, &m_total_ti3, &m_frac1_ti3, &m_frac2_ti3, textMeanVal3Buffer, TEXTMEANVAL3_SIZE, &textMeanVal3,
    		textUnitMean3Buffer, TEXTUNITMEAN3_SIZE, &textUnitMean3);

    calculateFormatMeanTime(ResultTimeBackend.measure4.mean, &m_total_ti4, &m_frac1_ti4, &m_frac2_ti4);
    setMeanResultTime(&ResultTimeBackend.measure4, &m_total_ti4, &m_frac1_ti4, &m_frac2_ti4, textMeanVal4Buffer, TEXTMEANVAL4_SIZE, &textMeanVal4,
    		textUnitMean4Buffer, TEXTUNITMEAN4_SIZE, &textUnitMean4);

    calculateFormatMeanTime(ResultTimeBackend.measure5.mean, &m_total_ti5, &m_frac1_ti5, &m_frac2_ti5);
    setMeanResultTime(&ResultTimeBackend.measure5, &m_total_ti5, &m_frac1_ti5, &m_frac2_ti5, textMeanVal5Buffer, TEXTMEANVAL5_SIZE, &textMeanVal5,
    		textUnitMean5Buffer, TEXTUNITMEAN5_SIZE, &textUnitMean5);

    calculateFormatMeanTime(ResultTimeBackend.measure6.mean, &m_total_ti6, &m_frac1_ti6, &m_frac2_ti6);
    setMeanResultTime(&ResultTimeBackend.measure6, &m_total_ti6, &m_frac1_ti6, &m_frac2_ti6, textMeanVal6Buffer, TEXTMEANVAL6_SIZE, &textMeanVal6,
    		textUnitMean6Buffer, TEXTUNITMEAN6_SIZE, &textUnitMean6);

    calculateFormatMeanTime(ResultTimeBackend.measure7.mean, &m_total_ti7, &m_frac1_ti7, &m_frac2_ti7);
    setMeanResultTime(&ResultTimeBackend.measure7, &m_total_ti7, &m_frac1_ti7, &m_frac2_ti7, textMeanVal7Buffer, TEXTMEANVAL7_SIZE, &textMeanVal7,
    		textUnitMean7Buffer, TEXTUNITMEAN7_SIZE, &textUnitMean7);

    // StdDev

    calculateFormatStdDevTime(ResultTimeBackend.measure1.stdDev, &m_totalStdDev1, &m_fracStdDev1);
    setStdDevResultTime(textStdDevVal1Buffer, TEXTSTDDEVVAL1_SIZE, &textStdDevVal1, textUnitSD1Buffer, TEXTUNITSD1_SIZE, &textUnitSD1,
    					&ResultTimeBackend.measure1, &m_totalStdDev1, &m_fracStdDev1);

    calculateFormatStdDevTime(ResultTimeBackend.measure2.stdDev, &m_totalStdDev2, &m_fracStdDev2);
    setStdDevResultTime(textStdDevVal2Buffer, TEXTSTDDEVVAL2_SIZE, &textStdDevVal2, textUnitSD2Buffer, TEXTUNITSD2_SIZE, &textUnitSD2,
    					&ResultTimeBackend.measure2, &m_totalStdDev2, &m_fracStdDev2);

    calculateFormatStdDevTime(ResultTimeBackend.measure3.stdDev, &m_totalStdDev3, &m_fracStdDev3);
    setStdDevResultTime(textStdDevVal3Buffer, TEXTSTDDEVVAL3_SIZE, &textStdDevVal3, textUnitSD3Buffer, TEXTUNITSD3_SIZE, &textUnitSD3,
    					&ResultTimeBackend.measure3, &m_totalStdDev3, &m_fracStdDev3);

    calculateFormatStdDevTime(ResultTimeBackend.measure4.stdDev, &m_totalStdDev4, &m_fracStdDev4);
    setStdDevResultTime(textStdDevVal4Buffer, TEXTSTDDEVVAL4_SIZE, &textStdDevVal4, textUnitSD4Buffer, TEXTUNITSD4_SIZE, &textUnitSD4,
    					&ResultTimeBackend.measure4, &m_totalStdDev4, &m_fracStdDev4);

    calculateFormatStdDevTime(ResultTimeBackend.measure5.stdDev, &m_totalStdDev5, &m_fracStdDev5);
    setStdDevResultTime(textStdDevVal5Buffer, TEXTSTDDEVVAL5_SIZE, &textStdDevVal5, textUnitSD5Buffer, TEXTUNITSD5_SIZE, &textUnitSD5,
    					&ResultTimeBackend.measure5, &m_totalStdDev5, &m_fracStdDev5);

    calculateFormatStdDevTime(ResultTimeBackend.measure6.stdDev, &m_totalStdDev6, &m_fracStdDev6);
    setStdDevResultTime(textStdDevVal6Buffer, TEXTSTDDEVVAL6_SIZE, &textStdDevVal6, textUnitSD6Buffer, TEXTUNITSD6_SIZE, &textUnitSD6,
    					&ResultTimeBackend.measure6, &m_totalStdDev6, &m_fracStdDev6);

    calculateFormatStdDevTime(ResultTimeBackend.measure7.stdDev, &m_totalStdDev7, &m_fracStdDev7);
    setStdDevResultTime(textStdDevVal7Buffer, TEXTSTDDEVVAL7_SIZE, &textStdDevVal7, textUnitSD7Buffer, TEXTUNITSD7_SIZE, &textUnitSD7,
    					&ResultTimeBackend.measure7, &m_totalStdDev7, &m_fracStdDev7);
}

void TimeModeView::tearDownScreen()
{
    TimeModeViewBase::tearDownScreen();
}

void TimeModeView::ResetParameter()
{
	presenter->askForReset();
	TimeModeView::draw();
	TimeModeView::setupScreen();
}

void TimeModeView::updateUIContinuousTime()
{
	TimeModeView::draw();
	TimeModeView::setupScreen();
}

void TimeModeView::calculateFormatMeanTime(float mean, int *pTotal, int *pFrac1, int *pFrac2)
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

void TimeModeView::calculateFormatStdDevTime(float stdDev, int *pTotal, int *pFrac)
{
	*pTotal = stdDev;
	float tempFrac = stdDev - *pTotal;
	*pFrac = trunc(tempFrac * 100);
}

// do podmieienia w metodzie setup
void TimeModeView::setLabelTi(touchgfx::Unicode::UnicodeChar *textBuffer, uint16_t size, uint8_t startIn, touchgfx::TextAreaWithOneWildcard *text)
{
	Unicode::snprintf(textBuffer, size, "%d", startIn);
	text->invalidate();
}

void TimeModeView::setStampsSampleTi(touchgfx::Unicode::UnicodeChar *textBufferStart, uint16_t sizeStart, touchgfx::TextAreaWithOneWildcard *textStart,
									touchgfx::Unicode::UnicodeChar *textBufferStop, uint16_t sizeStop, touchgfx::TextAreaWithOneWildcard *textStop,
									touchgfx::Unicode::UnicodeChar *textBufferSample, uint16_t sizeSample, touchgfx::TextAreaWithOneWildcard *textSample,
									TimeTi_t *Ti, SessionSetup_t *session)
{
    if ((Ti->stopIn - Ti->startIn) == 0 || Ti->tiState == false)
    {
    	textStart->setVisible(false);
    	textStop->setVisible(false);
    	textSample->setVisible(false);
    }
    else
    {
    	textStart->setVisible(true);
    	textStop->setVisible(true);
    	textSample->setVisible(true);
        Unicode::snprintf(textBufferStart, sizeStart, "%d", session->stampsNumber);
        Unicode::snprintf(textBufferStop, sizeStop, "%d", session->stampsNumber);
        Unicode::snprintf(textBufferSample, sizeSample, "%d", session->stampsNumber);
    }
    textStart->invalidate();
    textStop->invalidate();
    textSample->invalidate();
}

void TimeModeView::setMeanResultTime(MeasTime_t *measure, int *total, int *fraction1, int *fraction2, touchgfx::Unicode::UnicodeChar *textMeanBuffer,
								uint16_t sizeMean, touchgfx::TextAreaWithOneWildcard *textMean, touchgfx::Unicode::UnicodeChar *textUnitMeanBuffer,
								uint16_t sizeUnitMean, touchgfx::TextAreaWithOneWildcard *textUnitMean)
{

    switch (measure->meanUnit)
    {
    case PICO:
        Unicode::snprintf(textMeanBuffer, sizeMean, "%d.%d %d", *total, *fraction1, *fraction2);
        Unicode::strncpy(textUnitMeanBuffer, ps.c_str(), sizeUnitMean - 1);
    case NANO:
        Unicode::snprintf(textMeanBuffer, sizeMean, "%d.%d %d", *total, *fraction1, *fraction2);
        Unicode::strncpy(textUnitMeanBuffer, ns.c_str(), sizeUnitMean - 1);
        break;
    case MICRO:
        Unicode::snprintf(textMeanBuffer, sizeMean, "%d.000 %d %d", *total, *fraction1, *fraction2);
        Unicode::strncpy(textUnitMeanBuffer, us.c_str(), sizeUnitMean - 1);
        break;
    case MILLI:
        Unicode::snprintf(textMeanBuffer, sizeMean, "%d.000 000 %d %d", *total, *fraction1, *fraction2);
        Unicode::strncpy(textUnitMeanBuffer, ms.c_str(), sizeUnitMean - 1);
        break;
    case SEC:
        Unicode::snprintf(textMeanBuffer, sizeMean, "%d.000 000 000 %d %d", *total, *fraction1, *fraction2);
        Unicode::strncpy(textUnitMeanBuffer, sec.c_str(), sizeUnitMean - 1);
        break;
    default:
    	Unicode::snprintf(textMeanBuffer, sizeMean, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMeanBuffer, ns.c_str(), sizeUnitMean - 1);
    	break;
    }
    textMean->invalidate();
    textUnitMean->invalidate();
}

void TimeModeView::setStdDevResultTime(touchgfx::Unicode::UnicodeChar *textStdDevBuffer, uint16_t sizeStdDev, touchgfx::TextAreaWithOneWildcard *textStdDev,
								touchgfx::Unicode::UnicodeChar *textUnitStdDevBuffer, uint16_t sizeUnitStdDev, touchgfx::TextAreaWithOneWildcard *textUnitStdDev,
								MeasTime_t *measure, int *total, int *fraction)
{
    Unicode::snprintf(textStdDevBuffer, sizeStdDev, "%d.%d", *total, *fraction);
    textStdDev->invalidate();
    switch(measure->stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitStdDevBuffer, ps.c_str(), sizeUnitStdDev - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitStdDevBuffer, ns.c_str(), sizeUnitStdDev - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitStdDevBuffer, us.c_str(), sizeUnitStdDev - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitStdDevBuffer, ms.c_str(), sizeUnitStdDev - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitStdDevBuffer, ps.c_str(), sizeUnitStdDev - 1);
    	break;
    }
    textUnitStdDev->invalidate();
}
