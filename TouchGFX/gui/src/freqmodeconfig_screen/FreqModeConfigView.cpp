#include <gui/freqmodeconfig_screen/FreqModeConfigView.hpp>

FreqModeConfigView::FreqModeConfigView()
	: scrollWheelINPUTAnimateToCallback(this, &FreqModeConfigView::scrollWheelINPUTAnimateToHandler)
	, sliderValueStartedChangeCallback(this, &FreqModeConfigView::sliderValueStartedChangeCallbackHandler)
	, sliderValueChangedCallback(this, &FreqModeConfigView::sliderValueChangedCallbackHandler)
	, sliderValueConfirmedCallback(this, &FreqModeConfigView::sliderValueConfirmedCallbackHandler)
	, RadioBtnGroupFreqCallback(this, &FreqModeConfigView::RadioBtnGroupFreqCallbackHandler)
	, RadioBtnGroupHfInputCallback(this, &FreqModeConfigView::RadioBtnGroupHfInputCallbackHandler)
	, RadioBtnGroupClockCallback(this, &FreqModeConfigView::RadioBtnGroupClockCallbackHandler)
	, Channel1(FreqBackend.Channel1.numberChanel, FreqBackend.Channel1.channelState, static_cast<SlopeName>(FreqBackend.Channel1.slope), FreqBackend.Channel1.threshold)
	, Channel2(FreqBackend.Channel2.numberChanel, FreqBackend.Channel2.channelState, static_cast<SlopeName>(FreqBackend.Channel2.slope), FreqBackend.Channel2.threshold)
	, Channel3(FreqBackend.Channel3.numberChanel, FreqBackend.Channel3.channelState, static_cast<SlopeName>(FreqBackend.Channel3.slope), FreqBackend.Channel3.threshold)
	, Channel4(FreqBackend.Channel4.numberChanel, FreqBackend.Channel4.channelState, static_cast<SlopeName>(FreqBackend.Channel4.slope), FreqBackend.Channel4.threshold)
	, Channel5(FreqBackend.Channel5.numberChanel, FreqBackend.Channel5.channelState, static_cast<SlopeName>(FreqBackend.Channel5.slope), FreqBackend.Channel5.threshold)
	, Channel6(FreqBackend.Channel6.numberChanel, FreqBackend.Channel6.channelState, static_cast<SlopeName>(FreqBackend.Channel6.slope), FreqBackend.Channel6.threshold)
	, Channel7(FreqBackend.Channel7.numberChanel, FreqBackend.Channel7.channelState, static_cast<SlopeName>(FreqBackend.Channel7.slope), FreqBackend.Channel7.threshold)
	, Channel8(FreqBackend.Channel8.numberChanel, FreqBackend.Channel8.channelState, static_cast<SlopeName>(FreqBackend.Channel8.slope), FreqBackend.Channel8.threshold)
    , Session(false, static_cast<ClockName>(FreqBackend.FreqSession.clock), 0, FreqBackend.FreqSession.stampsNumber, FreqBackend.FreqSession.repeat)
