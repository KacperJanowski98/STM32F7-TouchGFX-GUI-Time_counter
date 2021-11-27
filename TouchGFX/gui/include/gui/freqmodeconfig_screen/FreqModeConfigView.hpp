#ifndef FREQMODECONFIGVIEW_HPP
#define FREQMODECONFIGVIEW_HPP

#include <gui_generated/freqmodeconfig_screen/FreqModeConfigViewBase.hpp>
#include <gui/freqmodeconfig_screen/FreqModeConfigPresenter.hpp>
#include <gui/lib/SessionSetup.hpp>
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

    virtual void FinishSetupFreqModeSingle();

    virtual void FinishSetupFreqModeConst();

    virtual void FinishSetupFreqModeStamps();

    virtual void FinishSetupFreqModeRepeat();

    // funkcja dla przycisku onoff INPUT
    virtual void toggleChannelState();

    virtual void detectThreshold();

    virtual void AddThreshold();

    virtual void OddThreshold();

    void initUIChannel(std::shared_ptr<FreqModeParameter>& channel);
    void setGuiTouchable(bool state);
    void setChannelStateUI(std::shared_ptr<FreqModeParameter>& channel, bool state);
    void readSlopeUI(SlopeName slopeUi);
    void setSlopeUI(std::shared_ptr<FreqModeParameter>& channel, SlopeName slopeUi);
    void readThresholdUI(uint32_t value);
    void setThresholdUI(std::shared_ptr<FreqModeParameter>& channel, uint32_t value);

    void setValueSliderThresholdUI(int value);
    void setValueSliderStampsNumberUI(int value);
    void setValueSliderRepeatUI(int value);
    void setValueSliderGateUI(int value);
    void initMesSetupUI();

    void setStampsUI(std::shared_ptr<SessionSetup>& session, uint16_t value);
    void setRepeatUI(std::shared_ptr<SessionSetup>& session, uint16_t value);

    void updateClockSourceUI(ClockName clk);

    void updateMesSetupUI(bool state);

    void updateSessionSetupUI(std::shared_ptr<SessionSetup>& session);

    void updateFreqParameterBackend();

    void updateChannelBackendStruct(FreqChannel_t *pChannelBack, std::shared_ptr<FreqModeParameter> pChannel);
    void updateSessionBackendStruct(SessionSetup_t *pSessionBack, std::shared_ptr<SessionSetup> pSession);

protected:
    // obsluga scroll wheel
    Callback<FreqModeConfigView, int16_t> scrollWheelINPUTAnimateToCallback;
    void scrollWheelINPUTAnimateToHandler(int16_t itemSelected);

    touchgfx::Callback<FreqModeConfigView, const touchgfx::Slider&, int> sliderValueStartedChangeCallback;
    touchgfx::Callback<FreqModeConfigView, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<FreqModeConfigView, const touchgfx::Slider&, int> sliderValueConfirmedCallback;

	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupFreqCallback;
	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupHfInputCallback;
	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupClockCallback;

    void sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);
    void RadioBtnGroupFreqCallbackHandler(const touchgfx::AbstractButton& src);
    void RadioBtnGroupHfInputCallbackHandler(const touchgfx::AbstractButton& src);
    void RadioBtnGroupClockCallbackHandler(const touchgfx::AbstractButton& src);

private:
    FreqModeParameter Channel1 , Channel2, Channel3, Channel4, Channel5, Channel6, Channel7, Channel8;

    SessionSetup Session;

    std::shared_ptr<SessionSetup> pSession;

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

    uint32_t m_newThreshold;
	bool m_hfInput;
	uint16_t m_gate;
};

#endif // FREQMODECONFIGVIEW_HPP
