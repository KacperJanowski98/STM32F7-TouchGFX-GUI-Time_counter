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
	scrollWheelINPUT.animateToItem(0);

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
	updateClockSourceUI(pSession->getSourceClock());
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
	m_channelInput = itemSelected + 1;
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
	m_channelTiSetup = itemSelected + 1;
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
    	setThresholdUI(pChannelInput, value);
    	setValueSliderThresholdUI(value);
    }
    else if (&src == &sliderRange)
    {
    	setRangeUI(pSession, value);
    	setValueSliderRange(value);
    }
    else if (&src == &sliderStampsNumber)
    {
    	setStampsUI(pSession, value);
    	setValueSliderStampsNumberUI(value);
    }
    else if (&src == &sliderRepeat)
    {
    	setRepeatUI(pSession, value);
    	setValueSliderRepeatUI(value);
    }
}

// Obsluga slidera threshold.
void TimeModeConfigView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
    	setThresholdUI(pChannelInput, (uint32_t)value);
    	setValueSliderThresholdUI(value);
    }
    else if (&src == &sliderRange)
    {
    	setRangeUI(pSession, value);
    	setValueSliderRange(value);
    }
    else if (&src == &sliderStampsNumber)
    {
    	setStampsUI(pSession, value);
    	setValueSliderStampsNumberUI(value);
    }
    else if (&src == &sliderRepeat)
    {
    	setRepeatUI(pSession, value);
    	setValueSliderRepeatUI(value);
    }
}

// Obsluga slidera threshold.
void TimeModeConfigView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderThreshold)
    {
    	setThresholdUI(pChannelInput, (uint32_t)value);
        setValueSliderThresholdUI(value);
    }
    else if (&src == &sliderRange)
    {
    	setRangeUI(pSession, value);
    	setValueSliderRange(value);
    }
    else if (&src == &sliderStampsNumber)
    {
    	setStampsUI(pSession, value);
    	setValueSliderStampsNumberUI(value);
    }
    else if (&src == &sliderRepeat)
    {
    	setRepeatUI(pSession, value);
    	setValueSliderRepeatUI(value);
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
		pSession->setClockSource(ClockName::INTERNAL_QUARTZ);
	}
	else if (&src == &radioClockRubid)
	{
		pSession->setClockSource(ClockName::INTERNAL_RUBID);
	}
	else if (&src == &radioClockExternal)
	{
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

	if (CurrentState == false)
	{
		imageLockInput.setVisible(true);
		boxLockInput.setVisible(true);
	} else
	{
		imageLockInput.setVisible(false);
		boxLockInput.setVisible(false);
	}
	imageLockInput.invalidate();
	boxLockInput.invalidate();
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
		imageLock.setVisible(true);
		boxLock.setVisible(true);
		scrollWheelStart.setTouchable(false);
		scrollWheelStop.setTouchable(false);
	} else
	{
		imageLock.setVisible(false);
		boxLock.setVisible(false);
		scrollWheelStart.setTouchable(true);
		scrollWheelStop.setTouchable(true);
	}
	imageLock.invalidate();
	boxLock.invalidate();
}

void TimeModeConfigView::detectThreshold()
{
	presenter->askForDetectedThreshold();
	setThresholdUI(pChannelInput, detectedThresholdTime);
	setValueSliderThresholdUI(detectedThresholdTime);
    sliderThreshold.setValue(detectedThresholdTime);
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
    	imageLockInput.setVisible(true);
    	boxLockInput.setVisible(true);
    }
    else
    {
    	radioSlopeUp.setTouchable(true);
    	radioSlopeDown.setTouchable(true);
    	sliderThreshold.setTouchable(true);
    	buttonDetect.setTouchable(true);
    	imageLockInput.setVisible(false);
    	boxLockInput.setVisible(false);
    }
    imageLockInput.invalidate();
    boxLockInput.invalidate();
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

void TimeModeConfigView::setValueSliderThresholdUI(int value)
{
    Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
    textSliderThreshold.invalidate();
}

void TimeModeConfigView::setValueSliderRange(int value)
{
	Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%d", value);
	textRangeVal.invalidate();
}

void TimeModeConfigView::setValueSliderStampsNumberUI(int value)
{
	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", value);
	textStampsVal.invalidate();
}

void TimeModeConfigView::setValueSliderRepeatUI(int value)
{
	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", value);
	textRepeatVal.invalidate();
}

