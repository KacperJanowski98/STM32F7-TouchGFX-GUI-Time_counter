#include <gui/timemodeconfig_screen/TimeModeConfigView.hpp>

TimeModeConfigView::TimeModeConfigView()
	: scrollWheelINPUTAnimateToCallback(this, &TimeModeConfigView::scrollWheelINPUTAnimateToHandler)
	, scrollWheelTISetupAnimateToCallback(this, &TimeModeConfigView::scrollWheelTISetupAnimateToHandler)
	, scrollWheelStartAnimateToCallback(this, &TimeModeConfigView::scrollWheelStartAnimateToHandler)
	, scrollWheelStopAnimateToCallback(this, &TimeModeConfigView::scrollWheelStopAnimateToHandler)
	, sliderValueChangedCallback(this, &TimeModeConfigView::sliderValueChangedCallbackHandler)
	, sliderValueConfirmedCallback(this, &TimeModeConfigView::sliderValueConfirmedCallbackHandler)
	, RadioBtnGroupSlopeCallback(this, &TimeModeConfigView::RadioBtnGroupSlopeCallbackHandler)
	, RadioBtnGroupSessionCallback(this, &TimeModeConfigView::RadioBtnGroupSessionCallbackHandler)
	, Channel1(1, false, SlopeName::UP, 0, 0, 0)
	, Channel2(2, false, SlopeName::UP, 0, 0, 0)
	, Channel3(3, false, SlopeName::UP, 0, 0, 0)
	, Channel4(4, false, SlopeName::UP, 0, 0, 0)
	, Channel5(5, false, SlopeName::UP, 0, 0, 0)
	, Channel6(6, false, SlopeName::UP, 0, 0, 0)
	, Channel7(7, false, SlopeName::UP, 0, 0, 0)
	, Channel8(8, false, SlopeName::UP, 0, 0, 0)
{
	radioButtonGroupSlope.setRadioButtonSelectedHandler(RadioBtnGroupSlopeCallback);
	radioButtonGroupModeSession.setRadioButtonSelectedHandler(RadioBtnGroupSessionCallback);
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

	// Elementy Scroll wheel sa aktualizowane zgodnie z wybranymi numerami.
	for (int i = 0; i < scrollWheelINPUTListItems.getNumberOfDrawables(); i++)
	{
		scrollWheelINPUT.itemChanged(i);
		scrollWheelTISetup.itemChanged(i);
	}
	scrollWheelINPUT.animateToItem(3);
	scrollWheelTISetup.animateToItem(3);

	// Aktualizacja elementow scroll wheel dla ustawienia kanalu start i stop.
	updateScrollTiSetup();

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

    sliderRate.setStartValueCallback(sliderValueStartedChangeCallback);
    sliderRate.setNewValueCallback(sliderValueChangedCallback);
    sliderRate.setStopValueCallback(sliderValueConfirmedCallback);

    sliderStampsNumber.setStartValueCallback(sliderValueStartedChangeCallback);
    sliderStampsNumber.setNewValueCallback(sliderValueChangedCallback);
    sliderStampsNumber.setStopValueCallback(sliderValueConfirmedCallback);
    // obsluga toggle butona    
	TimeModeConfigView::setGuiTouchable(toggleChannel.getState());
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
		toggleChannel.forceState(pChannel1->getStateChannel());
		break;
	case 2:
		pChannelInput = pChannel2;
		toggleChannel.forceState(pChannel2->getStateChannel());
		break;
	case 3:
		pChannelInput = pChannel3;
		toggleChannel.forceState(pChannel3->getStateChannel());
		break;
	case 4:
		pChannelInput = pChannel4;
		toggleChannel.forceState(pChannel4->getStateChannel());
		break;
	case 5:
		pChannelInput = pChannel5;
		toggleChannel.forceState(pChannel5->getStateChannel());
		break;
	case 6:
		pChannelInput = pChannel6;
		toggleChannel.forceState(pChannel6->getStateChannel());
		break;
	case 7:
		pChannelInput = pChannel7;
		toggleChannel.forceState(pChannel7->getStateChannel());
		break;
	case 8:
		pChannelInput = pChannel8;
		toggleChannel.forceState(pChannel8->getStateChannel());
		break;
	}
	initUIChannel(pChannelInput);
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
    	Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%d", value);
    	textRangeVal.invalidate();
    }
    else if (&src == &sliderStampsNumber)
    {
    	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", value);
    	textStampsVal.invalidate();
    }
    else if (&src == &sliderRepeat)
    {
    	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", value);
    	textRepeatVal.invalidate();
    }
    else if(&src == &sliderRate)
    {
    	Unicode::snprintf(textRateValBuffer, TEXTRATEVAL_SIZE, "%d", value);
    	textRateVal.invalidate();
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
    	Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%d", value);
    	textRangeVal.invalidate();
    }
    else if (&src == &sliderStampsNumber)
    {
    	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", value);
    	textStampsVal.invalidate();
    }
    else if (&src == &sliderRepeat)
    {
    	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", value);
    	textRepeatVal.invalidate();
    }
    else if(&src == &sliderRate)
    {
    	Unicode::snprintf(textRateValBuffer, TEXTRATEVAL_SIZE, "%d", value);
    	textRateVal.invalidate();
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
    	Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%d", value);
    	textRangeVal.invalidate();
    }
    else if (&src == &sliderStampsNumber)
    {
    	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", value);
    	textStampsVal.invalidate();
    }
    else if (&src == &sliderRepeat)
    {
    	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", value);
    	textRepeatVal.invalidate();
    }
    else if(&src == &sliderRate)
    {
    	Unicode::snprintf(textRateValBuffer, TEXTRATEVAL_SIZE, "%d", value);
    	textRateVal.invalidate();
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

// :TODO
void TimeModeConfigView::RadioBtnGroupSessionCallbackHandler(const touchgfx::AbstractButton& src)
{
	if(&src == &radioSingle)
	{

	}
	else if(&src == &radioContinuous)
	{

	}
}

// :TODO
void TimeModeConfigView::turnTiMaxRange()
{

}

// :TODO
void TimeModeConfigView::turnMeasRate()
{

}

void TimeModeConfigView::ChangeChannelState()
{
	bool CurrentState = toggleChannel.getState();
	TimeModeConfigView::setGuiTouchable(CurrentState);
	setChannelStateUI(pChannelInput, CurrentState);

	setActiveListChannels(m_channelInput, CurrentState);
	readStateChannel(pChannel4->getStateChannel());
	updateScrollTiSetup();
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

//
void TimeModeConfigView::FinishSetupTimeMode()
{
	presenter->askForDataTime();
	application().gotoTimeModeScreenCoverTransitionWest();
}
