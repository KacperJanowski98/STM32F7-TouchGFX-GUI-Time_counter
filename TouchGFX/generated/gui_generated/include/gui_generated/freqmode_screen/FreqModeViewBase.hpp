/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FREQMODEVIEWBASE_HPP
#define FREQMODEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/freqmode_screen/FreqModePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class FreqModeViewBase : public touchgfx::View<FreqModePresenter>
{
public:
    FreqModeViewBase();
    virtual ~FreqModeViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box boxBackgroungFreq;
    touchgfx::Button buttonToMenuF;
    touchgfx::Button buttonConfig;
    touchgfx::Button buttonReset;
    touchgfx::TextAreaWithOneWildcard textTi1start;
    touchgfx::TextAreaWithOneWildcard textTi2start;
    touchgfx::TextAreaWithOneWildcard textTi3start;
    touchgfx::TextAreaWithOneWildcard textTi4start;
    touchgfx::TextAreaWithOneWildcard textTi5start;
    touchgfx::TextAreaWithOneWildcard textTi6start;
    touchgfx::TextAreaWithOneWildcard textTi7start;
    touchgfx::TextArea textLabelFreq1;
    touchgfx::TextArea textLabelFreq2;
    touchgfx::TextArea textLabelFreq3;
    touchgfx::TextArea textLabelFreq4;
    touchgfx::TextArea textLabelFreq5;
    touchgfx::TextArea textLabelFreq6;
    touchgfx::TextArea textLabelFreq7;
    touchgfx::TextAreaWithOneWildcard textTi1start_1;
    touchgfx::TextArea textLabeFreq8;
    touchgfx::TextArea textSampleLabel;
    touchgfx::TextArea textMeanLabel;
    touchgfx::TextArea textStdDevLabel;
    touchgfx::TextAreaWithOneWildcard textSample1;
    touchgfx::TextAreaWithOneWildcard textSample2;
    touchgfx::TextAreaWithOneWildcard textSample3;
    touchgfx::TextAreaWithOneWildcard textSample4;
    touchgfx::TextAreaWithOneWildcard textSample5;
    touchgfx::TextAreaWithOneWildcard textSample6;
    touchgfx::TextAreaWithOneWildcard textSample7;
    touchgfx::TextAreaWithOneWildcard textSample8;
    touchgfx::TextAreaWithOneWildcard textMeanVal1;
    touchgfx::TextAreaWithOneWildcard textMeanVal2;
    touchgfx::TextAreaWithOneWildcard textMeanVal3;
    touchgfx::TextAreaWithOneWildcard textMeanVal4;
    touchgfx::TextAreaWithOneWildcard textMeanVal5;
    touchgfx::TextAreaWithOneWildcard textMeanVal6;
    touchgfx::TextAreaWithOneWildcard textMeanVal7;
    touchgfx::TextAreaWithOneWildcard textMeanVal8;
    touchgfx::TextAreaWithOneWildcard textStdDevVal1;
    touchgfx::TextAreaWithOneWildcard textStdDevVal2;
    touchgfx::TextAreaWithOneWildcard textStdDevVal3;
    touchgfx::TextAreaWithOneWildcard textStdDevVal4;
    touchgfx::TextAreaWithOneWildcard textStdDevVal5;
    touchgfx::TextAreaWithOneWildcard textStdDevVal6;
    touchgfx::TextAreaWithOneWildcard textStdDevVal7;
    touchgfx::TextAreaWithOneWildcard textStdDevVal7_1;
    touchgfx::TextArea textUnitSDuHz1;
    touchgfx::TextArea textUnitSDuHz2;
    touchgfx::TextArea textUnitSDuHz3;
    touchgfx::TextArea textUnitSDuHz4;
    touchgfx::TextArea textUnitSDuHz5;
    touchgfx::TextArea textUnitSDuHz6;
    touchgfx::TextArea textUnitSDuHz7;
    touchgfx::TextArea textUnitSDuHz8;
    touchgfx::TextArea textUnitSDmHz1;
    touchgfx::TextArea textUnitSDmHz2;
    touchgfx::TextArea textUnitSDmHz3;
    touchgfx::TextArea textUnitSDmHz4;
    touchgfx::TextArea textUnitSDmHz5;
    touchgfx::TextArea textUnitSDmHz6;
    touchgfx::TextArea textUnitSDmHz7;
    touchgfx::TextArea textUnitSDmHz8;
    touchgfx::TextArea textUnitkHz1;
    touchgfx::TextArea textUnitkHz2;
    touchgfx::TextArea textUnitkHz3;
    touchgfx::TextArea textUnitkHz4;
    touchgfx::TextArea textUnitkHz5;
    touchgfx::TextArea textUnitkHz6;
    touchgfx::TextArea textUnitkHz7;
    touchgfx::TextArea textUnitkHz8;
    touchgfx::TextArea textUnitMHz1;
    touchgfx::TextArea textUnitMHz2;
    touchgfx::TextArea textUnitMHz3;
    touchgfx::TextArea textUnitMHz4;
    touchgfx::TextArea textUnitMHz5;
    touchgfx::TextArea textUnitMHz6;
    touchgfx::TextArea textUnitMHz7;
    touchgfx::TextArea textUnitMHz8;
    touchgfx::TextArea textUnitGHz1;
    touchgfx::TextArea textUnitGHz2;
    touchgfx::TextArea textUnitGHz3;
    touchgfx::TextArea textUnitGHz4;
    touchgfx::TextArea textUnitGHz5;
    touchgfx::TextArea textUnitGHz6;
    touchgfx::TextArea textUnitGHz7;
    touchgfx::TextArea textUnitGHz8;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTTI1START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi1startBuffer[TEXTTI1START_SIZE];
    static const uint16_t TEXTTI2START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi2startBuffer[TEXTTI2START_SIZE];
    static const uint16_t TEXTTI3START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi3startBuffer[TEXTTI3START_SIZE];
    static const uint16_t TEXTTI4START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi4startBuffer[TEXTTI4START_SIZE];
    static const uint16_t TEXTTI5START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi5startBuffer[TEXTTI5START_SIZE];
    static const uint16_t TEXTTI6START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi6startBuffer[TEXTTI6START_SIZE];
    static const uint16_t TEXTTI7START_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi7startBuffer[TEXTTI7START_SIZE];
    static const uint16_t TEXTTI1START_1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTi1start_1Buffer[TEXTTI1START_1_SIZE];
    static const uint16_t TEXTSAMPLE1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textSample1Buffer[TEXTSAMPLE1_SIZE];
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
    static const uint16_t TEXTSAMPLE8_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textSample8Buffer[TEXTSAMPLE8_SIZE];
    static const uint16_t TEXTMEANVAL1_SIZE = 22;
    touchgfx::Unicode::UnicodeChar textMeanVal1Buffer[TEXTMEANVAL1_SIZE];
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
    static const uint16_t TEXTMEANVAL8_SIZE = 22;
    touchgfx::Unicode::UnicodeChar textMeanVal8Buffer[TEXTMEANVAL8_SIZE];
    static const uint16_t TEXTSTDDEVVAL1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStdDevVal1Buffer[TEXTSTDDEVVAL1_SIZE];
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
    static const uint16_t TEXTSTDDEVVAL7_1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStdDevVal7_1Buffer[TEXTSTDDEVVAL7_1_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<FreqModeViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // FREQMODEVIEWBASE_HPP
