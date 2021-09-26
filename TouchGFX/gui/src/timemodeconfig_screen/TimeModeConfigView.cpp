#include <gui/timemodeconfig_screen/TimeModeConfigView.hpp>

TimeModeConfigView::TimeModeConfigView()
	: scrollWheelINPUTAnimateToCallback(this, &TimeModeConfigView::scrollWheelINPUTAnimateToHandler)
	, scrollWheelTISetupAnimateToCallback(this, &TimeModeConfigView::scrollWheelTISetupAnimateToHandler)
	, scrollWheelStartAnimateToCallback(this, &TimeModeConfigView::scrollWheelStartAnimateToHandler)
	, scrollWheelStopAnimateToCallback(this, &TimeModeConfigView::scrollWheelStopAnimateToHandler)
	, sliderValueChangedCallback(this, &TimeModeConfigView::sliderValueChangedCallbackHandler)
	, sliderValueConfirmedCallback(this, &TimeModeConfigView::sliderValueConfirmedCallbackHandler)
	, RadioBtnGroupSlopeCallback(this, &TimeModeConfigView::RadioBtnGroupSlopeCallbackHandler)
	, Channel1(1, false, SlopeName::UP, ThresholdName::Manula, 0, 0, 0)
	, Channel2(2, false, SlopeName::UP, ThresholdName::Manula, 0, 0, 0)
	, Channel3(3, false, SlopeName::UP, ThresholdName::Manula, 0, 0, 0)
	, Channel4(4, false, SlopeName::UP, ThresholdName::Manula, 0, 0, 0)
	, Channel5(5, false, SlopeName::UP, ThresholdName::Manula, 0, 0, 0)
	, Channel6(6, false, SlopeName::UP, ThresholdName::Manula, 0, 0, 0)
	, Channel7(7, false, SlopeName::UP, ThresholdName::Manula, 0, 0, 0)
	, Channel8(8, false, SlopeName::UP, ThresholdName::Manula, 0, 0, 0)
{
	radioButtonGroupSlope.setRadioButtonSelectedHandler(RadioBtnGroupSlopeCallback);
	radioButtonGroupThreshold.setRadioButtonSelectedHandler(RadioBtnGroupSlopeCallback);
	TimeModeConfigView::pChannel1 = std::make_shared<TimeModeParameter>(Channel1);
	TimeModeConfigView::pChannel2 = std::make_shared<TimeModeParameter>(Channel2);
	TimeModeConfigView::pChannel3 = std::make_shared<TimeModeParameter>(Channel3);
	TimeModeConfigView::pChannel4 = std::make_shared<TimeModeParameter>(Channel4);
	TimeModeConfigView::pChannel5 = std::make_shared<TimeModeParameter>(Channel5);
	TimeModeConfigView::pChannel6 = std::make_shared<TimeModeParameter>(Channel6);
	TimeModeConfigView::pChannel7 = std::make_shared<TimeModeParameter>(Channel7);
	TimeModeConfigView::pChannel8 = std::make_shared<TimeModeParameter>(Channel8);
}

