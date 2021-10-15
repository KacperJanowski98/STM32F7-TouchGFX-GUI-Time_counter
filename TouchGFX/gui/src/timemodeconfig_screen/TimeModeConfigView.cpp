#include <gui/timemodeconfig_screen/TimeModeConfigView.hpp>

TimeModeConfigView::TimeModeConfigView()
	: scrollWheelINPUTAnimateToCallback(this, &TimeModeConfigView::scrollWheelINPUTAnimateToHandler)
	, scrollWheelTISetupAnimateToCallback(this, &TimeModeConfigView::scrollWheelTISetupAnimateToHandler)
	, scrollWheelStartAnimateToCallback(this, &TimeModeConfigView::scrollWheelStartAnimateToHandler)
	, scrollWheelStopAnimateToCallback(this, &TimeModeConfigView::scrollWheelStopAnimateToHandler)
	, sliderValueChangedCallback(this, &TimeModeConfigView::sliderValueChangedCallbackHandler)
	, sliderValueConfirmedCallback(this, &TimeModeConfigView::sliderValueConfirmedCallbackHandler)
	, RadioBtnGroupSlopeCallback(this, &TimeModeConfigView::RadioBtnGroupSlopeCallbackHandler)
	, RadioBtnGroupClockCallback(this, &TimeModeConfigView::RadioBtnGroupClockCallbackHandler)
	, Channel1(1, TimeBackend.Channel1.channelState, TimeBackend.TiSetup1.tiState, static_cast<SlopeName>(TimeBackend.Channel1.slope),
			TimeBackend.Channel1.threshold, TimeBackend.TiSetup1.startIn, TimeBackend.TiSetup1.stopIn)
	, Channel2(2, TimeBackend.Channel2.channelState, TimeBackend.TiSetup2.tiState, static_cast<SlopeName>(TimeBackend.Channel2.slope),
			TimeBackend.Channel2.threshold, TimeBackend.TiSetup2.startIn, TimeBackend.TiSetup2.stopIn)
	, Channel3(3, TimeBackend.Channel3.channelState, TimeBackend.TiSetup3.tiState, static_cast<SlopeName>(TimeBackend.Channel3.slope),
			TimeBackend.Channel3.threshold, TimeBackend.TiSetup3.startIn, TimeBackend.TiSetup3.stopIn)
	, Channel4(4, TimeBackend.Channel4.channelState, TimeBackend.TiSetup4.tiState, static_cast<SlopeName>(TimeBackend.Channel4.slope),
		TimeBackend.Channel4.threshold, TimeBackend.TiSetup4.startIn, TimeBackend.TiSetup4.stopIn)
	, Channel5(5, TimeBackend.Channel5.channelState, TimeBackend.TiSetup5.tiState, static_cast<SlopeName>(TimeBackend.Channel5.slope),
			TimeBackend.Channel5.threshold, TimeBackend.TiSetup5.startIn, TimeBackend.TiSetup5.stopIn)
	, Channel6(6, TimeBackend.Channel6.channelState, TimeBackend.TiSetup6.tiState, static_cast<SlopeName>(TimeBackend.Channel6.slope),
		TimeBackend.Channel6.threshold, TimeBackend.TiSetup6.startIn, TimeBackend.TiSetup6.stopIn)
	, Channel7(7, TimeBackend.Channel7.channelState, TimeBackend.TiSetup7.tiState, static_cast<SlopeName>(TimeBackend.Channel7.slope),
			TimeBackend.Channel7.threshold, TimeBackend.TiSetup7.startIn, TimeBackend.TiSetup7.stopIn)
	, Channel8(8, TimeBackend.Channel8.channelState, false, static_cast<SlopeName>(TimeBackend.Channel8.slope),
			TimeBackend.Channel8.threshold, 0, 0)
	, Session(TimeBackend.TimeSession.maxRange, static_cast<ClockName>(TimeBackend.TimeSession.clock),
			TimeBackend.TimeSession.tiRange, TimeBackend.TimeSession.stampsNumber, TimeBackend.TimeSession.repeat)
