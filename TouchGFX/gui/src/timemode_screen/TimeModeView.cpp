#include <gui/timemode_screen/TimeModeView.hpp>

TimeModeView::TimeModeView()
{

}

void TimeModeView::setupScreen()
{
    TimeModeViewBase::setupScreen();

    // Label

    Unicode::snprintf(textTi1startBuffer, TEXTTI1START_SIZE, "%d", TimeBackend.TiSetup1.startIn);
    textTi1start.invalidate();
    Unicode::snprintf(textTi1stopBuffer, TEXTTI1STOP_SIZE, "%d", TimeBackend.TiSetup1.stopIn);
    textTi1stop.invalidate();

    Unicode::snprintf(textTi2startBuffer, TEXTTI2START_SIZE, "%d", TimeBackend.TiSetup2.startIn);
    textTi2start.invalidate();
    Unicode::snprintf(textTi2stopBuffer, TEXTTI2STOP_SIZE, "%d", TimeBackend.TiSetup2.stopIn);
    textTi2stop.invalidate();

    Unicode::snprintf(textTi3startBuffer, TEXTTI3START_SIZE, "%d", TimeBackend.TiSetup3.startIn);
    textTi3start.invalidate();
    Unicode::snprintf(textTi3stopBuffer, TEXTTI3STOP_SIZE, "%d", TimeBackend.TiSetup3.stopIn);
    textTi3stop.invalidate();

    Unicode::snprintf(textTi4startBuffer, TEXTTI4START_SIZE, "%d", TimeBackend.TiSetup4.startIn);
    textTi4start.invalidate();
    Unicode::snprintf(textTi4stopBuffer, TEXTTI4STOP_SIZE, "%d", TimeBackend.TiSetup4.stopIn);
    textTi4stop.invalidate();

    Unicode::snprintf(textTi5startBuffer, TEXTTI5START_SIZE, "%d", TimeBackend.TiSetup5.startIn);
    textTi5start.invalidate();
    Unicode::snprintf(textTi5stopBuffer, TEXTTI5STOP_SIZE, "%d", TimeBackend.TiSetup5.stopIn);
    textTi5stop.invalidate();

    Unicode::snprintf(textTi6startBuffer, TEXTTI6START_SIZE, "%d", TimeBackend.TiSetup6.startIn);
    textTi6start.invalidate();
    Unicode::snprintf(textTi6stopBuffer, TEXTTI6STOP_SIZE, "%d", TimeBackend.TiSetup6.stopIn);
    textTi6stop.invalidate();

    Unicode::snprintf(textTi7startBuffer, TEXTTI7START_SIZE, "%d", TimeBackend.TiSetup7.startIn);
    textTi7start.invalidate();
    Unicode::snprintf(textTi7stopBuffer, TEXTTI7STOP_SIZE, "%d", TimeBackend.TiSetup7.stopIn);
    textTi7stop.invalidate();

    // Stamps and sample

    Unicode::snprintf(textStamps1startBuffer, TEXTSTAMPS1START_SIZE, "%d", TimeBackend.TiSetup1.startIn);
    textStamps1start.invalidate();
    Unicode::snprintf(textStamps1startValBuffer, TEXTSTAMPS1STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps1startVal.invalidate();
    Unicode::snprintf(textStamps1stopBuffer, TEXTSTAMPS1STOP_SIZE, "%d", TimeBackend.TiSetup1.stopIn);
    textStamps1stop.invalidate();
    Unicode::snprintf(textStamps1stopValBuffer, TEXTSTAMPS1STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps1stopVal.invalidate();
    Unicode::snprintf(textSample1Buffer, TEXTSAMPLE1_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textSample1.invalidate();

    Unicode::snprintf(textStamps2startBuffer, TEXTSTAMPS2START_SIZE, "%d", TimeBackend.TiSetup2.startIn);
    textStamps2start.invalidate();
    Unicode::snprintf(textStamps2startValBuffer, TEXTSTAMPS2STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps2startVal.invalidate();
    Unicode::snprintf(textStamps2stopBuffer, TEXTSTAMPS2STOP_SIZE, "%d", TimeBackend.TiSetup2.stopIn);
    textStamps2stop.invalidate();
    Unicode::snprintf(textStamps2stopValBuffer, TEXTSTAMPS2STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps2stopVal.invalidate();
    Unicode::snprintf(textSample2Buffer, TEXTSAMPLE2_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textSample2.invalidate();

    Unicode::snprintf(textStamps3startBuffer, TEXTSTAMPS3START_SIZE, "%d", TimeBackend.TiSetup3.startIn);
    textStamps3start.invalidate();
    Unicode::snprintf(textStamps3startValBuffer, TEXTSTAMPS3STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps3startVal.invalidate();
    Unicode::snprintf(textStamps3stopBuffer, TEXTSTAMPS3STOP_SIZE, "%d", TimeBackend.TiSetup3.stopIn);
    textStamps3stop.invalidate();
    Unicode::snprintf(textStamps3stopValBuffer, TEXTSTAMPS3STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps3stopVal.invalidate();
    Unicode::snprintf(textSample3Buffer, TEXTSAMPLE3_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textSample3.invalidate();

    Unicode::snprintf(textStamps4startBuffer, TEXTSTAMPS4START_SIZE, "%d", TimeBackend.TiSetup4.startIn);
    textStamps4start.invalidate();
    Unicode::snprintf(textStamps4startValBuffer, TEXTSTAMPS4STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps4startVal.invalidate();
    Unicode::snprintf(textStamps4stopBuffer, TEXTSTAMPS4STOP_SIZE, "%d", TimeBackend.TiSetup4.stopIn);
    textStamps4stop.invalidate();
    Unicode::snprintf(textStamps4stopValBuffer, TEXTSTAMPS4STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps4stopVal.invalidate();
    Unicode::snprintf(textSample4Buffer, TEXTSAMPLE4_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textSample4.invalidate();

    Unicode::snprintf(textStamps5startBuffer, TEXTSTAMPS5START_SIZE, "%d", TimeBackend.TiSetup5.startIn);
    textStamps5start.invalidate();
    Unicode::snprintf(textStamps5startValBuffer, TEXTSTAMPS5STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps5startVal.invalidate();
    Unicode::snprintf(textStamps5stopBuffer, TEXTSTAMPS5STOP_SIZE, "%d", TimeBackend.TiSetup5.stopIn);
    textStamps5stop.invalidate();
    Unicode::snprintf(textStamps5stopValBuffer, TEXTSTAMPS5STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps5stopVal.invalidate();
    Unicode::snprintf(textSample5Buffer, TEXTSAMPLE5_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textSample5.invalidate();

    Unicode::snprintf(textStamps6startBuffer, TEXTSTAMPS6START_SIZE, "%d", TimeBackend.TiSetup6.startIn);
    textStamps6start.invalidate();
    Unicode::snprintf(textStamps6startValBuffer, TEXTSTAMPS6STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps6startVal.invalidate();
    Unicode::snprintf(textStamps6stopBuffer, TEXTSTAMPS6STOP_SIZE, "%d", TimeBackend.TiSetup6.stopIn);
    textStamps6stop.invalidate();
    Unicode::snprintf(textStamps6stopValBuffer, TEXTSTAMPS6STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps6stopVal.invalidate();
    Unicode::snprintf(textSample6Buffer, TEXTSAMPLE6_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textSample6.invalidate();

    Unicode::snprintf(textStamps7startBuffer, TEXTSTAMPS7START_SIZE, "%d", TimeBackend.TiSetup7.startIn);
    textStamps7start.invalidate();
    Unicode::snprintf(textStamps7startValBuffer, TEXTSTAMPS7STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps7startVal.invalidate();
    Unicode::snprintf(textStamps7stopBuffer, TEXTSTAMPS7STOP_SIZE, "%d", TimeBackend.TiSetup7.stopIn);
    textStamps7stop.invalidate();
    Unicode::snprintf(textStamps7stopValBuffer, TEXTSTAMPS7STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textStamps7stopVal.invalidate();
    Unicode::snprintf(textSample7Buffer, TEXTSAMPLE7_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
    textSample7.invalidate();

    // Mean

    calculateFormatMeanTime(ResultTimeBackend.measure1.mean, &m_total_ti1, &m_frac1_ti1, &m_frac2_ti1);
    switch (ResultTimeBackend.measure1.meanUnit)
    {
    case NANO:
        Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.%d %d", m_total_ti1, m_frac1_ti1, m_frac2_ti1);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.000 %d %d", m_total_ti1, m_frac1_ti1, m_frac2_ti1);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.000 000 %d %d", m_total_ti1, m_frac1_ti1, m_frac2_ti1);
        break;
    default:
    	break;
    }
    textMeanVal1.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure2.mean, &m_total_ti2, &m_frac1_ti2, &m_frac2_ti2);
    switch (ResultTimeBackend.measure2.meanUnit)
    {
    case NANO:
        Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.%d %d", m_total_ti2, m_frac1_ti2, m_frac2_ti2);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.000 %d %d", m_total_ti2, m_frac1_ti2, m_frac2_ti2);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.000 000 %d %d", m_total_ti2, m_frac1_ti2, m_frac2_ti2);
        break;
    default:
    	break;
    }
    textMeanVal2.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure3.mean, &m_total_ti3, &m_frac1_ti3, &m_frac2_ti3);
    switch (ResultTimeBackend.measure3.meanUnit)
    {
    case NANO:
        Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.%d %d", m_total_ti3, m_frac1_ti3, m_frac2_ti3);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.000 %d %d", m_total_ti3, m_frac1_ti3, m_frac2_ti3);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.000 000 %d %d", m_total_ti3, m_frac1_ti3, m_frac2_ti3);
        break;
    default:
    	break;
    }
    textMeanVal3.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure4.mean, &m_total_ti4, &m_frac1_ti4, &m_frac2_ti4);
    switch (ResultTimeBackend.measure4.meanUnit)
    {
    case NANO:
        Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.%d %d", m_total_ti4, m_frac1_ti4, m_frac2_ti4);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.000 %d %d", m_total_ti4, m_frac1_ti4, m_frac2_ti4);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.000 000 %d %d", m_total_ti4, m_frac1_ti4, m_frac2_ti4);
        break;
    default:
    	break;
    }
    textMeanVal4.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure5.mean, &m_total_ti5, &m_frac1_ti5, &m_frac2_ti5);
    switch (ResultTimeBackend.measure5.meanUnit)
    {
    case NANO:
        Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.%d %d", m_total_ti5, m_frac1_ti5, m_frac2_ti5);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.000 %d %d", m_total_ti5, m_frac1_ti5, m_frac2_ti5);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.000 000 %d %d", m_total_ti5, m_frac1_ti5, m_frac2_ti5);
        break;
    default:
    	break;
    }
    textMeanVal5.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure6.mean, &m_total_ti6, &m_frac1_ti6, &m_frac2_ti6);
    switch (ResultTimeBackend.measure6.meanUnit)
    {
    case NANO:
        Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.%d %d", m_total_ti6, m_frac1_ti6, m_frac2_ti6);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.000 %d %d", m_total_ti6, m_frac1_ti6, m_frac2_ti6);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.000 000 %d %d", m_total_ti6, m_frac1_ti6, m_frac2_ti6);
        break;
    default:
    	break;
    }
    textMeanVal6.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure7.mean, &m_total_ti7, &m_frac1_ti7, &m_frac2_ti7);
    switch (ResultTimeBackend.measure7.meanUnit)
    {
    case NANO:
        Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", m_total_ti7, m_frac1_ti7, m_frac2_ti7);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.000 %d %d", m_total_ti7, m_frac1_ti7, m_frac2_ti7);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.000 000 %d %d", m_total_ti7, m_frac1_ti7, m_frac2_ti7);
        break;
    default:
    	break;
    }
    textMeanVal7.invalidate();

    // StdDev

}

void TimeModeView::tearDownScreen()
{
    TimeModeViewBase::tearDownScreen();
    // reset variables
}

void TimeModeView::calculateFormatMeanTime(float mean, int *pTotal, int *pFrac1, int *pFrac2)
{
    int a = 0, b = 0, c = 0;
    *pTotal = mean;
    float tmpFrac = mean - *pTotal;
    int tmpInt2 = trunc(tmpFrac * 1000000);
    *pFrac1 = tmpInt2;
    *pFrac1 /= 1000;
    a = tmpInt2 / 100 % 10;
    b = tmpInt2 / 10  % 10;
    c = tmpInt2 / 1 % 10;
    *pFrac2 = a * 100 + b * 10 + c;
}