void TimeModeConfigView::setupScreen()
{
	scrollWheelINPUT.setAnimateToCallback(scrollWheelINPUTAnimateToCallback);
	scrollWheelTISetup.setAnimateToCallback(scrollWheelTISetupAnimateToCallback);
	scrollWheelStart.setAnimateToCallback(scrollWheelStartAnimateToCallback);
	scrollWheelStop.setAnimateToCallback(scrollWheelStopAnimateToCallback);

	// The scroll wheel is updated to show the selected numbers.
	for (int i = 0; i < scrollWheelINPUTListItems.getNumberOfDrawables(); i++)
	{
		scrollWheelINPUT.itemChanged(i);
		scrollWheelTISetup.itemChanged(i);
	}
	scrollWheelINPUT.animateToItem(3);
	scrollWheelTISetup.animateToItem(3);

	// The scroll wheel for start in and stop in channels is updated to show the selected numbers.
	updateScrollTiSetup();

//    TimeModeConfigViewBase::setupScreen();
	// obsluga slidera    -- remove
    sliderThreshold.setStartValueCallback(sliderValueStartedChangeCallback);
    sliderThreshold.setNewValueCallback(sliderValueChangedCallback);
    sliderThreshold.setStopValueCallback(sliderValueConfirmedCallback);
    // obsluga toggle butona    -- remove
	TimeModeConfigView::setGuiTouchable(toggleChannel.getState());

    // Implementacja kanalow, stara wersja		-- remove
//    TimeModeParameter Channel1(1, false, Slope::UP, Threshold::Manula, 200, 1, 2);
    // implementacja wskaznikow   -- remove
//    TimeModeConfigView::pChannel1 = model.getChannel1();		//- wersja z pobiraniem obiektow z klasy model (version 1)
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

void TimeModeConfigView::scrollWheelTISetupUpdateItem(ChannelContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void TimeModeConfigView::scrollWheelTISetupUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void TimeModeConfigView::scrollWheelStartUpdateItem(ChannelContainer& item, int16_t itemIndex)
{
	item.updateText(activeChannels[itemIndex]);
}

void TimeModeConfigView::scrollWheelStartUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
{
	item.updateText(activeChannels[itemIndex]);
}

void TimeModeConfigView::scrollWheelStopUpdateItem(ChannelContainer& item, int16_t itemIndex)
{
	item.updateText(activeChannels[itemIndex]);
}

void TimeModeConfigView::scrollWheelStopUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex)
{
	item.updateText(activeChannels[itemIndex]);
}

// The callback updates the selectedVal on the itemSelected parameter
void TimeModeConfigView::scrollWheelINPUTAnimateToHandler(int16_t itemSelected)
{
	textChannelINPUT.invalidate();	//-- remove
//	int16_t numberChannel = itemSelected + 1;		//-- remove
	m_channelInput = itemSelected + 1;
	Unicode::snprintf(textChannelINPUTBuffer, TEXTCHANNELINPUT_SIZE, "%d", m_channelInput);	//-- remove
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
	bool CurrentState = toggleChannel.getState();
	setChannelStateUI(pChannelInput, CurrentState);
	TimeModeConfigView::setGuiTouchable(CurrentState);
}

void TimeModeConfigView::scrollWheelTISetupAnimateToHandler(int16_t itemSelected)
{
	textOnOffChannel.invalidate();
	m_channelTiSetup = itemSelected + 1;
	Unicode::snprintf(textOnOffChannelBuffer, TEXTONOFFCHANNEL_SIZE, "%d", m_channelTiSetup);	//-- remove
	switch(m_channelTiSetup)
	{
	case 1:
		readStateChannel(pChannel1->getStateChannel());
		updateStartStopIn(pChannel1);
		break;
	case 2:
		readStateChannel(pChannel2->getStateChannel());
		updateStartStopIn(pChannel2);
		break;
	case 3:
		readStateChannel(pChannel3->getStateChannel());
		updateStartStopIn(pChannel3);
		break;
	case 4:
		readStateChannel(pChannel4->getStateChannel());
		updateStartStopIn(pChannel4);
		break;
	case 5:
		readStateChannel(pChannel5->getStateChannel());
		updateStartStopIn(pChannel5);
		break;
	case 6:
		readStateChannel(pChannel6->getStateChannel());
		updateStartStopIn(pChannel6);
		break;
	case 7:
		readStateChannel(pChannel7->getStateChannel());
		updateStartStopIn(pChannel7);
		break;
	case 8:
		readStateChannel(pChannel8->getStateChannel());
		updateStartStopIn(pChannel8);
		break;
	}
}

void TimeModeConfigView::scrollWheelStartAnimateToHandler(int16_t itemSelected)
{
	textStartChannel.invalidate();
	m_channelTiSetupStart = activeChannels[itemSelected];
	Unicode::snprintf(textStartChannelBuffer, TEXTSTARTCHANNEL_SIZE, "%d", m_channelTiSetupStart);	//-- remove
	switch(m_channelTiSetup)
	{
	case 1:
		pChannel1->setStartChannel(m_channelTiSetupStart);
		updateStartStopIn(pChannel1);
		break;
	case 2:
		pChannel2->setStartChannel(m_channelTiSetupStart);
		updateStartStopIn(pChannel2);
		break;
	case 3:
		pChannel3->setStartChannel(m_channelTiSetupStart);
		updateStartStopIn(pChannel3);
		break;
	case 4:
		pChannel4->setStartChannel(m_channelTiSetupStart);
		updateStartStopIn(pChannel4);
		break;
	case 5:
		pChannel5->setStartChannel(m_channelTiSetupStart);
		updateStartStopIn(pChannel5);
		break;
	case 6:
		pChannel6->setStartChannel(m_channelTiSetupStart);
		updateStartStopIn(pChannel6);
		break;
	case 7:
		pChannel7->setStartChannel(m_channelTiSetupStart);
		updateStartStopIn(pChannel7);
		break;
	case 8:
		pChannel8->setStartChannel(m_channelTiSetupStart);
		updateStartStopIn(pChannel8);
		break;
	}
}

void TimeModeConfigView::scrollWheelStopAnimateToHandler(int16_t itemSelected)
{
	textStopChannel.invalidate();
	m_channelTiSetupStop = activeChannels[itemSelected];
	Unicode::snprintf(textStopChannelBuffer, TEXTSTOPCHANNEL_SIZE, "%d", m_channelTiSetupStop);	//-- remove
	switch(m_channelTiSetup)
	{
	case 1:
		pChannel1->setStopChannel(m_channelTiSetupStop);
		updateStartStopIn(pChannel1);
		break;
	case 2:
		pChannel2->setStopChannel(m_channelTiSetupStop);
		updateStartStopIn(pChannel2);
		break;
	case 3:
		pChannel3->setStopChannel(m_channelTiSetupStop);
		updateStartStopIn(pChannel3);
		break;
	case 4:
		pChannel4->setStopChannel(m_channelTiSetupStop);
		updateStartStopIn(pChannel4);
		break;
	case 5:
		pChannel5->setStopChannel(m_channelTiSetupStop);
		updateStartStopIn(pChannel5);
		break;
	case 6:
		pChannel6->setStopChannel(m_channelTiSetupStop);
		updateStartStopIn(pChannel6);
		break;
	case 7:
		pChannel7->setStopChannel(m_channelTiSetupStop);
		updateStartStopIn(pChannel7);
		break;
	case 8:
		pChannel8->setStopChannel(m_channelTiSetupStop);
		updateStartStopIn(pChannel8);
		break;
	}
}

// obsluga slidera threshold
void TimeModeConfigView::sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
        //execute code whenever the slider starts changing value.
    	setThresholdUI(pChannelInput, (uint32_t)value);
        Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
        textSliderThreshold.invalidate();
    }
}