//	, Channel1(1, false, SlopeName::UP, 0)
//	, Channel2(2, false, SlopeName::UP, 0)
//	, Channel3(3, false, SlopeName::UP, 0)
//	, Channel4(4, false, SlopeName::UP, 0)
//	, Channel5(5, false, SlopeName::UP, 0)
//	, Channel6(6, false, SlopeName::UP, 0)
//	, Channel7(7, false, SlopeName::UP, 0)
//	, Channel8(8, false, SlopeName::UP, 0)
//	, Session(false, ClockName::INTERNAL_QUARTZ, 0, 0, 0)
{
	radioButtonGroupHfInput.setRadioButtonSelectedHandler(RadioBtnGroupHfInputCallback);
	radioButtonGroupClock.setRadioButtonSelectedHandler(RadioBtnGroupClockCallback);
	FreqModeConfigView::pChannel1 = std::make_shared<FreqModeParameter>(Channel1);
	FreqModeConfigView::pChannel2 = std::make_shared<FreqModeParameter>(Channel2);
	FreqModeConfigView::pChannel3 = std::make_shared<FreqModeParameter>(Channel3);
	FreqModeConfigView::pChannel4 = std::make_shared<FreqModeParameter>(Channel4);
	FreqModeConfigView::pChannel5 = std::make_shared<FreqModeParameter>(Channel5);
	FreqModeConfigView::pChannel6 = std::make_shared<FreqModeParameter>(Channel6);
	FreqModeConfigView::pChannel7 = std::make_shared<FreqModeParameter>(Channel7);
	FreqModeConfigView::pChannel8 = std::make_shared<FreqModeParameter>(Channel8);
	FreqModeConfigView::pSession = std::make_shared<SessionSetup>(Session);
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

	sliderGate.setStartValueCallback(sliderValueStartedChangeCallback);
	sliderGate.setNewValueCallback(sliderValueChangedCallback);
	sliderGate.setStopValueCallback(sliderValueConfirmedCallback);

	sliderStampsNumber.setStartValueCallback(sliderValueStartedChangeCallback);
	sliderStampsNumber.setNewValueCallback(sliderValueChangedCallback);
	sliderStampsNumber.setStopValueCallback(sliderValueConfirmedCallback);

	sliderRepeat.setStartValueCallback(sliderValueStartedChangeCallback);
	sliderRepeat.setNewValueCallback(sliderValueChangedCallback);
	sliderRepeat.setStopValueCallback(sliderValueConfirmedCallback);

	initMesSetupUI();

	// aktualizacja zrodla zegarowego
	updateClockSourceUI(pSession->getSourceClock());

	FreqModeConfigView::m_hfInput = FreqBackend.MessSetup.hfInputState;
	FreqModeConfigView::m_gate = FreqBackend.MessSetup.gate;

	updateMesSetupUI(FreqBackend.MessSetup.hfInputState);

	updateSessionSetupUI(pSession);
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
	m_channelInput = itemSelected + 1;
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
	bool CurrentStateUI = toggleChannel.getState();
	setChannelStateUI(pChannelInput, CurrentStateUI);
	FreqModeConfigView::setGuiTouchable(CurrentStateUI);
}

