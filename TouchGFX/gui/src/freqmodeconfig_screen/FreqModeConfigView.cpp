#include <gui/freqmodeconfig_screen/FreqModeConfigView.hpp>

FreqModeConfigView::FreqModeConfigView()
	: scrollWheelINPUTAnimateToCallback(this, &FreqModeConfigView::scrollWheelINPUTAnimateToHandler)
	, sliderValueStartedChangeCallback(this, &FreqModeConfigView::sliderValueStartedChangeCallbackHandler)
	, sliderValueChangedCallback(this, &FreqModeConfigView::sliderValueChangedCallbackHandler)
	, sliderValueConfirmedCallback(this, &FreqModeConfigView::sliderValueConfirmedCallbackHandler)
	, RadioBtnGroupFreqCallback(this, &FreqModeConfigView::RadioBtnGroupFreqCallbackHandler)
	, Channel1(1, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel2(2, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel3(3, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel4(4, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel5(5, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel6(6, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel7(7, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel8(8, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
{
	radioButtonGroupThresholdFreq.setRadioButtonSelectedHandler(RadioBtnGroupFreqCallback);
	FreqModeConfigView::pChannel1 = std::make_shared<FreqModeParameter>(Channel1);
	FreqModeConfigView::pChannel2 = std::make_shared<FreqModeParameter>(Channel2);
	FreqModeConfigView::pChannel3 = std::make_shared<FreqModeParameter>(Channel3);
	FreqModeConfigView::pChannel4 = std::make_shared<FreqModeParameter>(Channel4);
	FreqModeConfigView::pChannel5 = std::make_shared<FreqModeParameter>(Channel5);
	FreqModeConfigView::pChannel6 = std::make_shared<FreqModeParameter>(Channel6);
	FreqModeConfigView::pChannel7 = std::make_shared<FreqModeParameter>(Channel7);
	FreqModeConfigView::pChannel8 = std::make_shared<FreqModeParameter>(Channel8);
}

void FreqModeConfigView::setupScreen()
{
	scrollWheelINPUT.setAnimateToCallback(scrollWheelINPUTAnimateToCallback);

//    FreqModeConfigViewBase::setupScreen();

	// Elementy Scroll wheel sa aktualizowane zgodnie z wybranymi numerami.
	for (int i = 0; i < scrollWheelINPUTListItems.getNumberOfDrawables(); i++)
	{
		scrollWheelINPUT.itemChanged(i);
	}
	scrollWheelINPUT.animateToItem(3);

	// obsluga toggle button
	FreqModeConfigView::setGuiTouchable(toggleChannel.getState());

	// obsluga sliderow
	sliderThreshold.setStartValueCallback(sliderValueStartedChangeCallback);
	sliderThreshold.setNewValueCallback(sliderValueChangedCallback);
	sliderThreshold.setStopValueCallback(sliderValueConfirmedCallback);
}

void FreqModeConfigView::tearDownScreen()
{
//    FreqModeConfigViewBase::tearDownScreen();
}

void FreqModeConfigView::scrollWheelINPUTUpdateItem(ChannelContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void FreqModeConfigView::scrollWheelINPUTUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void FreqModeConfigView::scrollWheelINPUTAnimateToHandler(int16_t itemSelected)
{
	textChannelINPUT.invalidate();
	m_channelInput = itemSelected + 1;
	Unicode::snprintf(textChannelINPUTBuffer, TEXTCHANNELINPUT_SIZE, "%d", m_channelInput);
	switch(m_channelInput)
	{
	case 1:
		pChannelInput = pChannel1;
		toggleChannel.forceState(pChannel1->getStateChannel());
		readSlopeUI(pChannel1->getSlope());
		readThresholdModeUI(pChannel1->getThresholdMode());
		readThresholdUI(pChannel1->getThreshold());
		break;
	case 2:
		pChannelInput = pChannel2;
		toggleChannel.forceState(pChannel2->getStateChannel());
		readSlopeUI(pChannel2->getSlope());
		readThresholdModeUI(pChannel2->getThresholdMode());
		readThresholdUI(pChannel2->getThreshold());
		break;
	case 3:
		pChannelInput = pChannel3;
		toggleChannel.forceState(pChannel3->getStateChannel());
		readSlopeUI(pChannel3->getSlope());
		readThresholdModeUI(pChannel3->getThresholdMode());
		readThresholdUI(pChannel3->getThreshold());
		break;
	case 4:
		pChannelInput = pChannel4;
		toggleChannel.forceState(pChannel4->getStateChannel());
		readSlopeUI(pChannel4->getSlope());
		readThresholdModeUI(pChannel4->getThresholdMode());
		readThresholdUI(pChannel4->getThreshold());
		break;
	case 5:
		pChannelInput = pChannel5;
		toggleChannel.forceState(pChannel5->getStateChannel());
		readSlopeUI(pChannel5->getSlope());
		readThresholdModeUI(pChannel5->getThresholdMode());
		readThresholdUI(pChannel5->getThreshold());
		break;
	case 6:
		pChannelInput = pChannel6;
		toggleChannel.forceState(pChannel6->getStateChannel());
		readSlopeUI(pChannel6->getSlope());
		readThresholdModeUI(pChannel6->getThresholdMode());
		readThresholdUI(pChannel6->getThreshold());
		break;
	case 7:
		pChannelInput = pChannel7;
		toggleChannel.forceState(pChannel7->getStateChannel());
		readSlopeUI(pChannel7->getSlope());
		readThresholdModeUI(pChannel7->getThresholdMode());
		readThresholdUI(pChannel7->getThreshold());
		break;
	case 8:
		pChannelInput = pChannel8;
		toggleChannel.forceState(pChannel8->getStateChannel());
		readSlopeUI(pChannel8->getSlope());
		readThresholdModeUI(pChannel8->getThresholdMode());
		readThresholdUI(pChannel8->getThreshold());
		break;
	}
	toggleChannel.invalidate();
	bool CurrentStateUI = toggleChannel.getState();
	setChannelStateUI(pChannelInput, CurrentStateUI);
	FreqModeConfigView::setGuiTouchable(CurrentStateUI);
}

// obsluga sliderow
void FreqModeConfigView::sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value)
{
	if (&src == &sliderThreshold)
	{
		setThresholdUI(pChannelInput, (uint32_t)value);
		Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
		textSliderThreshold.invalidate();
	}
}

void FreqModeConfigView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
	if (&src == &sliderThreshold)
	{
		setThresholdUI(pChannelInput, (uint32_t)value);
		Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
		textSliderThreshold.invalidate();
	}
}

void FreqModeConfigView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
	if (&src == &sliderThreshold)
	{
		setThresholdUI(pChannelInput, (uint32_t)value);
		Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
		textSliderThreshold.invalidate();
	}
}

// obsluga radio button
void FreqModeConfigView::RadioBtnGroupFreqCallbackHandler(const touchgfx::AbstractButton& src)
{
	if (&src == &radioSlopeUp)
	{
		setSlopeUI(pChannelInput, SlopeName::UP);
	}
	else if (&src == &radioSlopeDown)
	{
		setSlopeUI(pChannelInput, SlopeName::DOWN);
	}
	else if (&src == &radioThresholdManual)
	{
		setThresholdModeUI(pChannelInput, ThresholdName::Manula);
	}
	else if (&src == &radioThresholdDefined)
	{
		setThresholdModeUI(pChannelInput, ThresholdName::Defined);
	}
	radioSlopeUp.invalidate();
	radioSlopeDown.invalidate();
	radioThresholdManual.invalidate();
	radioThresholdDefined.invalidate();
}

// obsluga przycisku toogle button
void FreqModeConfigView::toggleChannelState()
{
	bool CurrentState = toggleChannel.getState();
	FreqModeConfigView::setGuiTouchable(CurrentState);
	setChannelStateUI(pChannelInput, CurrentState);
}

// Funkcja pomocnicza dla toogle button
void FreqModeConfigView::setGuiTouchable(bool state)
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

// funkcja ustwiajaca stan kanalu w jego obiekcie
void FreqModeConfigView::setChannelStateUI(std::shared_ptr<FreqModeParameter>& channel, bool state)
{
	channel->setStateChannel(state);
}

void FreqModeConfigView::readSlopeUI(SlopeName slopeUi)
{
	if (slopeUi == SlopeName::UP)
	{
		radioSlopeUp.setSelected(true);
		radioSlopeDown.setSelected(false);
	}
	else
	{
		radioSlopeUp.setSelected(false);
		radioSlopeDown.setSelected(true);
	}
}

void FreqModeConfigView::setSlopeUI(std::shared_ptr<FreqModeParameter>& channel, SlopeName slopeUi)
{
	channel->setSlope(slopeUi);
}

void FreqModeConfigView::readThresholdModeUI(ThresholdName ThresholdM)
{
	if (ThresholdM == ThresholdName::Manula)
	{
		radioThresholdManual.setSelected(true);
		radioThresholdDefined.setSelected(false);
	}
	else
	{
		radioThresholdManual.setSelected(false);
		radioThresholdDefined.setSelected(true);
	}
}

void FreqModeConfigView::setThresholdModeUI(std::shared_ptr<FreqModeParameter>& channel, ThresholdName ThresholdMode)
{
	channel->setThresholdMode(ThresholdMode);
}

void FreqModeConfigView::readThresholdUI(uint32_t value)
{
	Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
	textSliderThreshold.invalidate();
	sliderThreshold.setValue((uint32_t)value);
}

void FreqModeConfigView::setThresholdUI(std::shared_ptr<FreqModeParameter>& channel, uint32_t value)
{
	channel->setThreshold(value);
}