void TimeModeConfigView::readStateChannel(bool stateChannel)
{
	if (stateChannel == true)
	{
		textStartChannel.setVisible(false);
		textStopChannel.setVisible(false);
		imageLock.setVisible(true);
		boxLock.setVisible(true);
		scrollWheelStart.setTouchable(false);
		scrollWheelStop.setTouchable(false);
	}
	else
	{
		textStartChannel.setVisible(true);
		textStopChannel.setVisible(true);
		imageLock.setVisible(false);
		boxLock.setVisible(false);
		scrollWheelStart.setTouchable(true);
		scrollWheelStop.setTouchable(true);
	}
	textStartChannel.invalidate();
	textStopChannel.invalidate();
	imageLock.invalidate();
	boxLock.invalidate();
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
		imageLock.setVisible(true);
		boxLock.setVisible(true);
		scrollWheelStart.setTouchable(false);
		scrollWheelStop.setTouchable(false);
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
		scrollWheelStart.setTouchable(true);
		scrollWheelStop.setTouchable(true);
		imageLock.setVisible(false);
		boxLock.setVisible(false);
	}
	imageLock.invalidate();
	boxLock.invalidate();
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
	application().gotoTimeModeScreenWipeTransitionEast();
}

void TimeModeConfigView::FinishSetupTimeModeConst()
{
	updateTimeParameterBackend();

	presenter->askForDataTimeConst();
	application().gotoTimeModeScreenWipeTransitionEast();
}

void TimeModeConfigView::FinishSetupTimeModeStamps()
{
	updateTimeParameterBackend();

	presenter->askForDataTimeStamps();
	application().gotoTimeModeScreenWipeTransitionEast();
}

void TimeModeConfigView::FinishSetupTimeModeRepeat()
{
	updateTimeParameterBackend();

	presenter->askForDataTimeRepeat();
	application().gotoTimeModeScreenWipeTransitionEast();
}

void TimeModeConfigView::updateTimeParameterBackend()
{
	updateChannelBackendStruct(&TimeBackend.Channel1, pChannel1);
	updateTiBackendStruct(&TimeBackend.TiSetup1, pChannel1);

	updateChannelBackendStruct(&TimeBackend.Channel2, pChannel2);
	updateTiBackendStruct(&TimeBackend.TiSetup2, pChannel2);

	updateChannelBackendStruct(&TimeBackend.Channel3, pChannel3);
	updateTiBackendStruct(&TimeBackend.TiSetup3, pChannel3);

	updateChannelBackendStruct(&TimeBackend.Channel4, pChannel4);
	updateTiBackendStruct(&TimeBackend.TiSetup4, pChannel4);

	updateChannelBackendStruct(&TimeBackend.Channel5, pChannel5);
	updateTiBackendStruct(&TimeBackend.TiSetup5, pChannel5);

	updateChannelBackendStruct(&TimeBackend.Channel6, pChannel6);
	updateTiBackendStruct(&TimeBackend.TiSetup6, pChannel6);

	updateChannelBackendStruct(&TimeBackend.Channel7, pChannel7);
	updateTiBackendStruct(&TimeBackend.TiSetup7, pChannel7);

	updateChannelBackendStruct(&TimeBackend.Channel8, pChannel8);

	updateSessionBackendStruct(&TimeBackend.TimeSession, pSession);
}

void TimeModeConfigView::updateChannelBackendStruct(TimeChannel_t *pChannelBack, std::shared_ptr<TimeModeParameter> pChannel)
{
	pChannelBack->channelState = pChannel->getStateChannel();
	pChannelBack->slope = static_cast<Slope_t>(pChannel->getSlope());
	pChannelBack->threshold = pChannel->getThreshold();
}

void TimeModeConfigView::updateTiBackendStruct(TimeTi_t *pTiBack, std::shared_ptr<TimeModeParameter> pTi)
{
	pTiBack->tiState = pTi->getTiState();
	pTiBack->startIn = pTi->getStartChannel();
	pTiBack->stopIn = pTi->getStopChannel();
}

void TimeModeConfigView::updateSessionBackendStruct(SessionSetup_t *pSessionBack, std::shared_ptr<SessionSetup> pSession)
{
	pSessionBack->clock = static_cast<Clock_t>(pSession->getSourceClock());
	pSessionBack->maxRange = pSession->getMaxRange();
	pSessionBack->repeat = pSession->getRepeat();
	pSessionBack->stampsNumber = pSession->getStampsNumber();
	pSessionBack->tiRange = pSession->getRange();
}
