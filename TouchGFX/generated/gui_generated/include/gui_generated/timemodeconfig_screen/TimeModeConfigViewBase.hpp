/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TIMEMODECONFIGVIEWBASE_HPP
#define TIMEMODECONFIGVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/timemodeconfig_screen/TimeModeConfigPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/scrollers/ScrollWheelWithSelectionStyle.hpp>
#include <gui/containers/ChannelContainer.hpp>
#include <gui/containers/ChannelContainerCenter.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>

class TimeModeConfigViewBase : public touchgfx::View<TimeModeConfigPresenter>
{
public:
    TimeModeConfigViewBase();
    virtual ~TimeModeConfigViewBase() {}
    virtual void setupScreen();

    virtual void scrollWheelINPUTUpdateItem(ChannelContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in TimeModeConfig
    }

    virtual void scrollWheelINPUTUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
    {
        // Override and implement this function in TimeModeConfig
    }

    virtual void scrollWheelTISetupUpdateItem(ChannelContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in TimeModeConfig
    }

    virtual void scrollWheelTISetupUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
    {
        // Override and implement this function in TimeModeConfig
    }

    virtual void scrollWheelStartUpdateItem(ChannelContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in TimeModeConfig
    }

    virtual void scrollWheelStartUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
    {
        // Override and implement this function in TimeModeConfig
    }

    virtual void scrollWheelStopUpdateItem(ChannelContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in TimeModeConfig
    }

    virtual void scrollWheelStopUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
    {
        // Override and implement this function in TimeModeConfig
    }

    /*
     * Virtual Action Handlers
     */
    virtual void ChangeChannelState()
    {
        // Override and implement this function in TimeModeConfig
    }

    virtual void turnTiMaxRange()
    {
        // Override and implement this function in TimeModeConfig
    }