// obsluga slidera threshold
void TimeModeConfigView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
        //execute code whenever the slider starts changing value.
    	setThresholdUI(pChannelInput, (uint32_t)value);
        Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
        textSliderThreshold.invalidate();
    }
}

// obsluga slidera threshold
void TimeModeConfigView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
        //execute code whenever the slider starts changing value.
    	setThresholdUI(pChannelInput, (uint32_t)value);
        Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
        textSliderThreshold.invalidate();
    }
}

// obsluga radiobutton   -- remove
void TimeModeConfigView::RadioBtnGroupSlopeCallbackHandler(const touchgfx::AbstractButton& src)
{
	if(&src == &radioSlopeUp)
	{
		setSlopeUI(pChannelInput, SlopeName::UP);
	}
	else if(&src == &radioSlopeDown)
	{
		setSlopeUI(pChannelInput, SlopeName::DOWN);
	}
	else if(&src == &radioThresholdManual)
	{
		setThresholdModeUI(pChannelInput, ThresholdName::Manula);
	}
	else if(&src == &radioThresholdDefined)
	{
		setThresholdModeUI(pChannelInput, ThresholdName::Defined);
	}
	radioSlopeUp.invalidate();
	radioSlopeDown.invalidate();
	radioThresholdManual.invalidate();
	radioThresholdDefined.invalidate();
}

void TimeModeConfigView::ChangeChannelState()
{
	bool CurrentState = toggleChannel.getState();
	TimeModeConfigView::setGuiTouchable(CurrentState);
	setChannelStateUI(pChannelInput ,CurrentState);

	setActiveListChannels(m_channelInput, CurrentState);
	readStateChannel(pChannel4->getStateChannel());
	updateScrollTiSetup();
}

// moje funkcje

void  TimeModeConfigView::setGuiTouchable(bool state)
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

uint16_t TimeModeConfigView::getCurrentChannel()
{
	return m_channelInput;
}