//	, Channel1(1, false, false, SlopeName::UP, 0, 0, 0)
//	, Channel2(2, false, false, SlopeName::UP, 0, 0, 0)
//	, Channel3(3, false, false, SlopeName::UP, 0, 0, 0)
//	, Channel4(4, false, false, SlopeName::UP, 0, 0, 0)
//	, Channel5(5, false, false, SlopeName::UP, 0, 0, 0)
//	, Channel6(6, false, false, SlopeName::UP, 0, 0, 0)
//	, Channel7(7, false, false, SlopeName::UP, 0, 0, 0)
//	, Channel8(8, false, false, SlopeName::UP, 0, 0, 0)
//	, Session(false, 0, 0, 0)
{
	radioButtonGroupSlope.setRadioButtonSelectedHandler(RadioBtnGroupSlopeCallback);
	radioButtonGroupClock.setRadioButtonSelectedHandler(RadioBtnGroupClockCallback);
	TimeModeConfigView::pChannel1 = std::make_shared<TimeModeParameter>(Channel1);
	TimeModeConfigView::pChannel2 = std::make_shared<TimeModeParameter>(Channel2);
	TimeModeConfigView::pChannel3 = std::make_shared<TimeModeParameter>(Channel3);
	TimeModeConfigView::pChannel4 = std::make_shared<TimeModeParameter>(Channel4);
	TimeModeConfigView::pChannel5 = std::make_shared<TimeModeParameter>(Channel5);
	TimeModeConfigView::pChannel6 = std::make_shared<TimeModeParameter>(Channel6);
	TimeModeConfigView::pChannel7 = std::make_shared<TimeModeParameter>(Channel7);
	TimeModeConfigView::pChannel8 = std::make_shared<TimeModeParameter>(Channel8);
	TimeModeConfigView::pSession = std::make_shared<SessionSetup>(Session);
}

void TimeModeConfigView::setupScreen()
{
	scrollWheelINPUT.setAnimateToCallback(scrollWheelINPUTAnimateToCallback);
	scrollWheelTISetup.setAnimateToCallback(scrollWheelTISetupAnimateToCallback);
	scrollWheelStart.setAnimateToCallback(scrollWheelStartAnimateToCallback);
	scrollWheelStop.setAnimateToCallback(scrollWheelStopAnimateToCallback);

	// Elementy Scroll wheel sa aktualizowane zgodnie z wybranymi numerami.
	for (int i = 0; i < scrollWheelINPUTListItems.getNumberOfDrawables(); i++)
	{
		scrollWheelINPUT.itemChanged(i);
	}
	scrollWheelINPUT.animateToItem(3);

//    TimeModeConfigViewBase::setupScreen();

	// obsluga sliderow
    sliderThreshold.setStartValueCallback(sliderValueStartedChangeCallback);
    sliderThreshold.setNewValueCallback(sliderValueChangedCallback);
    sliderThreshold.setStopValueCallback(sliderValueConfirmedCallback);

    sliderRange.setStartValueCallback(sliderValueStartedChangeCallback);
    sliderRange.setNewValueCallback(sliderValueChangedCallback);
    sliderRange.setStopValueCallback(sliderValueConfirmedCallback);

    sliderRepeat.setStartValueCallback(sliderValueStartedChangeCallback);
    sliderRepeat.setNewValueCallback(sliderValueChangedCallback);
    sliderRepeat.setStopValueCallback(sliderValueConfirmedCallback);

    sliderStampsNumber.setStartValueCallback(sliderValueStartedChangeCallback);
    sliderStampsNumber.setNewValueCallback(sliderValueChangedCallback);
    sliderStampsNumber.setStopValueCallback(sliderValueConfirmedCallback);
    // obsluga toggle butona    
	TimeModeConfigView::setGuiTouchable(toggleChannel.getState());
	// aktualizacja panelu konfiguracyjnego zegara
	updateClockSourceUI(Session.getSourceClock());
	// aktualizacaj session setup
	updateSessionSetupUI(pSession);
	// uzupelnienie listy aktywnych kanalow przy starcie UI
	setActiveListChannels(1, pChannel1->getStateChannel());
	setActiveListChannels(2, pChannel2->getStateChannel());
	setActiveListChannels(3, pChannel3->getStateChannel());
	setActiveListChannels(4, pChannel4->getStateChannel());
	setActiveListChannels(5, pChannel5->getStateChannel());
	setActiveListChannels(6, pChannel6->getStateChannel());
	setActiveListChannels(7, pChannel7->getStateChannel());
	setActiveListChannels(8, pChannel8->getStateChannel());

	// Aktualizacja elementow scroll wheel dla ustawienia kanalu start i stop.
	updateScrollTiSetup();

	for (int i = 0; i < scrollWheelTISetupListItems.getNumberOfDrawables(); i++)
	{
		scrollWheelTISetup.itemChanged(i);
	}
	scrollWheelTISetup.animateToItem(0);

}

