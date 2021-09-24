#ifndef TIMEMODECONFIGVIEW_HPP
#define TIMEMODECONFIGVIEW_HPP

#include <gui_generated/timemodeconfig_screen/TimeModeConfigViewBase.hpp>
#include <gui/timemodeconfig_screen/TimeModeConfigPresenter.hpp>
#include <gui/lib/TimeModeParameter.hpp>

//extern TimeModeParameter Channel1;

class TimeModeConfigView : public TimeModeConfigViewBase
{
public:
    TimeModeConfigView();
    virtual ~TimeModeConfigView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollWheelINPUTUpdateItem(ChannelContainer& item, int16_t itemIndex);
    virtual void scrollWheelINPUTUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex);

    virtual void ChangeChannelState();
    // moje funkcje do GUI   -- remove
    void setGuiTouchable(bool state);
    uint16_t getCurrentChannel();
    void setChannelStateUI(bool state);
protected:
    // Callback which is executed when an item in the scroll wheel is selected to as selected style.
    // The parameter itemSelected is the selected item.
    Callback<TimeModeConfigView, int16_t> scrollWheelAnimateToCallback;
    void scrollWheelAnimateToHandler(int16_t itemSelected);

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
    // wskazniki do kanalow		-- remove
    std::unique_ptr<TimeModeParameter> pChannel1;

    int16_t m_numberChannel;
};

#endif // TIMEMODECONFIGVIEW_HPP
