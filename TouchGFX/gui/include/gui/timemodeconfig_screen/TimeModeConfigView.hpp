#ifndef TIMEMODECONFIGVIEW_HPP
#define TIMEMODECONFIGVIEW_HPP

#include <gui_generated/timemodeconfig_screen/TimeModeConfigViewBase.hpp>
#include <gui/timemodeconfig_screen/TimeModeConfigPresenter.hpp>
#include <gui/lib/TimeModeParameter.hpp>
#include <gui/model/Model.hpp>

class TimeModeConfigView : public TimeModeConfigViewBase
{
public:
    TimeModeConfigView();
    virtual ~TimeModeConfigView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollWheelINPUTUpdateItem(ChannelContainer& item, int16_t itemIndex);
    virtual void scrollWheelINPUTUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex);

    virtual void scrollWheelTISetupUpdateItem(ChannelContainer& item, int16_t itemIndex);
    virtual void scrollWheelTISetupUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex);

    virtual void ChangeChannelState();
    // moje funkcje do GUI   -- remove
    void setGuiTouchable(bool state);
    uint16_t getCurrentChannel();
    void setChannelStateUI(bool state);
    void readSlopeUI(SlopeName slopeUi);
    void setSlopeUI(SlopeName slopeUi);
    void readThresholdModeUI(ThresholdName ThresholdMode);
    void setThresholdModeUI(ThresholdName ThresholdMode);
    void readThresholdUI(uint32_t value);
    void setThresholdUI(uint32_t value);
protected:
    // Callback which is executed when an item in the scroll wheel is selected to as selected style.
    // The parameter itemSelected is the selected item.
    Callback<TimeModeConfigView, int16_t> scrollWheelINPUTAnimateToCallback;
    void scrollWheelINPUTAnimateToHandler(int16_t itemSelected);

    Callback<TimeModeConfigView, int16_t> scrollWheelTISetupAnimateToCallback;
    void scrollWheelTISetupAnimateToHandler(int16_t itemSelected);

    // Callback Declaration.
    touchgfx::Callback<TimeModeConfigView, const touchgfx::Slider&, int> sliderValueStartedChangeCallback;
    touchgfx::Callback<TimeModeConfigView, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<TimeModeConfigView, const touchgfx::Slider&, int> sliderValueConfirmedCallback;

    touchgfx::Callback<TimeModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupSlopeCallback;

    // Callback Handler Declarations.
    void sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);

    void RadioBtnGroupSlopeCallbackHandler(const touchgfx::AbstractButton& src);
private:
    TimeModeParameter Channel1 , Channel2, Channel3, Channel4, Channel5, Channel6, Channel7, Channel8;
    // wskazniki do kanalow		-- remove
    std::unique_ptr<TimeModeParameter> pChannel1;
    std::unique_ptr<TimeModeParameter> pChannel2;
    std::unique_ptr<TimeModeParameter> pChannel3;
    std::unique_ptr<TimeModeParameter> pChannel4;
    std::unique_ptr<TimeModeParameter> pChannel5;
    std::unique_ptr<TimeModeParameter> pChannel6;
    std::unique_ptr<TimeModeParameter> pChannel7;
    std::unique_ptr<TimeModeParameter> pChannel8;

    int16_t m_numberChannel;
};

#endif // TIMEMODECONFIGVIEW_HPP
