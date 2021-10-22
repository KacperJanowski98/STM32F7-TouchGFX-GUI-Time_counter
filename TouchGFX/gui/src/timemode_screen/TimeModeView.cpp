#include <gui/timemode_screen/TimeModeView.hpp>

TimeModeView::TimeModeView()
{

}

void TimeModeView::setupScreen()
{
    TimeModeViewBase::setupScreen();

    char ps[] = "ps";
    char ns[] = "ns";
    char us[] = "us";
    char ms[] = "ms";
    char sec[] = "s";

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
    Unicode::snprintf(textStamps1stopBuffer, TEXTSTAMPS1STOP_SIZE, "%d", TimeBackend.TiSetup1.stopIn);
    textStamps1stop.invalidate();
    if ((TimeBackend.TiSetup1.stopIn - TimeBackend.TiSetup1.startIn) == 0 || TimeBackend.TiSetup1.tiState == false)
    {
    	textStamps1startVal.setVisible(false);
    	textStamps1stopVal.setVisible(false);
    	textSample1.setVisible(false);
    }
    else
    {
    	textStamps1startVal.setVisible(true);
    	textStamps1stopVal.setVisible(true);
    	textSample1.setVisible(true);
        Unicode::snprintf(textStamps1startValBuffer, TEXTSTAMPS1STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);//
        textStamps1startVal.invalidate();
        Unicode::snprintf(textStamps1stopValBuffer, TEXTSTAMPS1STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);//
        textStamps1stopVal.invalidate();
        Unicode::snprintf(textSample1Buffer, TEXTSAMPLE1_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);//
        textSample1.invalidate();
    }

    Unicode::snprintf(textStamps2startBuffer, TEXTSTAMPS2START_SIZE, "%d", TimeBackend.TiSetup2.startIn);
    textStamps2start.invalidate();
    Unicode::snprintf(textStamps2stopBuffer, TEXTSTAMPS2STOP_SIZE, "%d", TimeBackend.TiSetup2.stopIn);
    textStamps2stop.invalidate();
    if ((TimeBackend.TiSetup2.stopIn - TimeBackend.TiSetup2.startIn) == 0 || TimeBackend.TiSetup2.tiState == false)
    {
    	textStamps2startVal.setVisible(false);
    	textStamps2stopVal.setVisible(false);
    	textSample2.setVisible(false);
    }
    else
    {
    	textStamps2startVal.setVisible(true);
    	textStamps2stopVal.setVisible(true);
    	textSample2.setVisible(true);
        Unicode::snprintf(textStamps2startValBuffer, TEXTSTAMPS2STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps2startVal.invalidate();
        Unicode::snprintf(textStamps2stopValBuffer, TEXTSTAMPS2STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps2stopVal.invalidate();
        Unicode::snprintf(textSample2Buffer, TEXTSAMPLE2_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textSample2.invalidate();
    }

    Unicode::snprintf(textStamps3startBuffer, TEXTSTAMPS3START_SIZE, "%d", TimeBackend.TiSetup3.startIn);
    textStamps3start.invalidate();
    Unicode::snprintf(textStamps3stopBuffer, TEXTSTAMPS3STOP_SIZE, "%d", TimeBackend.TiSetup3.stopIn);
    textStamps3stop.invalidate();
    if ((TimeBackend.TiSetup3.stopIn - TimeBackend.TiSetup3.startIn) == 0 || TimeBackend.TiSetup3.tiState == false)
    {
    	textStamps3startVal.setVisible(false);
    	textStamps3stopVal.setVisible(false);
    	textSample3.setVisible(false);
    }
    else
    {
    	textStamps3startVal.setVisible(true);
    	textStamps3stopVal.setVisible(true);
    	textSample3.setVisible(true);
        Unicode::snprintf(textStamps3startValBuffer, TEXTSTAMPS3STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps3startVal.invalidate();
        Unicode::snprintf(textStamps3stopValBuffer, TEXTSTAMPS3STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps3stopVal.invalidate();
        Unicode::snprintf(textSample3Buffer, TEXTSAMPLE3_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textSample3.invalidate();
    }

    Unicode::snprintf(textStamps4startBuffer, TEXTSTAMPS4START_SIZE, "%d", TimeBackend.TiSetup4.startIn);
    textStamps4start.invalidate();
    Unicode::snprintf(textStamps4stopBuffer, TEXTSTAMPS4STOP_SIZE, "%d", TimeBackend.TiSetup4.stopIn);
    textStamps4stop.invalidate();
    if ((TimeBackend.TiSetup4.stopIn - TimeBackend.TiSetup4.startIn) == 0 || TimeBackend.TiSetup4.tiState == false)
    {
    	textStamps4startVal.setVisible(false);
    	textStamps4stopVal.setVisible(false);
    	textSample4.setVisible(false);
    }
    else
    {
    	textStamps4startVal.setVisible(true);
    	textStamps4stopVal.setVisible(true);
    	textSample4.setVisible(true);
        Unicode::snprintf(textStamps4startValBuffer, TEXTSTAMPS4STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps4startVal.invalidate();
        Unicode::snprintf(textStamps4stopValBuffer, TEXTSTAMPS4STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps4stopVal.invalidate();
        Unicode::snprintf(textSample4Buffer, TEXTSAMPLE4_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textSample4.invalidate();
    }

    Unicode::snprintf(textStamps5startBuffer, TEXTSTAMPS5START_SIZE, "%d", TimeBackend.TiSetup5.startIn);
    textStamps5start.invalidate();
    Unicode::snprintf(textStamps5stopBuffer, TEXTSTAMPS5STOP_SIZE, "%d", TimeBackend.TiSetup5.stopIn);
    textStamps5stop.invalidate();
    if ((TimeBackend.TiSetup5.stopIn - TimeBackend.TiSetup5.startIn) == 0 || TimeBackend.TiSetup5.tiState == false)
    {
    	textStamps5startVal.setVisible(false);
    	textStamps5stopVal.setVisible(false);
    	textSample5.setVisible(false);
    }
    else
    {
    	textStamps5startVal.setVisible(true);
    	textStamps5stopVal.setVisible(true);
    	textSample5.setVisible(true);
        Unicode::snprintf(textStamps5startValBuffer, TEXTSTAMPS5STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps5startVal.invalidate();
        Unicode::snprintf(textStamps5stopValBuffer, TEXTSTAMPS5STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps5stopVal.invalidate();
        Unicode::snprintf(textSample5Buffer, TEXTSAMPLE5_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textSample5.invalidate();
    }

    Unicode::snprintf(textStamps6startBuffer, TEXTSTAMPS6START_SIZE, "%d", TimeBackend.TiSetup6.startIn);
    textStamps6start.invalidate();
    Unicode::snprintf(textStamps6stopBuffer, TEXTSTAMPS6STOP_SIZE, "%d", TimeBackend.TiSetup6.stopIn);
    textStamps6stop.invalidate();
    if ((TimeBackend.TiSetup6.stopIn - TimeBackend.TiSetup6.startIn) == 0 || TimeBackend.TiSetup6.tiState == false)
    {
    	textStamps6startVal.setVisible(false);
    	textStamps6stopVal.setVisible(false);
    	textSample6.setVisible(false);
    }
    else
    {
    	textStamps6startVal.setVisible(true);
    	textStamps6stopVal.setVisible(true);
    	textSample6.setVisible(true);
        Unicode::snprintf(textStamps6startValBuffer, TEXTSTAMPS6STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps6startVal.invalidate();
        Unicode::snprintf(textStamps6stopValBuffer, TEXTSTAMPS6STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps6stopVal.invalidate();
        Unicode::snprintf(textSample6Buffer, TEXTSAMPLE6_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textSample6.invalidate();
    }

    Unicode::snprintf(textStamps7startBuffer, TEXTSTAMPS7START_SIZE, "%d", TimeBackend.TiSetup7.startIn);
    textStamps7start.invalidate();
    Unicode::snprintf(textStamps7stopBuffer, TEXTSTAMPS7STOP_SIZE, "%d", TimeBackend.TiSetup7.stopIn);
    textStamps7stop.invalidate();
    if ((TimeBackend.TiSetup7.stopIn - TimeBackend.TiSetup7.startIn) == 0 || TimeBackend.TiSetup7.tiState == false)
    {
    	textStamps7startVal.setVisible(false);
    	textStamps7stopVal.setVisible(false);
    	textSample7.setVisible(false);
    }
    else
    {
    	textStamps7startVal.setVisible(true);
    	textStamps7stopVal.setVisible(true);
    	textSample7.setVisible(true);
        Unicode::snprintf(textStamps7startValBuffer, TEXTSTAMPS7STARTVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps7startVal.invalidate();
        Unicode::snprintf(textStamps7stopValBuffer, TEXTSTAMPS7STOPVAL_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textStamps7stopVal.invalidate();
        Unicode::snprintf(textSample7Buffer, TEXTSAMPLE7_SIZE, "%d", TimeBackend.TimeSession.stampsNumber);
        textSample7.invalidate();
    }

    // Mean

    calculateFormatMeanTime(ResultTimeBackend.measure1.mean, &m_total_ti1, &m_frac1_ti1, &m_frac2_ti1);
    switch (ResultTimeBackend.measure1.meanUnit)
    {
    case PICO:
        Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.%d %d", m_total_ti1, m_frac1_ti1, m_frac2_ti1);
        Unicode::strncpy(textUnitMean1Buffer, (char*)ps, TEXTUNITMEAN1_SIZE - 1);
    case NANO:
        Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.%d %d", m_total_ti1, m_frac1_ti1, m_frac2_ti1);
        Unicode::strncpy(textUnitMean1Buffer, (char*)ns, TEXTUNITMEAN1_SIZE - 1);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.000 %d %d", m_total_ti1, m_frac1_ti1, m_frac2_ti1);
        Unicode::strncpy(textUnitMean1Buffer, (char*)us, TEXTUNITMEAN1_SIZE - 1);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.000 000 %d %d", m_total_ti1, m_frac1_ti1, m_frac2_ti1);
        Unicode::strncpy(textUnitMean1Buffer, (char*)ms, TEXTUNITMEAN1_SIZE - 1);
        break;
    case SEC:
        Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.000 000 000 %d %d", m_total_ti1, m_frac1_ti1, m_frac2_ti1);
        Unicode::strncpy(textUnitMean1Buffer, (char*)sec, TEXTUNITMEAN1_SIZE - 1);
        break;
    default:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL1_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean1Buffer, (char*)ns, TEXTUNITMEAN1_SIZE - 1);
    	break;
    }
    textMeanVal1.invalidate();
    textUnitMean1.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure2.mean, &m_total_ti2, &m_frac1_ti2, &m_frac2_ti2);
    switch (ResultTimeBackend.measure2.meanUnit)
    {
    case PICO:
        Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.%d %d", m_total_ti2, m_frac1_ti2, m_frac2_ti2);
        Unicode::strncpy(textUnitMean2Buffer, (char*)ps, TEXTUNITMEAN2_SIZE - 1);
    case NANO:
        Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.%d %d", m_total_ti2, m_frac1_ti2, m_frac2_ti2);
        Unicode::strncpy(textUnitMean2Buffer, (char*)ns, TEXTUNITMEAN2_SIZE - 1);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.000 %d %d", m_total_ti2, m_frac1_ti2, m_frac2_ti2);
        Unicode::strncpy(textUnitMean2Buffer, (char*)us, TEXTUNITMEAN2_SIZE - 1);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.000 000 %d %d", m_total_ti2, m_frac1_ti2, m_frac2_ti2);
        Unicode::strncpy(textUnitMean2Buffer, (char*)ms, TEXTUNITMEAN2_SIZE - 1);
        break;
    case SEC:
        Unicode::snprintf(textMeanVal2Buffer, TEXTMEANVAL2_SIZE, "%d.000 000 000 %d %d", m_total_ti2, m_frac1_ti2, m_frac2_ti2);
        Unicode::strncpy(textUnitMean2Buffer, (char*)sec, TEXTUNITMEAN2_SIZE - 1);
        break;
    default:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL2_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean2Buffer, (char*)ns, TEXTUNITMEAN2_SIZE - 1);
    	break;
    }
    textMeanVal2.invalidate();
    textUnitMean2.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure3.mean, &m_total_ti3, &m_frac1_ti3, &m_frac2_ti3);
    switch (ResultTimeBackend.measure3.meanUnit)
    {
    case PICO:
        Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.%d %d", m_total_ti3, m_frac1_ti3, m_frac2_ti3);
        Unicode::strncpy(textUnitMean3Buffer, (char*)ps, TEXTUNITMEAN3_SIZE - 1);
    case NANO:
        Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.%d %d", m_total_ti3, m_frac1_ti3, m_frac2_ti3);
        Unicode::strncpy(textUnitMean3Buffer, (char*)ns, TEXTUNITMEAN3_SIZE - 1);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.000 %d %d", m_total_ti3, m_frac1_ti3, m_frac2_ti3);
        Unicode::strncpy(textUnitMean3Buffer, (char*)us, TEXTUNITMEAN3_SIZE - 1);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.000 000 %d %d", m_total_ti3, m_frac1_ti3, m_frac2_ti3);
        Unicode::strncpy(textUnitMean3Buffer, (char*)ms, TEXTUNITMEAN3_SIZE - 1);
        break;
    case SEC:
        Unicode::snprintf(textMeanVal3Buffer, TEXTMEANVAL3_SIZE, "%d.000 000 000 %d %d", m_total_ti3, m_frac1_ti3, m_frac2_ti3);
        Unicode::strncpy(textUnitMean3Buffer, (char*)sec, TEXTUNITMEAN3_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL3_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean3Buffer, (char*)ns, TEXTUNITMEAN3_SIZE - 1);
    	break;
    }
    textMeanVal3.invalidate();
    textUnitMean3.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure4.mean, &m_total_ti4, &m_frac1_ti4, &m_frac2_ti4);
    switch (ResultTimeBackend.measure4.meanUnit)
    {
    case PICO:
        Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.%d %d", m_total_ti4, m_frac1_ti4, m_frac2_ti4);
        Unicode::strncpy(textUnitMean4Buffer, (char*)ps, TEXTUNITMEAN4_SIZE - 1);
    case NANO:
        Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.%d %d", m_total_ti4, m_frac1_ti4, m_frac2_ti4);
        Unicode::strncpy(textUnitMean4Buffer, (char*)ns, TEXTUNITMEAN4_SIZE - 1);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.000 %d %d", m_total_ti4, m_frac1_ti4, m_frac2_ti4);
        Unicode::strncpy(textUnitMean4Buffer, (char*)us, TEXTUNITMEAN4_SIZE - 1);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.000 000 %d %d", m_total_ti4, m_frac1_ti4, m_frac2_ti4);
        Unicode::strncpy(textUnitMean4Buffer, (char*)ms, TEXTUNITMEAN4_SIZE - 1);
        break;
    case SEC:
        Unicode::snprintf(textMeanVal4Buffer, TEXTMEANVAL4_SIZE, "%d.000 000 000 %d %d", m_total_ti4, m_frac1_ti4, m_frac2_ti4);
        Unicode::strncpy(textUnitMean4Buffer, (char*)sec, TEXTUNITMEAN4_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL4_SIZE, "%d.%d %d", 0, 0, 0);
        Unicode::strncpy(textUnitMean4Buffer, (char*)ns, TEXTUNITMEAN4_SIZE - 1);
    	break;
    }
    textMeanVal4.invalidate();
    textUnitMean4.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure5.mean, &m_total_ti5, &m_frac1_ti5, &m_frac2_ti5);
    switch (ResultTimeBackend.measure5.meanUnit)
    {
    case PICO:
        Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.%d %d", m_total_ti5, m_frac1_ti5, m_frac2_ti5);
        Unicode::strncpy(textUnitMean5Buffer, (char*)ps, TEXTUNITMEAN5_SIZE - 1);
    case NANO:
        Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.%d %d", m_total_ti5, m_frac1_ti5, m_frac2_ti5);
        Unicode::strncpy(textUnitMean5Buffer, (char*)ns, TEXTUNITMEAN5_SIZE - 1);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.000 %d %d", m_total_ti5, m_frac1_ti5, m_frac2_ti5);
        Unicode::strncpy(textUnitMean5Buffer, (char*)us, TEXTUNITMEAN5_SIZE - 1);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.000 000 %d %d", m_total_ti5, m_frac1_ti5, m_frac2_ti5);
        Unicode::strncpy(textUnitMean5Buffer, (char*)ms, TEXTUNITMEAN5_SIZE - 1);
        break;
    case SEC:
        Unicode::snprintf(textMeanVal5Buffer, TEXTMEANVAL5_SIZE, "%d.000 000 000 %d %d", m_total_ti5, m_frac1_ti5, m_frac2_ti5);
        Unicode::strncpy(textUnitMean5Buffer, (char*)sec, TEXTUNITMEAN5_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL5_SIZE, "%d.%d %d", 0, 0, 0);
        Unicode::strncpy(textUnitMean5Buffer, (char*)ns, TEXTUNITMEAN5_SIZE - 1);
    	break;
    }
    textMeanVal5.invalidate();
    textUnitMean5.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure6.mean, &m_total_ti6, &m_frac1_ti6, &m_frac2_ti6);
    switch (ResultTimeBackend.measure6.meanUnit)
    {
    case PICO:
        Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.%d %d", m_total_ti6, m_frac1_ti6, m_frac2_ti6);
        Unicode::strncpy(textUnitMean6Buffer, (char*)ps, TEXTUNITMEAN6_SIZE - 1);
    case NANO:
        Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.%d %d", m_total_ti6, m_frac1_ti6, m_frac2_ti6);
        Unicode::strncpy(textUnitMean6Buffer, (char*)ns, TEXTUNITMEAN6_SIZE - 1);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.000 %d %d", m_total_ti6, m_frac1_ti6, m_frac2_ti6);
        Unicode::strncpy(textUnitMean6Buffer, (char*)us, TEXTUNITMEAN6_SIZE - 1);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.000 000 %d %d", m_total_ti6, m_frac1_ti6, m_frac2_ti6);
        Unicode::strncpy(textUnitMean6Buffer, (char*)ms, TEXTUNITMEAN6_SIZE - 1);
        break;
    case SEC:
        Unicode::snprintf(textMeanVal6Buffer, TEXTMEANVAL6_SIZE, "%d.000 000 000 %d %d", m_total_ti6, m_frac1_ti6, m_frac2_ti6);
        Unicode::strncpy(textUnitMean6Buffer, (char*)sec, TEXTUNITMEAN6_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL6_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean6Buffer, (char*)ns, TEXTUNITMEAN6_SIZE - 1);
    	break;
    }
    textMeanVal6.invalidate();
    textUnitMean6.invalidate();

    calculateFormatMeanTime(ResultTimeBackend.measure7.mean, &m_total_ti7, &m_frac1_ti7, &m_frac2_ti7);
    Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", m_total_ti7, m_frac1_ti7, m_frac2_ti7);
    switch (ResultTimeBackend.measure7.meanUnit)
    {
    case PICO:
    	Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", m_total_ti7, m_frac1_ti7, m_frac2_ti7);
    	Unicode::strncpy(textUnitMean7Buffer, (char*)ps, TEXTUNITMEAN7_SIZE - 1);
    case NANO:
    	Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", m_total_ti7, m_frac1_ti7, m_frac2_ti7);
    	Unicode::strncpy(textUnitMean7Buffer, (char*)ns, TEXTUNITMEAN7_SIZE - 1);
        break;
    case MICRO:
        Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.000 %d %d", m_total_ti7, m_frac1_ti7, m_frac2_ti7);
        Unicode::strncpy(textUnitMean7Buffer, (char*)us, TEXTUNITMEAN7_SIZE - 1);
        break;
    case MILLI:
        Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.000 000 %d %d", m_total_ti7, m_frac1_ti7, m_frac2_ti7);
        Unicode::strncpy(textUnitMean7Buffer, (char*)ms, TEXTUNITMEAN7_SIZE - 1);
        break;
    case SEC:
        Unicode::snprintf(textMeanVal7Buffer, TEXTMEANVAL7_SIZE, "%d.000 000 000 %d %d", m_total_ti7, m_frac1_ti7, m_frac2_ti7);
        Unicode::strncpy(textUnitMean7Buffer, (char*)sec, TEXTUNITMEAN7_SIZE - 1);
    	break;
    default:
    	Unicode::snprintf(textMeanVal1Buffer, TEXTMEANVAL7_SIZE, "%d.%d %d", 0, 0, 0);
    	Unicode::strncpy(textUnitMean7Buffer, (char*)ns, TEXTUNITMEAN7_SIZE - 1);
    	break;
    }
    textMeanVal7.invalidate();
    textUnitMean7.invalidate();

    // StdDev

    calculateFormatStdDevTime(ResultTimeBackend.measure1.stdDev, &m_totalStdDev1, &m_fracStdDev1);
    Unicode::snprintf(textStdDevVal1Buffer, TEXTSTDDEVVAL1_SIZE, "%d.%d", m_totalStdDev1, m_fracStdDev1);
    textStdDevVal1.invalidate();
    switch(ResultTimeBackend.measure1.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)ps, TEXTUNITSD1_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)ns, TEXTUNITSD1_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)us, TEXTUNITSD1_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)ms, TEXTUNITSD1_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD1Buffer, (char*)ps, TEXTUNITSD1_SIZE - 1);
    	break;
    }
    textUnitSD1.invalidate();

    calculateFormatStdDevTime(ResultTimeBackend.measure2.stdDev, &m_totalStdDev2, &m_fracStdDev2);
    Unicode::snprintf(textStdDevVal2Buffer, TEXTSTDDEVVAL2_SIZE, "%d.%d", m_totalStdDev2, m_fracStdDev2);
    textStdDevVal2.invalidate();
    switch(ResultTimeBackend.measure2.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)ps, TEXTUNITSD2_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)ns, TEXTUNITSD2_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)us, TEXTUNITSD2_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)ms, TEXTUNITSD2_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD2Buffer, (char*)ps, TEXTUNITSD2_SIZE - 1);
    	break;
    }
    textUnitSD2.invalidate();

    calculateFormatStdDevTime(ResultTimeBackend.measure3.stdDev, &m_totalStdDev3, &m_fracStdDev3);
    Unicode::snprintf(textStdDevVal3Buffer, TEXTSTDDEVVAL3_SIZE, "%d.%d", m_totalStdDev3, m_fracStdDev3);
    textStdDevVal3.invalidate();
    switch(ResultTimeBackend.measure3.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)ps, TEXTUNITSD3_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)ns, TEXTUNITSD3_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)us, TEXTUNITSD3_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)ms, TEXTUNITSD3_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD3Buffer, (char*)ps, TEXTUNITSD3_SIZE - 1);
    	break;
    }
    textUnitSD3.invalidate();

    calculateFormatStdDevTime(ResultTimeBackend.measure4.stdDev, &m_totalStdDev4, &m_fracStdDev4);
    Unicode::snprintf(textStdDevVal4Buffer, TEXTSTDDEVVAL4_SIZE, "%d.%d", m_totalStdDev4, m_fracStdDev4);
    textStdDevVal4.invalidate();
    switch(ResultTimeBackend.measure4.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)ps, TEXTUNITSD4_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)ns, TEXTUNITSD4_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)us, TEXTUNITSD4_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)ms, TEXTUNITSD4_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD4Buffer, (char*)ps, TEXTUNITSD4_SIZE - 1);
    	break;
    }
    textUnitSD4.invalidate();

    calculateFormatStdDevTime(ResultTimeBackend.measure5.stdDev, &m_totalStdDev5, &m_fracStdDev5);
    Unicode::snprintf(textStdDevVal5Buffer, TEXTSTDDEVVAL5_SIZE, "%d.%d", m_totalStdDev5, m_fracStdDev5);
    textStdDevVal5.invalidate();
    switch(ResultTimeBackend.measure5.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)ps, TEXTUNITSD5_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)ns, TEXTUNITSD5_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)us, TEXTUNITSD5_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)ms, TEXTUNITSD5_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD5Buffer, (char*)ps, TEXTUNITSD5_SIZE - 1);
    	break;
    }
    textUnitSD5.invalidate();

    calculateFormatStdDevTime(ResultTimeBackend.measure6.stdDev, &m_totalStdDev6, &m_fracStdDev6);
    Unicode::snprintf(textStdDevVal6Buffer, TEXTSTDDEVVAL6_SIZE, "%d.%d", m_totalStdDev6, m_fracStdDev6);
    textStdDevVal6.invalidate();
    switch(ResultTimeBackend.measure6.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)ps, TEXTUNITSD6_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)ns, TEXTUNITSD6_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)us, TEXTUNITSD6_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)ms, TEXTUNITSD6_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD6Buffer, (char*)ps, TEXTUNITSD6_SIZE - 1);
    	break;
    }
    textUnitSD6.invalidate();

    calculateFormatStdDevTime(ResultTimeBackend.measure7.stdDev, &m_totalStdDev7, &m_fracStdDev7);
    Unicode::snprintf(textStdDevVal7Buffer, TEXTSTDDEVVAL7_SIZE, "%d.%d", m_totalStdDev7, m_fracStdDev7);
    textStdDevVal7.invalidate();
    switch(ResultTimeBackend.measure2.stdDevUnit)
    {
    case PICO:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)ps, TEXTUNITSD7_SIZE - 1);
    	break;
    case NANO:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)ns, TEXTUNITSD7_SIZE - 1);
    	break;
    case MICRO:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)us, TEXTUNITSD7_SIZE - 1);
    	break;
    case MILLI:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)ms, TEXTUNITSD7_SIZE - 1);
    	break;
    default:
    	Unicode::strncpy(textUnitSD7Buffer, (char*)ps, TEXTUNITSD7_SIZE - 1);
    	break;
    }
    textUnitSD7.invalidate();
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