void TimeModeConfigView::tearDownScreen()
{
//    TimeModeConfigViewBase::tearDownScreen();
}

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

// Wywołanie zwrotne aktualizuje selectedVal poprzez parametr itemSelected.
void TimeModeConfigView::scrollWheelINPUTAnimateToHandler(int16_t itemSelected)
{
	textChannelINPUT.invalidate();	//-- remove
	m_channelInput = itemSelected + 1;
	Unicode::snprintf(textChannelINPUTBuffer, TEXTCHANNELINPUT_SIZE, "%d", m_channelInput);	//-- remove
	switch(m_channelInput)
	{
	case 1:
		pChannelInput = pChannel1;
		break;
	case 2:
		pChannelInput = pChannel2;
		break;
	case 3:
		pChannelInput = pChannel3;
		break;
	case 4:
		pChannelInput = pChannel4;
		break;
	case 5:
		pChannelInput = pChannel5;
		break;
	case 6:
		pChannelInput = pChannel6;
		break;
	case 7:
		pChannelInput = pChannel7;
		break;
	case 8:
		pChannelInput = pChannel8;
		break;
	}
	initUIChannel(pChannelInput);
	toggleChannel.forceState(pChannelInput->getStateChannel());
	toggleChannel.invalidate();
	bool CurrentState = toggleChannel.getState();
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
		pChannelTI = pChannel1;
		break;
	case 2:
		pChannelTI = pChannel2;
		break;
	case 3:
		pChannelTI = pChannel3;
		break;
	case 4:
		pChannelTI = pChannel4;
		break;
	case 5:
		pChannelTI = pChannel5;
		break;
	case 6:
		pChannelTI = pChannel6;
		break;
	case 7:
		pChannelTI = pChannel7;
		break;
	}
	toggleTiSetup.forceState(pChannelTI->getTiState());
	updateStartStopScroolList(pChannelTI);
	updateStartStopIn(pChannelTI);
	toggleTiSetup.invalidate();
}
void TimeModeConfigView::scrollWheelStartAnimateToHandler(int16_t itemSelected)
{
	textStartChannel.invalidate();
	m_channelTiSetupStart = activeChannels[itemSelected];
	Unicode::snprintf(textStartChannelBuffer, TEXTSTARTCHANNEL_SIZE, "%d", m_channelTiSetupStart);	//-- remove
	if (swipeContainerTime.getSelectedPage() == 2)
	{
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
}

void TimeModeConfigView::scrollWheelStopAnimateToHandler(int16_t itemSelected)
{
	textStopChannel.invalidate();
	m_channelTiSetupStop = activeChannels[itemSelected];
	Unicode::snprintf(textStopChannelBuffer, TEXTSTOPCHANNEL_SIZE, "%d", m_channelTiSetupStop);	//-- remove
	if (swipeContainerTime.getSelectedPage() == 2)
	{
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
}

// Obsluga slidera threshold.
// :TODO slider dla panelu session setup
void TimeModeConfigView::sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
    	setThresholdUI(pChannelInput, (uint32_t)value);
        Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
        textSliderThreshold.invalidate();
    }
    else if (&src == &sliderRange)
    {
    	setRangeUI(pSession, value);
    	Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%d", value);
    	textRangeVal.invalidate();
    }
    else if (&src == &sliderStampsNumber)
    {
    	setStampsUI(pSession, value);
    	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", value);
    	textStampsVal.invalidate();
    }
    else if (&src == &sliderRepeat)
    {
    	setRepeatUI(pSession, value);
    	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", value);
    	textRepeatVal.invalidate();
    }
}

