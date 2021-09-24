#include <gui/timemodeconfig_screen/TimeModeConfigView.hpp>

TimeModeConfigView::TimeModeConfigView()
	: scrollWheelAnimateToCallback(this, &TimeModeConfigView::scrollWheelAnimateToHandler)
	, sliderValueChangedCallback(this, &TimeModeConfigView::sliderValueChangedCallbackHandler)
	, sliderValueConfirmedCallback(this, &TimeModeConfigView::sliderValueConfirmedCallbackHandler)
	, RadioBtnGroupSlopeCallback(this, &TimeModeConfigView::RadioBtnGroupSlopeCallbackHandler)
{
	radioButtonGroupSlope.setRadioButtonSelectedHandler(RadioBtnGroupSlopeCallback);
	radioButtonGroupThreshold.setRadioButtonSelectedHandler(RadioBtnGroupSlopeCallback);
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
	// obsluga slidera    -- remove
    sliderThreshold.setStartValueCallback(sliderValueStartedChangeCallback);
    sliderThreshold.setNewValueCallback(sliderValueChangedCallback);
    sliderThreshold.setStopValueCallback(sliderValueConfirmedCallback);
    // obsluga toggle butona    -- remove
    TimeModeConfigView::setChannelParameter(toggleChannel.getState());
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
	int16_t numberChannel = itemSelected + 1;
	Unicode::snprintf(textChannelINPUTBuffer, TEXTCHANNELINPUT_SIZE, "%d", numberChannel);
	switch(numberChannel)
	{
	case 1:
		toggleChannel.forceState(true);
		break;
	case 2:
		toggleChannel.forceState(false);
		break;
	case 3:
		toggleChannel.forceState(true);
		break;
	case 4:
		toggleChannel.forceState(false);
		break;
	case 5:
		toggleChannel.forceState(true);
		break;
	case 6:
		toggleChannel.forceState(false);
		break;
	case 7:
		toggleChannel.forceState(true);
		break;
	case 8:
		toggleChannel.forceState(false);
		break;
	}
	toggleChannel.invalidate();
	TimeModeConfigView::setChannelParameter(toggleChannel.getState());
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

// obsluga radiobutton   -- remove
void TimeModeConfigView::RadioBtnGroupSlopeCallbackHandler(const touchgfx::AbstractButton& src)
{
	if(&src == &radioSlopeUp)
	{
		Unicode::snprintf(textTestBuffer, TEXTTEST_SIZE, "%d", 1);
		textTest.invalidate();
	}
	else if(&src == &radioSlopeDown)
	{
		Unicode::snprintf(textTestBuffer, TEXTTEST_SIZE, "%d", 2);
		textTest.invalidate();
	}
	else if(&src == &radioThresholdManual)
	{
		Unicode::snprintf(textTestBuffer, TEXTTEST_SIZE, "%d", 11);
		textTest.invalidate();
	}
	else if(&src == &radioThresholdDefined)
	{
		Unicode::snprintf(textTestBuffer, TEXTTEST_SIZE, "%d", 22);
		textTest.invalidate();
	}
}

void TimeModeConfigView::ChangeChannelState()
{
	TimeModeConfigView::setChannelParameter(toggleChannel.getState());
}

// moje funkcje
void  TimeModeConfigView::setChannelParameter(bool state)
{
    if (state == false)
    {
    	radioSlopeUp.setTouchable(false);
    	radioSlopeDown.setTouchable(false);
    	radioThresholdManual.setTouchable(false);
    	radioThresholdDefined.setTouchable(false);
    	sliderThreshold.setTouchable(false);
    	buttonDetect.setTouchable(false);
    }
    else
    {
    	radioSlopeUp.setTouchable(true);
    	radioSlopeDown.setTouchable(true);
    	radioThresholdManual.setTouchable(true);
    	radioThresholdDefined.setTouchable(true);
    	sliderThreshold.setTouchable(true);
    	buttonDetect.setTouchable(true);
    }
}