// obsluga sliderow :TODO oprogramowac slidery z panelu sessionsetup
void FreqModeConfigView::sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value)
{
	if (&src == &sliderThreshold)
	{
		setThresholdUI(pChannelInput, (uint32_t)value);
		setValueSliderThresholdUI(value);
	}
	else if (&src == &sliderGate)
	{
		setValueSliderGateUI(value);
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

void FreqModeConfigView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
	if (&src == &sliderThreshold)
	{
		setThresholdUI(pChannelInput, (uint32_t)value);
		setValueSliderThresholdUI(value);
	}
	else if (&src == &sliderGate)
	{
		setValueSliderGateUI(value);
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

void FreqModeConfigView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
	if (&src == &sliderThreshold)
	{
		setThresholdUI(pChannelInput, (uint32_t)value);
		setValueSliderThresholdUI(value);
	}
	else if (&src == &sliderGate)
	{
		setValueSliderGateUI(value);
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
	radioSlopeUp.invalidate();
	radioSlopeDown.invalidate();
}

// obsluga radio button
void FreqModeConfigView::RadioBtnGroupHfInputCallbackHandler(const touchgfx::AbstractButton& src)
{
	if (&src == &radioHfInputOff)
	{
		m_hfInput = false;
		textGateVal.setVisible(false);
		sliderGate.setTouchable(false);
	}
	else if (&src == &radioHfInputOn)
	{
		m_hfInput = true;
		textGateVal.setVisible(true);
		sliderGate.setTouchable(true);
		sliderGate.setValue(m_gate);
	}
	radioHfInputOff.invalidate();
	radioHfInputOn.invalidate();
	textGateVal.invalidate();
}

void FreqModeConfigView::RadioBtnGroupClockCallbackHandler(const touchgfx::AbstractButton& src)
{
	if (&src == &radioClockQuartz)
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

// obsluga przycisku toogle button
void FreqModeConfigView::toggleChannelState()
{
	bool CurrentState = toggleChannel.getState();
	FreqModeConfigView::setGuiTouchable(CurrentState);
	setChannelStateUI(pChannelInput, CurrentState);
	if (CurrentState == true)
	{
		pChannelInput->setNumberChannel(m_channelInput);
	}
	else
	{
		pChannelInput->setNumberChannel(0);
	}
}

// funkcja ustawiaja thresold z backendu
void FreqModeConfigView::detectThreshold()
{
	presenter->askForDetectedThreshold();
	setThresholdUI(pChannelInput, detectedThresholdFreq);
	setValueSliderThresholdUI(detectedThresholdFreq);
	sliderThreshold.setValue(detectedThresholdFreq);
}

// funkcja ustawiajaca w UI wartosci zapisane w obiektach
void FreqModeConfigView::initUIChannel(std::shared_ptr<FreqModeParameter>& channel)
{
	readSlopeUI(channel->getSlope());
	readThresholdUI(channel->getThreshold());
}

// Funkcja pomocnicza dla toogle button
void FreqModeConfigView::setGuiTouchable(bool state)
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

// funkcja ustwiajaca stan kanalu w jego obiekcie
void FreqModeConfigView::setChannelStateUI(std::shared_ptr<FreqModeParameter>& channel, bool state)
{
	channel->setStateChannel(state);
}

void FreqModeConfigView::setStampsUI(std::shared_ptr<SessionSetup>& session, uint16_t value)
{
	session->setStampsNumber(value);
}

void FreqModeConfigView::setRepeatUI(std::shared_ptr<SessionSetup>& session, uint16_t value)
{
	session->setRepeat(value);
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

void FreqModeConfigView::setValueSliderThresholdUI(int value)
{
	Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%d", value);
	textSliderThreshold.invalidate();
}

void FreqModeConfigView::setValueSliderStampsNumberUI(int value)
{
	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", value);
	textStampsVal.invalidate();
}
//
void FreqModeConfigView::setValueSliderRepeatUI(int value)
{
	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", value);
	textRepeatVal.invalidate();
}

void FreqModeConfigView::initMesSetupUI()
{
	m_hfInput = false;
	textGateVal.setVisible(false);
	sliderGate.setTouchable(false);
	textGateVal.invalidate();
}

void FreqModeConfigView::setValueSliderGateUI(int value)
{
	Unicode::snprintf(textGateValBuffer, TEXTGATEVAL_SIZE, "%d", value);
	textGateVal.invalidate();
	m_gate = static_cast<uint16_t>(value);
}

void FreqModeConfigView::updateClockSourceUI(ClockName clk)
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

void FreqModeConfigView::updateMesSetupUI(bool state)
{
	if (state == true)
	{
		radioHfInputOn.setSelected(true);
		textGateVal.setVisible(true);
		sliderGate.setTouchable(true);
		sliderGate.setValue(m_gate);
	}
	else
	{
		radioHfInputOff.setSelected(true);
		textGateVal.setVisible(false);
		sliderGate.setTouchable(false);
	}
}

void FreqModeConfigView::updateSessionSetupUI(std::shared_ptr<SessionSetup>& session)
{
	Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%d", session->getStampsNumber());
	textStampsVal.invalidate();
	sliderStampsNumber.setValue(session->getStampsNumber());

	Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%d", session->getRepeat());
	textRepeatVal.invalidate();
	sliderRepeat.setValue(session->getRepeat());
}

void FreqModeConfigView::FinishSetupFreqModeSingle()
{
	updateFreqParameterBackend();

	presenter->askForDataFreqSingle();
	application().gotoFreqModeScreenCoverTransitionWest();
}

void FreqModeConfigView::FinishSetupFreqModeConst()
{
	updateFreqParameterBackend();

	presenter->askForDataFreqConst();
	application().gotoFreqModeScreenCoverTransitionWest();
}

void FreqModeConfigView::FinishSetupFreqModeStamps()
{
	updateFreqParameterBackend();

	presenter->askForDataFreqStamps();
	application().gotoFreqModeScreenCoverTransitionWest();
}

void FreqModeConfigView::FinishSetupFreqModeRepeat()
{
	updateFreqParameterBackend();

	presenter->askForDataFreqRepeat();
	application().gotoFreqModeScreenCoverTransitionWest();
}

void FreqModeConfigView::updateFreqParameterBackend()
{
	FreqBackend.Channel1.channelState = pChannel1->getStateChannel();
	FreqBackend.Channel1.numberChanel = pChannel1->getNumberChannel();
	FreqBackend.Channel1.slope = static_cast<Slope_t>(pChannel1->getSlope());
	FreqBackend.Channel1.threshold = pChannel1->getThreshold();

	FreqBackend.Channel2.channelState = pChannel2->getStateChannel();
	FreqBackend.Channel2.numberChanel = pChannel2->getNumberChannel();
	FreqBackend.Channel2.slope = static_cast<Slope_t>(pChannel2->getSlope());
	FreqBackend.Channel2.threshold = pChannel2->getThreshold();

	FreqBackend.Channel3.channelState = pChannel3->getStateChannel();
	FreqBackend.Channel3.numberChanel = pChannel3->getNumberChannel();
	FreqBackend.Channel3.slope = static_cast<Slope_t>(pChannel3->getSlope());
	FreqBackend.Channel3.threshold = pChannel3->getThreshold();

	FreqBackend.Channel4.channelState = pChannel4->getStateChannel();
	FreqBackend.Channel4.numberChanel = pChannel4->getNumberChannel();
	FreqBackend.Channel4.slope = static_cast<Slope_t>(pChannel4->getSlope());
	FreqBackend.Channel4.threshold = pChannel4->getThreshold();

	FreqBackend.Channel5.channelState = pChannel5->getStateChannel();
	FreqBackend.Channel5.numberChanel = pChannel5->getNumberChannel();
	FreqBackend.Channel5.slope = static_cast<Slope_t>(pChannel5->getSlope());
	FreqBackend.Channel5.threshold = pChannel5->getThreshold();

	FreqBackend.Channel6.channelState = pChannel6->getStateChannel();
	FreqBackend.Channel6.numberChanel = pChannel6->getNumberChannel();
	FreqBackend.Channel6.slope = static_cast<Slope_t>(pChannel6->getSlope());
	FreqBackend.Channel6.threshold = pChannel6->getThreshold();

	FreqBackend.Channel7.channelState = pChannel7->getStateChannel();
	FreqBackend.Channel7.numberChanel = pChannel7->getNumberChannel();
	FreqBackend.Channel7.slope = static_cast<Slope_t>(pChannel7->getSlope());
	FreqBackend.Channel7.threshold = pChannel7->getThreshold();

	FreqBackend.Channel8.channelState = pChannel8->getStateChannel();
	FreqBackend.Channel8.numberChanel = pChannel8->getNumberChannel();
	FreqBackend.Channel8.slope = static_cast<Slope_t>(pChannel8->getSlope());
	FreqBackend.Channel8.threshold = pChannel8->getThreshold();

	FreqBackend.MessSetup.hfInputState = m_hfInput;
	FreqBackend.MessSetup.gate = m_gate;

	FreqBackend.FreqSession.clock = static_cast<Clock_t>(pSession->getSourceClock());
	FreqBackend.FreqSession.repeat = pSession->getRepeat();
	FreqBackend.FreqSession.stampsNumber = pSession->getStampsNumber();
}