// Obsluga slidera threshold.
void TimeModeConfigView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
    	setThresholdUI(pChannelInput, (uint32_t)value);
        Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
        textSliderThreshold.invalidate();
    }
    else if (&src == &sliderRange)
    {
    	setRangeUI(pSession, value);
    	Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%d", value);
    	textRangeVal.invalidate();
    }
    else if (&src == &sliderStampsNumber)
    {
    	setStampsUI(pSession, value);
    	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", value);
    	textStampsVal.invalidate();
    }
    else if (&src == &sliderRepeat)
    {
    	setRepeatUI(pSession, value);
    	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", value);
    	textRepeatVal.invalidate();
    }
}

// Obsluga slidera threshold.
void TimeModeConfigView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
    	setThresholdUI(pChannelInput, (uint32_t)value);
        Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
        textSliderThreshold.invalidate();
    }
    else if (&src == &sliderRange)
    {
    	setRangeUI(pSession, value);
    	Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%d", value);
    	textRangeVal.invalidate();
    }
    else if (&src == &sliderStampsNumber)
    {
    	setStampsUI(pSession, value);
    	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", value);
    	textStampsVal.invalidate();
    }
    else if (&src == &sliderRepeat)
    {
    	setRepeatUI(pSession, value);
    	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", value);
    	textRepeatVal.invalidate();
    }
}

// Obsluga radiobutton. 
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
	radioSlopeUp.invalidate();
	radioSlopeDown.invalidate();
}

void TimeModeConfigView::RadioBtnGroupClockCallbackHandler(const touchgfx::AbstractButton& src)
{
	if(&src == &radioClockQuartz)
	{
//		TimeModeConfigView::m_clockSource = ClockName::INTERNAL_QUARTZ;
		pSession->setClockSource(ClockName::INTERNAL_QUARTZ);
	}
	else if (&src == &radioClockRubid)
	{
//		TimeModeConfigView::m_clockSource = ClockName::INTERNAL_RUBID;
		pSession->setClockSource(ClockName::INTERNAL_RUBID);
	}
	else if (&src == &radioClockExternal)
	{
//		TimeModeConfigView::m_clockSource = ClockName::EXTERNAL;
		pSession->setClockSource(ClockName::EXTERNAL);
	}
}

// :TODO
void TimeModeConfigView::turnTiMaxRange()
{
	bool CurrentState = toggleTiMaxRange.getState();
	if (CurrentState == true)
	{
		Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%d", sliderRange.getMaxValue());
		textRangeVal.invalidate();
		sliderRange.setValue(sliderRange.getMaxValue());
		setRangeUI(pSession, sliderRange.getMaxValue());
		sliderRange.setTouchable(false);
	}
	else
	{
		sliderRange.setTouchable(true);
	}
}

void TimeModeConfigView::ChangeChannelState()
{
	bool CurrentState = toggleChannel.getState();
	TimeModeConfigView::setGuiTouchable(CurrentState);
	setChannelStateUI(pChannelInput, CurrentState);

	setActiveListChannels(m_channelInput, CurrentState);
	updateScrollTiSetup();
	scrollWheelTISetup.animateToItem(0);
}

void TimeModeConfigView::ChangeStateTI()
{
	bool CurrentState = toggleTiSetup.getState();
	setTiChannelStateUI(pChannelTI, CurrentState);
	updateStartStopScroolList(pChannelTI);
	updateStartStopIn(pChannelTI);

	if (CurrentState == false)
	{
		pChannelTI->setStartChannel(0);
		pChannelTI->setStopChannel(0);
	}
}

void TimeModeConfigView::detectThreshold()
{
	presenter->askForDetectedThreshold();
	setThresholdUI(pChannelInput, detectedThresholdTime);
    Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", detectedThresholdTime);
    sliderThreshold.setValue(detectedThresholdTime);
    textSliderThreshold.invalidate();
}

void TimeModeConfigView::initUIChannel(std::shared_ptr<TimeModeParameter>& channel)
{
	readSlopeUI(channel->getSlope());
	readThresholdUI(channel->getThreshold());
}

