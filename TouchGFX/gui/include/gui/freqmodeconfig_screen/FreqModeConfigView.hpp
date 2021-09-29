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

    // funkcja dla przycisku onoff INPUT
    virtual void toggleChannelState();

protected:
    // obsluga scroll wheel
    Callback<FreqModeConfigView, int16_t> scrollWheelINPUTAnimateToCallback;
    void scrollWheelINPUTAnimateToHandler(int16_t itemSelected);

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
};

#endif // FREQMODECONFIGVIEW_HPP
