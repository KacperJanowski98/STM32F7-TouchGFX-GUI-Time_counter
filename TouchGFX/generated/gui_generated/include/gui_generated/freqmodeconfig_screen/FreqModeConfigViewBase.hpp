/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FREQMODECONFIGVIEWBASE_HPP
#define FREQMODECONFIGVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/freqmodeconfig_screen/FreqModeConfigPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/containers/scrollers/ScrollWheelWithSelectionStyle.hpp>
#include <gui/containers/ChannelContainer.hpp>
#include <gui/containers/ChannelContainerCenter.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>

class FreqModeConfigViewBase : public touchgfx::View<FreqModeConfigPresenter>
{
public:
    FreqModeConfigViewBase();
    virtual ~FreqModeConfigViewBase() {}
    virtual void setupScreen();

    virtual void scrollWheelINPUTUpdateItem(ChannelContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in FreqModeConfig
    }

    virtual void scrollWheelINPUTUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
    {
        // Override and implement this function in FreqModeConfig
    }

    /*
     * Virtual Action Handlers
     */
    virtual void toggleChannelState()
    {
        // Override and implement this function in FreqModeConfig
    }

    virtual void FinishSetupFreqModeSingle()
    {
        // Override and implement this function in FreqModeConfig
    }

    virtual void FinishSetupFreqModeConst()
    {
        // Override and implement this function in FreqModeConfig
    }

    virtual void FinishSetupFreqModeStamps()
    {
        // Override and implement this function in FreqModeConfig
    }

    virtual void detectThreshold()
    {
        // Override and implement this function in FreqModeConfig
    }

    virtual void FinishSetupFreqModeRepeat()
    {
        // Override and implement this function in FreqModeConfig
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box boxLeftBackG;
    touchgfx::Box boxRightBackG;
    touchgfx::Box boxConfigFreq;
    touchgfx::Button buttonBackFreq;
    touchgfx::TextArea labelFreqConfig;
    touchgfx::Box boxBackgroundFC;
    touchgfx::SwipeContainer swipeContainerFreq;
    touchgfx::Container swipeContainerFreqINPUT;
    touchgfx::Box boxINPUT;
    touchgfx::BoxWithBorder boxWithBorderScroll;
    touchgfx::BoxWithBorder boxWithBorderThreshold;
    touchgfx::BoxWithBorder boxWithBorderSlope;
    touchgfx::Image imageArrowR;
    touchgfx::TextArea labelINPUT;
    touchgfx::ToggleButton toggleChannel;
    touchgfx::RadioButton radioSlopeDown;
    touchgfx::RadioButton radioSlopeUp;
    touchgfx::TextArea textThreshold;
    touchgfx::ScrollWheelWithSelectionStyle scrollWheelINPUT;
    touchgfx::DrawableListItems<ChannelContainer, 6> scrollWheelINPUTListItems;
    touchgfx::DrawableListItems<ChannelContainerCenter, 2> scrollWheelINPUTSelectedListItems;

    touchgfx::TextArea textSlope;
    touchgfx::ButtonWithLabel buttonDetect;
    touchgfx::TextAreaWithOneWildcard textSliderThreshold;
    touchgfx::Slider sliderThreshold;
    touchgfx::Image imageFrame;
    touchgfx::Image imageFallingF;
    touchgfx::Image imageRisingF;
    touchgfx::BoxWithBorder boxLockInput;
    touchgfx::Image imageLockInput;
    touchgfx::Container swipeContainerFreqCLOCK;
    touchgfx::Box boxCLOCK;
    touchgfx::Image imageArrowCL;
    touchgfx::Image imageArrowCR;
    touchgfx::TextArea labelCLOCK;
    touchgfx::TextArea textClockExternal;
    touchgfx::RadioButton radioClockExternal;
    touchgfx::TextArea textClockRubid;
    touchgfx::RadioButton radioClockRubid;
    touchgfx::TextArea textClockQuartz;
    touchgfx::RadioButton radioClockQuartz;
    touchgfx::Container swipeContainerFreqMESSETUP;
    touchgfx::Image imageArrowTL;
    touchgfx::Image imageArrowTR;
    touchgfx::TextArea labelTISETUP;
    touchgfx::Box boxTISETUP;
    touchgfx::BoxWithBorder boxWithBorderGate;
    touchgfx::TextArea labelHfInput;
    touchgfx::Image imageArrowML;
    touchgfx::Image imageArrowMR;
    touchgfx::RadioButton radioHfInputOn;
    touchgfx::RadioButton radioHfInputOff;
    touchgfx::TextArea textON;
    touchgfx::TextArea textOFF;
    touchgfx::TextArea labelGate;
    touchgfx::TextAreaWithOneWildcard textGateVal;
    touchgfx::Slider sliderGate;
    touchgfx::TextArea labelMesSetup;
    touchgfx::Container swipeContainerFreqSESSION;
    touchgfx::Box boxSESSIONSETUP;
    touchgfx::BoxWithBorder boxWithBorderStamp;
    touchgfx::BoxWithBorder boxWithBorderRepeat;
    touchgfx::Image imageArrowSL;
    touchgfx::TextArea labelSESSIONSETUP;
    touchgfx::TextAreaWithOneWildcard textStampsVal;
    touchgfx::TextArea textSampsNumber;
    touchgfx::TextArea textX;
    touchgfx::TextArea textArea1;
    touchgfx::TextAreaWithOneWildcard textRepeatVal;
    touchgfx::Slider sliderStampsNumber;
    touchgfx::Slider sliderRepeat;
    touchgfx::ButtonWithLabel buttonConfigFreqStamps;
    touchgfx::ButtonWithLabel buttonConfigFreqConst;
    touchgfx::ButtonWithLabel buttonConfigFreqSingle;
    touchgfx::ButtonWithLabel buttonConfigFreqRepeat;
    touchgfx::Image imageSetting;
    touchgfx::RadioButtonGroup<2> radioButtonGroupSlopeFreq;
    touchgfx::RadioButtonGroup<3> radioButtonGroupClock;
    touchgfx::RadioButtonGroup<2> radioButtonGroupHfInput;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTSLIDERTHRESHOLD_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textSliderThresholdBuffer[TEXTSLIDERTHRESHOLD_SIZE];
    static const uint16_t TEXTGATEVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textGateValBuffer[TEXTGATEVAL_SIZE];
    static const uint16_t TEXTSTAMPSVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStampsValBuffer[TEXTSTAMPSVAL_SIZE];
    static const uint16_t TEXTREPEATVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textRepeatValBuffer[TEXTREPEATVAL_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<FreqModeConfigViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<FreqModeConfigViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);

};

#endif // FREQMODECONFIGVIEWBASE_HPP