void  TimeModeConfigView::setGuiTouchable(bool state)
{
    if (state == false)
    {
    	radioSlopeUp.setTouchable(false);
    	radioSlopeDown.setTouchable(false);
    	sliderThreshold.setTouchable(false);
    	buttonDetect.setTouchable(false);
    }
    else
    {
    	radioSlopeUp.setTouchable(true);
    	radioSlopeDown.setTouchable(true);
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

void TimeModeConfigView::setTiChannelStateUI(std::shared_ptr<TimeModeParameter>& channel, bool state)
{
	channel->setTiState(state);
}

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

void TimeModeConfigView::setSlopeUI(std::shared_ptr<TimeModeParameter>& channel, SlopeName slopeUi)
{
	channel->setSlope(slopeUi);
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

void TimeModeConfigView::setRangeUI(std::shared_ptr<SessionSetup>& session, uint16_t value)
{
	session->setRange(value);
}

void TimeModeConfigView::setStampsUI(std::shared_ptr<SessionSetup>& session, uint16_t value)
{
	session->setStampsNumber(value);
}

void TimeModeConfigView::setRepeatUI(std::shared_ptr<SessionSetup>& session, uint16_t value)
{
	session->setRepeat(value);
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
		if (std::find(activeChannels.begin(), activeChannels.end(), channel) == activeChannels.end())
		{
			activeChannels.push_back(channel);
		}
	}
	else
	{
		if (std::find(activeChannels.begin(), activeChannels.end(), channel) != activeChannels.end())
		{
			activeChannels.erase(std::remove(activeChannels.begin(), activeChannels.end(), channel), activeChannels.end());
		}
	}

	std::sort(activeChannels.begin(), activeChannels.end());
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
		}
		for (int i = 0; i < scrollWheelStopListItems.getNumberOfDrawables(); i++)
		{
			scrollWheelStop.itemChanged(i);
		}
		scrollWheelStart.animateToItem(0);
		scrollWheelStop.animateToItem(0);
//		updateStartStopScroolList(pChannel1);
	}
}