    virtual void turnMeasRate()
    {
        // Override and implement this function in TimeModeConfig
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
    touchgfx::Box boxConfigTime;
    touchgfx::Button buttonBackTime;
    touchgfx::TextArea labelTimeConfig;
    touchgfx::Box boxBacgroundTC;
    touchgfx::SwipeContainer swipeContainerTime;
    touchgfx::Container swipeContainerTimeINPUT;
    touchgfx::Box boxINPUT;
    touchgfx::Image imageArrowR;
    touchgfx::TextArea labelINPUT;
    touchgfx::TextAreaWithOneWildcard textChannelINPUT;
    touchgfx::ScrollWheelWithSelectionStyle scrollWheelINPUT;
    touchgfx::DrawableListItems<ChannelContainer, 6> scrollWheelINPUTListItems;
    touchgfx::DrawableListItems<ChannelContainerCenter, 2> scrollWheelINPUTSelectedListItems;

    touchgfx::ToggleButton toggleChannel;
    touchgfx::RadioButton radioSlopeDown;
    touchgfx::RadioButton radioSlopeUp;
    touchgfx::TextArea textThreshold;
    touchgfx::TextArea textSlope;
    touchgfx::ButtonWithLabel buttonDetect;
    touchgfx::TextAreaWithOneWildcard textSliderThreshold;
    touchgfx::Slider sliderThreshold;
    touchgfx::RadioButton radioThresholdManual;
    touchgfx::RadioButton radioThresholdDefined;
    touchgfx::TextArea textTManual;
    touchgfx::TextArea textTDefined;
    touchgfx::Container swipeContainerTimeCLOCK;
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
    touchgfx::Container swipeContainerTimeTISETUP;
    touchgfx::Box boxTISETUP;
    touchgfx::Image imageArrowTL;
    touchgfx::Image imageArrowTR;
    touchgfx::TextArea labelTISETUP;
    touchgfx::ScrollWheelWithSelectionStyle scrollWheelTISetup;
    touchgfx::DrawableListItems<ChannelContainer, 6> scrollWheelTISetupListItems;
    touchgfx::DrawableListItems<ChannelContainerCenter, 2> scrollWheelTISetupSelectedListItems;

    touchgfx::TextAreaWithOneWildcard textOnOffChannel;
    touchgfx::TextArea textTiStop;
    touchgfx::TextArea textTiStart;
    touchgfx::TextArea textOnState;
    touchgfx::TextArea textOffState;
    touchgfx::ScrollWheelWithSelectionStyle scrollWheelStart;
    touchgfx::DrawableListItems<ChannelContainer, 4> scrollWheelStartListItems;
    touchgfx::DrawableListItems<ChannelContainerCenter, 2> scrollWheelStartSelectedListItems;

    touchgfx::TextAreaWithOneWildcard textStartChannel;
    touchgfx::TextAreaWithOneWildcard textStopChannel;
    touchgfx::ScrollWheelWithSelectionStyle scrollWheelStop;
    touchgfx::DrawableListItems<ChannelContainer, 4> scrollWheelStopListItems;
    touchgfx::DrawableListItems<ChannelContainerCenter, 2> scrollWheelStopSelectedListItems;
    touchgfx::Container swipeContainerTimeSESSION;
    touchgfx::Box boxSESSIONSETUP;
    touchgfx::Image imageArrowSL;
    touchgfx::TextArea labelSESSIONSETUP;
    touchgfx::TextArea textTiMaxRange;
    touchgfx::TextArea textMeasRate;
    touchgfx::TextAreaWithOneWildcard textRangeVal;
    touchgfx::Slider sliderRange;
    touchgfx::TextAreaWithOneWildcard textStampsVal;
    touchgfx::TextArea textSampsNumber;
    touchgfx::TextArea textX;
    touchgfx::TextArea textArea1;
    touchgfx::TextAreaWithOneWildcard textRepeatVal;
    touchgfx::Slider sliderStampsNumber;
    touchgfx::Slider sliderRepeat;
    touchgfx::Slider sliderRate;
    touchgfx::TextAreaWithOneWildcard textRateVal;
    touchgfx::ToggleButton toggleTiMeasRate;
    touchgfx::ToggleButton toggleTiMaxRange;
    touchgfx::RadioButton radioSingle;
    touchgfx::RadioButton radioContinuous;
    touchgfx::TextArea textSingle;
    touchgfx::TextArea textContinuous;
    touchgfx::RadioButtonGroup<2> radioButtonGroupSlope;
    touchgfx::RadioButtonGroup<2> radioButtonGroupThreshold;
    touchgfx::RadioButtonGroup<3> radioButtonGroupClock;
    touchgfx::RadioButtonGroup<2> radioButtonGroupModeSession;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTCHANNELINPUT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textChannelINPUTBuffer[TEXTCHANNELINPUT_SIZE];
    static const uint16_t TEXTSLIDERTHRESHOLD_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textSliderThresholdBuffer[TEXTSLIDERTHRESHOLD_SIZE];
    static const uint16_t TEXTONOFFCHANNEL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textOnOffChannelBuffer[TEXTONOFFCHANNEL_SIZE];
    static const uint16_t TEXTSTARTCHANNEL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStartChannelBuffer[TEXTSTARTCHANNEL_SIZE];
    static const uint16_t TEXTSTOPCHANNEL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStopChannelBuffer[TEXTSTOPCHANNEL_SIZE];
    static const uint16_t TEXTRANGEVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textRangeValBuffer[TEXTRANGEVAL_SIZE];
    static const uint16_t TEXTSTAMPSVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textStampsValBuffer[TEXTSTAMPSVAL_SIZE];
    static const uint16_t TEXTREPEATVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textRepeatValBuffer[TEXTREPEATVAL_SIZE];
    static const uint16_t TEXTRATEVAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textRateValBuffer[TEXTRATEVAL_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TimeModeConfigViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<TimeModeConfigViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);

};

#endif // TIMEMODECONFIGVIEWBASE_HPP