void TimeModeConfigView::setChannelStateUI(std::shared_ptr<TimeModeParameter>& channel, bool state)
{
	channel->setStateChannel(state);
}

// funkcja do ustawienia zboczy (odczytywanie z obiektow)
void TimeModeConfigView::readSlopeUI(SlopeName slopeUi)
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

// funkcja do ustawienia zboczy (wpisywanie do obiektow)
void TimeModeConfigView::setSlopeUI(std::shared_ptr<TimeModeParameter>& channel, SlopeName slopeUi)
{
	channel->setSlope(slopeUi);
}

void TimeModeConfigView::readThresholdModeUI(ThresholdName ThresholdMode)
{
	if (ThresholdMode == ThresholdName::Manula)
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

void TimeModeConfigView::setThresholdModeUI(std::shared_ptr<TimeModeParameter>& channel, ThresholdName ThresholdMode)
{
	channel->setThresholdMode(ThresholdMode);
}

void TimeModeConfigView::readThresholdUI(uint32_t value)
{
    Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
    textSliderThreshold.invalidate();
    sliderThreshold.setValue((uint32_t)value);
}

void TimeModeConfigView::setThresholdUI(std::shared_ptr<TimeModeParameter>& channel, uint32_t value)
{
	channel->setThreshold(value);
}

void TimeModeConfigView::readStateChannel(bool stateChannel)
{
	if (stateChannel == true)
	{
		textOnState.setVisible(true);
		textOffState.setVisible(false);
		textStartChannel.setVisible(false);
		textStopChannel.setVisible(false);
	}
	else
	{
		textOnState.setVisible(false);
		textOffState.setVisible(true);
		textStartChannel.setVisible(true);
		textStopChannel.setVisible(true);
	}
	textOnState.invalidate();
	textOffState.invalidate();
	textStartChannel.invalidate();
	textStopChannel.invalidate();
}

void TimeModeConfigView::setActiveListChannels(int16_t channel, bool chanelState)
{
	if (chanelState == true)
	{
		if (!(std::find(activeChannels.begin(), activeChannels.end(), channel)!=activeChannels.end()))
		{
			activeChannels.push_back(channel);
		}
	}
	else
	{
		if (std::find(activeChannels.begin(), activeChannels.end(), channel)!=activeChannels.end())
		{
			activeChannels.erase(std::remove(activeChannels.begin(), activeChannels.end(), channel), activeChannels.end());
		}
	}
}

void TimeModeConfigView::updateScrollTiSetup()
{
	if (activeChannels.size() == 0)
	{
		scrollWheelStart.setVisible(false);
		textStartChannel.setVisible(false);
		scrollWheelStop.setVisible(false);
		textStopChannel.setVisible(false);
	}
	else
	{
		scrollWheelStart.setVisible(true);
		textStartChannel.setVisible(true);
		scrollWheelStop.setVisible(true);
		textStopChannel.setVisible(true);
		scrollWheelStart.setNumberOfItems(activeChannels.size());
		scrollWheelStop.setNumberOfItems(activeChannels.size());
		for (int i = 0; i < scrollWheelStartListItems.getNumberOfDrawables(); i++)
		{
			scrollWheelStart.itemChanged(i);
			scrollWheelStop.itemChanged(i);
		}
		scrollWheelStart.animateToItem(0);
		scrollWheelStop.animateToItem(0);
	}
}

void TimeModeConfigView::updateStartStopIn(std::shared_ptr<TimeModeParameter>& channel)
{
	if (channel->getStateChannel() == false)
	{
		textStartChannel.setVisible(false);
		textStopChannel.setVisible(false);
	}
	else
	{
		if (channel->getStartChannel() == 0)
		{
			textStartChannel.setVisible(false);
		}
		else
		{
			textStartChannel.setVisible(true);
		}
		if (channel->getStopChannel() == 0)
		{
			textStopChannel.setVisible(false);
		}
		else
		{
			textStopChannel.setVisible(true);
		}

		Unicode::snprintf(textStartChannelBuffer, TEXTSTARTCHANNEL_SIZE, "%d", channel->getStartChannel());
		Unicode::snprintf(textStopChannelBuffer, TEXTSTOPCHANNEL_SIZE, "%d", channel->getStopChannel());
		textStartChannel.invalidate();
		textStopChannel.invalidate();
	}
}