void TimeModeConfigView::updateStartStopIn(std::shared_ptr<TimeModeParameter>& channel)
{
	readStateChannel(channel->getTiState());

	if (channel->getTiState() == false)
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

void TimeModeConfigView::updateStartStopScroolList(std::shared_ptr<TimeModeParameter>& channel)
{
	if ((channel->getStartChannel() != 0) && (channel->getStopChannel() != 0) && (channel->getTiState() == true))
	{
		std::vector<int16_t>::iterator itrStart = std::find(activeChannels.begin(), activeChannels.end(), channel->getStartChannel());
		std::vector<int16_t>::iterator itrStop = std::find(activeChannels.begin(), activeChannels.end(), channel->getStopChannel());

		scrollWheelStart.animateToItem(std::distance(activeChannels.begin(), itrStart));
		scrollWheelStop.animateToItem(std::distance(activeChannels.begin(), itrStop));
	}
}

void TimeModeConfigView::updateClockSourceUI(ClockName clk)
{
	if (clk == ClockName::INTERNAL_QUARTZ)
	{
		radioClockQuartz.setSelected(true);
	}
	else if (clk == ClockName::INTERNAL_RUBID)
	{
		radioClockRubid.setSelected(true);
	}
	else if (clk == ClockName::EXTERNAL)
	{
		radioClockExternal.setSelected(true);
	}
}

void TimeModeConfigView::updateSessionSetupUI(std::shared_ptr<SessionSetup>& session)
{
	toggleTiMaxRange.forceState(session->getMaxRange());

	if (session->getMaxRange() == true)
	{
		sliderRange.setTouchable(false);
	}
	else
	{
		sliderRange.setTouchable(true);
	}

	Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%d", session->getRange());
	textRangeVal.invalidate();
	sliderRange.setValue(session->getRange());

	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", session->getStampsNumber());
	textStampsVal.invalidate();
	sliderStampsNumber.setValue(session->getStampsNumber());

	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", session->getRepeat());
	textRepeatVal.invalidate();
	sliderRepeat.setValue(session->getRepeat());
}

//
void TimeModeConfigView::FinishSetupTimeModeSingle()
{
	updateTimeParameterBackend();

	presenter->askForDataTimeSingle();
	application().gotoTimeModeScreenCoverTransitionWest();
}

void TimeModeConfigView::FinishSetupTimeModeConst()
{
	updateTimeParameterBackend();

	presenter->askForDataTimeConst();
	application().gotoTimeModeScreenCoverTransitionWest();
}

void TimeModeConfigView::FinishSetupTimeModeStamps()
{
	updateTimeParameterBackend();

	presenter->askForDataTimeStamps();
	application().gotoTimeModeScreenCoverTransitionWest();
}

void TimeModeConfigView::updateTimeParameterBackend()
{
	TimeBackend.Channel1.channelState = pChannel1->getStateChannel();
	TimeBackend.Channel1.slope = static_cast<Slope_t>(pChannel1->getSlope());
	TimeBackend.Channel1.threshold = pChannel1->getThreshold();
	TimeBackend.TiSetup1.tiState = pChannel1->getTiState();
	TimeBackend.TiSetup1.startIn = pChannel1->getStartChannel();
	TimeBackend.TiSetup1.stopIn = pChannel1->getStopChannel();

	TimeBackend.Channel2.channelState = pChannel2->getStateChannel();
	TimeBackend.Channel2.slope = static_cast<Slope_t>(pChannel2->getSlope());
	TimeBackend.Channel2.threshold = pChannel2->getThreshold();
	TimeBackend.TiSetup2.tiState = pChannel2->getTiState();
	TimeBackend.TiSetup2.startIn = pChannel2->getStartChannel();
	TimeBackend.TiSetup2.stopIn = pChannel2->getStopChannel();

	TimeBackend.Channel3.channelState = pChannel3->getStateChannel();
	TimeBackend.Channel3.slope = static_cast<Slope_t>(pChannel3->getSlope());
	TimeBackend.Channel3.threshold = pChannel3->getThreshold();
	TimeBackend.TiSetup3.tiState = pChannel3->getTiState();
	TimeBackend.TiSetup3.startIn = pChannel3->getStartChannel();
	TimeBackend.TiSetup3.stopIn = pChannel3->getStopChannel();

	TimeBackend.Channel4.channelState = pChannel4->getStateChannel();
	TimeBackend.Channel4.slope = static_cast<Slope_t>(pChannel4->getSlope());
	TimeBackend.Channel4.threshold = pChannel4->getThreshold();
	TimeBackend.TiSetup4.tiState = pChannel4->getTiState();
	TimeBackend.TiSetup4.startIn = pChannel4->getStartChannel();
	TimeBackend.TiSetup4.stopIn = pChannel4->getStopChannel();

	TimeBackend.Channel5.channelState = pChannel5->getStateChannel();
	TimeBackend.Channel5.slope = static_cast<Slope_t>(pChannel5->getSlope());
	TimeBackend.Channel5.threshold = pChannel5->getThreshold();
	TimeBackend.TiSetup5.tiState = pChannel5->getTiState();
	TimeBackend.TiSetup5.startIn = pChannel5->getStartChannel();
	TimeBackend.TiSetup5.stopIn = pChannel5->getStopChannel();

	TimeBackend.Channel6.channelState = pChannel6->getStateChannel();
	TimeBackend.Channel6.slope = static_cast<Slope_t>(pChannel6->getSlope());
	TimeBackend.Channel6.threshold = pChannel6->getThreshold();
	TimeBackend.TiSetup6.tiState = pChannel6->getTiState();
	TimeBackend.TiSetup6.startIn = pChannel6->getStartChannel();
	TimeBackend.TiSetup6.stopIn = pChannel6->getStopChannel();

	TimeBackend.Channel7.channelState = pChannel7->getStateChannel();
	TimeBackend.Channel7.slope = static_cast<Slope_t>(pChannel7->getSlope());
	TimeBackend.Channel7.threshold = pChannel7->getThreshold();
	TimeBackend.TiSetup7.tiState = pChannel7->getTiState();
	TimeBackend.TiSetup7.startIn = pChannel7->getStartChannel();
	TimeBackend.TiSetup7.stopIn = pChannel7->getStopChannel();

	TimeBackend.Channel8.channelState = pChannel8->getStateChannel();
	TimeBackend.Channel8.slope = static_cast<Slope_t>(pChannel8->getSlope());
	TimeBackend.Channel8.threshold = pChannel8->getThreshold();

	TimeBackend.TimeSession.clock = static_cast<Clock_t>(pSession->getSourceClock());
	TimeBackend.TimeSession.maxRange = pSession->getMaxRange();
	TimeBackend.TimeSession.repeat = pSession->getRepeat();
	TimeBackend.TimeSession.stampsNumber = pSession->getStampsNumber();
	TimeBackend.TimeSession.tiRange = pSession->getRange();
}
