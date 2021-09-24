#include <gui/timemodeconfig_screen/TimeModeConfigView.hpp>

TimeModeConfigView::TimeModeConfigView()
	: scrollWheelAnimateToCallback(this, &TimeModeConfigView::scrollWheelAnimateToHandler)
	, sliderValueChangedCallback(this, &TimeModeConfigView::sliderValueChangedCallbackHandler)
	, sliderValueConfirmedCallback(this, &TimeModeConfigView::sliderValueConfirmedCallbackHandler)
{

}

void TimeModeConfigView::setupScreen()
{
	scrollWheelINPUT.setAnimateToCallback(scrollWheelAnimateToCallback);

	// The scroll wheel is updated to show the selected numbers.
	for (int i = 0; i < scrollWheelINPUTListItems.getNumberOfDrawables(); i++)
	{
		scrollWheelINPUT.itemChanged(i);
	}
	scrollWheelINPUT.animateToItem(3);
//    TimeModeConfigViewBase::setupScreen();
    sliderThreshold.setStartValueCallback(sliderValueStartedChangeCallback);
    sliderThreshold.setNewValueCallback(sliderValueChangedCallback);
    sliderThreshold.setStopValueCallback(sliderValueConfirmedCallback);
}

void TimeModeConfigView::tearDownScreen()
{
//    TimeModeConfigViewBase::tearDownScreen();
}

// Updates the text in the scroll wheel based on the item's index
void TimeModeConfigView::scrollWheelINPUTUpdateItem(ChannelContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void TimeModeConfigView::scrollWheelINPUTUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

// The callback updates the selectedVal on the itemSelected parameter
void TimeModeConfigView::scrollWheelAnimateToHandler(int16_t itemSelected)
{
	textChannelINPUT.invalidate();
	Unicode::snprintf(textChannelINPUTBuffer, TEXTCHANNELINPUT_SIZE, "%d", itemSelected + 1);
}

void TimeModeConfigView::sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
        //execute code whenever the slider starts changing value.
        Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
        textSliderThreshold.invalidate();
    }
}

void TimeModeConfigView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
        //execute code whenever the slider starts changing value.
        Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
        textSliderThreshold.invalidate();
    }
}

void TimeModeConfigView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
        //execute code whenever the slider starts changing value.
        Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
        textSliderThreshold.invalidate();
    }
}

