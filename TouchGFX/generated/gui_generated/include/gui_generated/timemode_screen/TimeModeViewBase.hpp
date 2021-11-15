/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TIMEMODEVIEWBASE_HPP
#define TIMEMODEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/timemode_screen/TimeModePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>

class TimeModeViewBase : public touchgfx::View<TimeModePresenter>
{
public:
    TimeModeViewBase();
    virtual ~TimeModeViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void ResetParameter()
    {
        // Override and implement this function in TimeMode
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box boxBackgroundTime;
    touchgfx::Button buttonBackMenuT;
    touchgfx::Button buttonConfig;
    touchgfx::Button buttonReset;
    touchgfx::TextAreaWithOneWildcard textTi1start;
    touchgfx::TextAreaWithOneWildcard textTi1stop;
    touchgfx::TextAreaWithOneWildcard textTi2start;
    touchgfx::TextAreaWithOneWildcard textTi2stop;
    touchgfx::TextAreaWithOneWildcard textTi3start;
    touchgfx::TextAreaWithOneWildcard textTi3stop;
    touchgfx::TextAreaWithOneWildcard textTi4start;
    touchgfx::TextAreaWithOneWildcard textTi4stop;
    touchgfx::TextAreaWithOneWildcard textTi5start;
    touchgfx::TextAreaWithOneWildcard textTi5stop;
    touchgfx::TextAreaWithOneWildcard textTi6start;
    touchgfx::TextAreaWithOneWildcard textTi6stop;
    touchgfx::TextAreaWithOneWildcard textTi7start;
    touchgfx::TextAreaWithOneWildcard textTi7stop;
    touchgfx::TextAreaWithOneWildcard textStamps1start;
    touchgfx::TextArea textStampsLabel;
    touchgfx::TextArea textSampleLabel;
    touchgfx::TextAreaWithOneWildcard textStamps1stop;
    touchgfx::TextAreaWithOneWildcard textSample1;
    touchgfx::TextArea textMeanLabel;
    touchgfx::TextArea textStdDevLabel;
    touchgfx::TextAreaWithOneWildcard textStamps2start;
    touchgfx::TextAreaWithOneWildcard textStamps2stop;
    touchgfx::TextAreaWithOneWildcard textStamps3start;
    touchgfx::TextAreaWithOneWildcard textStamps3stop;
    touchgfx::TextAreaWithOneWildcard textStamps4start;
    touchgfx::TextAreaWithOneWildcard textStamps4stop;
    touchgfx::TextAreaWithOneWildcard textStamps5start;
    touchgfx::TextAreaWithOneWildcard textStamps5stop;
    touchgfx::TextAreaWithOneWildcard textStamps6start;
    touchgfx::TextAreaWithOneWildcard textStamps6stop;
    touchgfx::TextAreaWithOneWildcard textStamps7start;
    touchgfx::TextAreaWithOneWildcard textStamps7stop;
    touchgfx::TextAreaWithOneWildcard textSample2;
    touchgfx::TextAreaWithOneWildcard textSample3;
    touchgfx::TextAreaWithOneWildcard textSample4;
    touchgfx::TextAreaWithOneWildcard textSample5;
    touchgfx::TextAreaWithOneWildcard textSample6;
    touchgfx::TextAreaWithOneWildcard textSample7;
    touchgfx::TextAreaWithOneWildcard textMeanVal1;
    touchgfx::TextAreaWithOneWildcard textStdDevVal1;
    touchgfx::TextAreaWithOneWildcard textMeanVal2;
    touchgfx::TextAreaWithOneWildcard textMeanVal3;
    touchgfx::TextAreaWithOneWildcard textMeanVal4;
    touchgfx::TextAreaWithOneWildcard textMeanVal5;
    touchgfx::TextAreaWithOneWildcard textMeanVal6;
    touchgfx::TextAreaWithOneWildcard textMeanVal7;
    touchgfx::TextAreaWithOneWildcard textStdDevVal2;
    touchgfx::TextAreaWithOneWildcard textStdDevVal3;
    touchgfx::TextAreaWithOneWildcard textStdDevVal4;
    touchgfx::TextAreaWithOneWildcard textStdDevVal5;
    touchgfx::TextAreaWithOneWildcard textStdDevVal6;
    touchgfx::TextAreaWithOneWildcard textStdDevVal7;
    touchgfx::TextAreaWithOneWildcard textStamps1startVal;
    touchgfx::TextAreaWithOneWildcard textStamps1stopVal;
    touchgfx::TextAreaWithOneWildcard textStamps2startVal;
    touchgfx::TextAreaWithOneWildcard textStamps2stopVal;
    touchgfx::TextAreaWithOneWildcard textStamps3startVal;
    touchgfx::TextAreaWithOneWildcard textStamps3stopVal;
    touchgfx::TextAreaWithOneWildcard textStamps4startVal;
    touchgfx::TextAreaWithOneWildcard textStamps4stopVal;
    touchgfx::TextAreaWithOneWildcard textStamps5startVal;
    touchgfx::TextAreaWithOneWildcard textStamps5stopVal;
    touchgfx::TextAreaWithOneWildcard textStamps6startVal;
    touchgfx::TextAreaWithOneWildcard textStamps6stopVal;
    touchgfx::TextAreaWithOneWildcard textStamps7startVal;
    touchgfx::TextAreaWithOneWildcard textStamps7stopVal;
    touchgfx::TextAreaWithOneWildcard textUnitSD1;
    touchgfx::TextAreaWithOneWildcard textUnitSD2;
    touchgfx::TextAreaWithOneWildcard textUnitSD3;
    touchgfx::TextAreaWithOneWildcard textUnitSD4;
    touchgfx::TextAreaWithOneWildcard textUnitSD5;
    touchgfx::TextAreaWithOneWildcard textUnitSD6;
    touchgfx::TextAreaWithOneWildcard textUnitSD7;
    touchgfx::TextAreaWithOneWildcard textUnitMean1;
    touchgfx::TextAreaWithOneWildcard textUnitMean2;
    touchgfx::TextAreaWithOneWildcard textUnitMean3;
    touchgfx::TextAreaWithOneWildcard textUnitMean4;
    touchgfx::TextAreaWithOneWildcard textUnitMean5;
    touchgfx::TextAreaWithOneWildcard textUnitMean6;
    touchgfx::TextAreaWithOneWildcard textUnitMean7;
    touchgfx::TextArea textLabelTi1;
    touchgfx::TextArea textLabelTi2;
    touchgfx::TextArea textLabelTi3;
    touchgfx::TextArea textLabelTi4;
    touchgfx::TextArea textLabelTi5;
    touchgfx::TextArea textLabelTi6;
    touchgfx::TextArea textLabelTi7;
    touchgfx::Button buttonHistogram;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::TextArea labelTimeConfig;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTTI1START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi1startBuffer[TEXTTI1START_SIZE];
    static const uint16_t TEXTTI1STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi1stopBuffer[TEXTTI1STOP_SIZE];
    static const uint16_t TEXTTI2START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi2startBuffer[TEXTTI2START_SIZE];
    static const uint16_t TEXTTI2STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi2stopBuffer[TEXTTI2STOP_SIZE];
    static const uint16_t TEXTTI3START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi3startBuffer[TEXTTI3START_SIZE];
    static const uint16_t TEXTTI3STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi3stopBuffer[TEXTTI3STOP_SIZE];
    static const uint16_t TEXTTI4START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi4startBuffer[TEXTTI4START_SIZE];
    static const uint16_t TEXTTI4STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi4stopBuffer[TEXTTI4STOP_SIZE];
    static const uint16_t TEXTTI5START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi5startBuffer[TEXTTI5START_SIZE];
    static const uint16_t TEXTTI5STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi5stopBuffer[TEXTTI5STOP_SIZE];
    static const uint16_t TEXTTI6START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi6startBuffer[TEXTTI6START_SIZE];
    static const uint16_t TEXTTI6STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi6stopBuffer[TEXTTI6STOP_SIZE];
    static const uint16_t TEXTTI7START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi7startBuffer[TEXTTI7START_SIZE];
    static const uint16_t TEXTTI7STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi7stopBuffer[TEXTTI7STOP_SIZE];
    static const uint16_t TEXTSTAMPS1START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps1startBuffer[TEXTSTAMPS1START_SIZE];
    static const uint16_t TEXTSTAMPS1STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps1stopBuffer[TEXTSTAMPS1STOP_SIZE];
    static const uint16_t TEXTSAMPLE1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textSample1Buffer[TEXTSAMPLE1_SIZE];
    static const uint16_t TEXTSTAMPS2START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps2startBuffer[TEXTSTAMPS2START_SIZE];
    static const uint16_t TEXTSTAMPS2STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps2stopBuffer[TEXTSTAMPS2STOP_SIZE];
    static const uint16_t TEXTSTAMPS3START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps3startBuffer[TEXTSTAMPS3START_SIZE];
    static const uint16_t TEXTSTAMPS3STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps3stopBuffer[TEXTSTAMPS3STOP_SIZE];
    static const uint16_t TEXTSTAMPS4START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps4startBuffer[TEXTSTAMPS4START_SIZE];
    static const uint16_t TEXTSTAMPS4STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps4stopBuffer[TEXTSTAMPS4STOP_SIZE];
    static const uint16_t TEXTSTAMPS5START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps5startBuffer[TEXTSTAMPS5START_SIZE];
    static const uint16_t TEXTSTAMPS5STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps5stopBuffer[TEXTSTAMPS5STOP_SIZE];
    static const uint16_t TEXTSTAMPS6START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps6startBuffer[TEXTSTAMPS6START_SIZE];
    static const uint16_t TEXTSTAMPS6STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps6stopBuffer[TEXTSTAMPS6STOP_SIZE];
    static const uint16_t TEXTSTAMPS7START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps7startBuffer[TEXTSTAMPS7START_SIZE];
    static const uint16_t TEXTSTAMPS7STOP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps7stopBuffer[TEXTSTAMPS7STOP_SIZE];
    static const uint16_t TEXTSAMPLE2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textSample2Buffer[TEXTSAMPLE2_SIZE];
    static const uint16_t TEXTSAMPLE3_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textSample3Buffer[TEXTSAMPLE3_SIZE];
    static const uint16_t TEXTSAMPLE4_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textSample4Buffer[TEXTSAMPLE4_SIZE];
    static const uint16_t TEXTSAMPLE5_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textSample5Buffer[TEXTSAMPLE5_SIZE];
    static const uint16_t TEXTSAMPLE6_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textSample6Buffer[TEXTSAMPLE6_SIZE];
    static const uint16_t TEXTSAMPLE7_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textSample7Buffer[TEXTSAMPLE7_SIZE];
    static const uint16_t TEXTMEANVAL1_SIZE = 22;
    touchgfx::Unicode::UnicodeChar textMeanVal1Buffer[TEXTMEANVAL1_SIZE];
    static const uint16_t TEXTSTDDEVVAL1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStdDevVal1Buffer[TEXTSTDDEVVAL1_SIZE];
    static const uint16_t TEXTMEANVAL2_SIZE = 22;
    touchgfx::Unicode::UnicodeChar textMeanVal2Buffer[TEXTMEANVAL2_SIZE];
    static const uint16_t TEXTMEANVAL3_SIZE = 22;
    touchgfx::Unicode::UnicodeChar textMeanVal3Buffer[TEXTMEANVAL3_SIZE];
    static const uint16_t TEXTMEANVAL4_SIZE = 22;
    touchgfx::Unicode::UnicodeChar textMeanVal4Buffer[TEXTMEANVAL4_SIZE];
    static const uint16_t TEXTMEANVAL5_SIZE = 22;
    touchgfx::Unicode::UnicodeChar textMeanVal5Buffer[TEXTMEANVAL5_SIZE];
    static const uint16_t TEXTMEANVAL6_SIZE = 22;
    touchgfx::Unicode::UnicodeChar textMeanVal6Buffer[TEXTMEANVAL6_SIZE];
    static const uint16_t TEXTMEANVAL7_SIZE = 22;
    touchgfx::Unicode::UnicodeChar textMeanVal7Buffer[TEXTMEANVAL7_SIZE];
    static const uint16_t TEXTSTDDEVVAL2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStdDevVal2Buffer[TEXTSTDDEVVAL2_SIZE];
    static const uint16_t TEXTSTDDEVVAL3_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStdDevVal3Buffer[TEXTSTDDEVVAL3_SIZE];
    static const uint16_t TEXTSTDDEVVAL4_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStdDevVal4Buffer[TEXTSTDDEVVAL4_SIZE];
    static const uint16_t TEXTSTDDEVVAL5_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStdDevVal5Buffer[TEXTSTDDEVVAL5_SIZE];
    static const uint16_t TEXTSTDDEVVAL6_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStdDevVal6Buffer[TEXTSTDDEVVAL6_SIZE];
    static const uint16_t TEXTSTDDEVVAL7_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStdDevVal7Buffer[TEXTSTDDEVVAL7_SIZE];
    static const uint16_t TEXTSTAMPS1STARTVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps1startValBuffer[TEXTSTAMPS1STARTVAL_SIZE];
    static const uint16_t TEXTSTAMPS1STOPVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps1stopValBuffer[TEXTSTAMPS1STOPVAL_SIZE];
    static const uint16_t TEXTSTAMPS2STARTVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps2startValBuffer[TEXTSTAMPS2STARTVAL_SIZE];
    static const uint16_t TEXTSTAMPS2STOPVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps2stopValBuffer[TEXTSTAMPS2STOPVAL_SIZE];
    static const uint16_t TEXTSTAMPS3STARTVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps3startValBuffer[TEXTSTAMPS3STARTVAL_SIZE];
    static const uint16_t TEXTSTAMPS3STOPVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps3stopValBuffer[TEXTSTAMPS3STOPVAL_SIZE];
    static const uint16_t TEXTSTAMPS4STARTVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps4startValBuffer[TEXTSTAMPS4STARTVAL_SIZE];
    static const uint16_t TEXTSTAMPS4STOPVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps4stopValBuffer[TEXTSTAMPS4STOPVAL_SIZE];
    static const uint16_t TEXTSTAMPS5STARTVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps5startValBuffer[TEXTSTAMPS5STARTVAL_SIZE];
    static const uint16_t TEXTSTAMPS5STOPVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps5stopValBuffer[TEXTSTAMPS5STOPVAL_SIZE];
    static const uint16_t TEXTSTAMPS6STARTVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps6startValBuffer[TEXTSTAMPS6STARTVAL_SIZE];
    static const uint16_t TEXTSTAMPS6STOPVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps6stopValBuffer[TEXTSTAMPS6STOPVAL_SIZE];
    static const uint16_t TEXTSTAMPS7STARTVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps7startValBuffer[TEXTSTAMPS7STARTVAL_SIZE];
    static const uint16_t TEXTSTAMPS7STOPVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStamps7stopValBuffer[TEXTSTAMPS7STOPVAL_SIZE];
    static const uint16_t TEXTUNITSD1_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitSD1Buffer[TEXTUNITSD1_SIZE];
    static const uint16_t TEXTUNITSD2_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitSD2Buffer[TEXTUNITSD2_SIZE];
    static const uint16_t TEXTUNITSD3_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitSD3Buffer[TEXTUNITSD3_SIZE];
    static const uint16_t TEXTUNITSD4_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitSD4Buffer[TEXTUNITSD4_SIZE];
    static const uint16_t TEXTUNITSD5_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitSD5Buffer[TEXTUNITSD5_SIZE];
    static const uint16_t TEXTUNITSD6_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitSD6Buffer[TEXTUNITSD6_SIZE];
    static const uint16_t TEXTUNITSD7_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitSD7Buffer[TEXTUNITSD7_SIZE];
    static const uint16_t TEXTUNITMEAN1_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitMean1Buffer[TEXTUNITMEAN1_SIZE];
    static const uint16_t TEXTUNITMEAN2_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitMean2Buffer[TEXTUNITMEAN2_SIZE];
    static const uint16_t TEXTUNITMEAN3_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitMean3Buffer[TEXTUNITMEAN3_SIZE];
    static const uint16_t TEXTUNITMEAN4_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitMean4Buffer[TEXTUNITMEAN4_SIZE];
    static const uint16_t TEXTUNITMEAN5_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitMean5Buffer[TEXTUNITMEAN5_SIZE];
    static const uint16_t TEXTUNITMEAN6_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitMean6Buffer[TEXTUNITMEAN6_SIZE];
    static const uint16_t TEXTUNITMEAN7_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textUnitMean7Buffer[TEXTUNITMEAN7_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TimeModeViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // TIMEMODEVIEWBASE_HPP
