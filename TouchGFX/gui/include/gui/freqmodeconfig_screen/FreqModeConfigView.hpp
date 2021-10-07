#ifndef FREQMODECONFIGVIEW_HPP
#define FREQMODECONFIGVIEW_HPP

#include <gui_generated/freqmodeconfig_screen/FreqModeConfigViewBase.hpp>
#include <gui/freqmodeconfig_screen/FreqModeConfigPresenter.hpp>

#include <gui/lib/FreqModeParameter.hpp>

class FreqModeConfigView : public FreqModeConfigViewBase
{
public:
    FreqModeConfigView();
    virtual ~FreqModeConfigView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // funckcje dla slider INPUT
    virtual void scrollWheelINPUTUpdateItem(ChannelContainer& item, int16_t itemIndex);
    virtual void scrollWheelINPUTUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex);

    virtual void FinishSetupFreqMode();

    // funkcja dla przycisku onoff INPUT
    virtual void toggleChannelState();

    void initUIChannel(std::shared_ptr<FreqModeParameter>& channel);
    void setGuiTouchable(bool state);
    void setChannelStateUI(std::shared_ptr<FreqModeParameter>& channel, bool state);
    void readSlopeUI(SlopeName slopeUi);
    void setSlopeUI(std::shared_ptr<FreqModeParameter>& channel, SlopeName slopeUi);
    void readThresholdUI(uint32_t value);
    void setThresholdUI(std::shared_ptr<FreqModeParameter>& channel, uint32_t value);

    void setValueSliderThresholdUI(int value);
    void initMesSetupUI();
    void setValueSliderGateUI(int value);

    void updateClockSourceUI(ClockName clk);

protected:
    // obsluga scroll wheel
    Callback<FreqModeConfigView, int16_t> scrollWheelINPUTAnimateToCallback;
    void scrollWheelINPUTAnimateToHandler(int16_t itemSelected);

    touchgfx::Callback<FreqModeConfigView, const touchgfx::Slider&, int> sliderValueStartedChangeCallback;
    touchgfx::Callback<FreqModeConfigView, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<FreqModeConfigView, const touchgfx::Slider&, int> sliderValueConfirmedCallback;

	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupFreqCallback;
	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupHfInputCallback;
	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupSessionCallback;
	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupClockCallback;

    void sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);
    void RadioBtnGroupFreqCallbackHandler(const touchgfx::AbstractButton& src);
    void RadioBtnGroupHfInputCallbackHandler(const touchgfx::AbstractButton& src);
    void RadioBtnGroupSessionCallbackHandler(const touchgfx::AbstractButton& src);
    void RadioBtnGroupClockCallbackHandler(const touchgfx::AbstractButton& src);

private:
    FreqModeParameter Channel1 , Channel2, Channel3, Channel4, Channel5, Channel6, Channel7, Channel8;

    std::shared_ptr<FreqModeParameter> pChannel1;
    std::shared_ptr<FreqModeParameter> pChannel2;
    std::shared_ptr<FreqModeParameter> pChannel3;
    std::shared_ptr<FreqModeParameter> pChannel4;
    std::shared_ptr<FreqModeParameter> pChannel5;
    std::shared_ptr<FreqModeParameter> pChannel6;
    std::shared_ptr<FreqModeParameter> pChannel7;
    std::shared_ptr<FreqModeParameter> pChannel8;

    int16_t m_channelInput;
    std::shared_ptr<FreqModeParameter> pChannelInput;

	bool m_hfInput;
	uint16_t m_gate;
	ClockName m_clockSource;
};

#endif // FREQMODECONFIGVIEW_HPP
