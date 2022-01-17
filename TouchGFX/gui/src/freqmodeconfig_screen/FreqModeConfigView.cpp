#include <gui/freqmodeconfig_screen/FreqModeConfigView.hpp>

FreqModeConfigView::FreqModeConfigView()
	: scrollWheelINPUTAnimateToCallback(this, &FreqModeConfigView::scrollWheelINPUTAnimateToHandler)
	, sliderValueStartedChangeCallback(this, &FreqModeConfigView::sliderValueStartedChangeCallbackHandler)
	, sliderValueChangedCallback(this, &FreqModeConfigView::sliderValueChangedCallbackHandler)
	, sliderValueConfirmedCallback(this, &FreqModeConfigView::sliderValueConfirmedCallbackHandler)
	, RadioBtnGroupFreqCallback(this, &FreqModeConfigView::RadioBtnGroupFreqCallbackHandler)
	, RadioBtnGroupHfInputCallback(this, &FreqModeConfigView::RadioBtnGroupHfInputCallbackHandler)
	, RadioBtnGroupClockCallback(this, &FreqModeConfigView::RadioBtnGroupClockCallbackHandler)
	, Channel1(DataExchange.FrequencyData.Channel1.numberChanel, DataExchange.FrequencyData.Channel1.channelState,
			static_cast<SlopeName>(DataExchange.FrequencyData.Channel1.slope), DataExchange.FrequencyData.Channel1.threshold)
	, Channel2(DataExchange.FrequencyData.Channel2.numberChanel, DataExchange.FrequencyData.Channel2.channelState,
			static_cast<SlopeName>(DataExchange.FrequencyData.Channel2.slope), DataExchange.FrequencyData.Channel2.threshold)
	, Channel3(DataExchange.FrequencyData.Channel3.numberChanel, DataExchange.FrequencyData.Channel3.channelState,
			static_cast<SlopeName>(DataExchange.FrequencyData.Channel3.slope), DataExchange.FrequencyData.Channel3.threshold)
	, Channel4(DataExchange.FrequencyData.Channel4.numberChanel, DataExchange.FrequencyData.Channel4.channelState,
			static_cast<SlopeName>(DataExchange.FrequencyData.Channel4.slope), DataExchange.FrequencyData.Channel4.threshold)
	, Channel5(DataExchange.FrequencyData.Channel5.numberChanel, DataExchange.FrequencyData.Channel5.channelState,
			static_cast<SlopeName>(DataExchange.FrequencyData.Channel5.slope), DataExchange.FrequencyData.Channel5.threshold)
	, Channel6(DataExchange.FrequencyData.Channel6.numberChanel, DataExchange.FrequencyData.Channel6.channelState,
			static_cast<SlopeName>(DataExchange.FrequencyData.Channel6.slope), DataExchange.FrequencyData.Channel6.threshold)
	, Channel7(DataExchange.FrequencyData.Channel7.numberChanel, DataExchange.FrequencyData.Channel7.channelState,
			static_cast<SlopeName>(DataExchange.FrequencyData.Channel7.slope), DataExchange.FrequencyData.Channel7.threshold)
	, Channel8(DataExchange.FrequencyData.Channel8.numberChanel, DataExchange.FrequencyData.Channel8.channelState,
			static_cast<SlopeName>(DataExchange.FrequencyData.Channel8.slope), DataExchange.FrequencyData.Channel8.threshold)
    , Session(false, static_cast<ClockName>(DataExchange.FrequencyData.FreqSession.clock), 0, DataExchange.FrequencyData.FreqSession.stampsNumber, DataExchange.FrequencyData.FreqSession.repeat)
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
	scrollWheelINPUT.animateToItem(0);

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

	FreqModeConfigView::m_hfInput = DataExchange.FrequencyData.MessSetup.hfInputState;
	FreqModeConfigView::m_gate = DataExchange.FrequencyData.MessSetup.gate;

	updateMesSetupUI(DataExchange.FrequencyData.MessSetup.hfInputState);

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
		btnAddGate.setTouchable(false);
		btnOddGate.setTouchable(false);
	}
	else if (&src == &radioHfInputOn)
	{
		m_hfInput = true;
		textGateVal.setVisible(true);
		sliderGate.setTouchable(true);
		btnAddGate.setTouchable(true);
		btnOddGate.setTouchable(true);
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
		imageLockInput.setVisible(false);
		boxLockInput.setVisible(false);
	}
	else
	{
		pChannelInput->setNumberChannel(0);
		imageLockInput.setVisible(true);
		boxLockInput.setVisible(true);
	}
	imageLockInput.invalidate();
	boxLockInput.invalidate();
}

// funkcja ustawiaja thresold z backendu
void FreqModeConfigView::detectThreshold()
{
	presenter->askForDetectedThreshold();
	setThresholdUI(pChannelInput, DataExchange.detectedThreshold);
	setValueSliderThresholdUI(DataExchange.detectedThreshold);
	sliderThreshold.setValue(DataExchange.detectedThreshold);
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
		btnAddThreshold.setTouchable(false);
		btnOddThreshold.setTouchable(false);
		imageLockInput.setVisible(true);
		boxLockInput.setVisible(true);
	}
	else
	{
		radioSlopeUp.setTouchable(true);
		radioSlopeDown.setTouchable(true);
		sliderThreshold.setTouchable(true);
		buttonDetect.setTouchable(true);
		btnAddThreshold.setTouchable(true);
		btnOddThreshold.setTouchable(true);
		imageLockInput.setVisible(false);
		boxLockInput.setVisible(false);
	}
	imageLockInput.invalidate();
	boxLockInput.invalidate();
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

void FreqModeConfigView::AddThreshold()
{
	m_newThreshold = pChannelInput->getThreshold() + 1;
	if (m_newThreshold <= 285)
	{
		setThresholdUI(pChannelInput, m_newThreshold);
		setValueSliderThresholdUI(m_newThreshold);
		sliderThreshold.setValue(m_newThreshold);
	}
}

void FreqModeConfigView::OddThreshold()
{
	m_newThreshold = pChannelInput->getThreshold() - 1;
	if (m_newThreshold >= 0)
	{
		setThresholdUI(pChannelInput, m_newThreshold);
		setValueSliderThresholdUI(m_newThreshold);
		sliderThreshold.setValue(m_newThreshold);
	}
}

void FreqModeConfigView::AddRepeat()
{
	m_newRepeat = pSession->getRepeat() + 1;
	if (m_newRepeat <= 125)
	{
    	setRepeatUI(pSession, m_newRepeat);
    	setValueSliderRepeatUI(m_newRepeat);
    	sliderRepeat.setValue(m_newRepeat);
	}
}

void FreqModeConfigView::OddRepeat()
{
	m_newRepeat = pSession->getRepeat() - 1;
	if (m_newRepeat >= 0)
	{
    	setRepeatUI(pSession, m_newRepeat);
    	setValueSliderRepeatUI(m_newRepeat);
    	sliderRepeat.setValue(m_newRepeat);
	}
}

void FreqModeConfigView::AddStamps()
{
	m_newStamps = pSession->getStampsNumber() + 1;
	if (m_newStamps <= 284)
	{
    	setStampsUI(pSession, m_newStamps);
    	setValueSliderStampsNumberUI(m_newStamps);
    	sliderStampsNumber.setValue(m_newStamps);
	}
}

void FreqModeConfigView::OddStamps()
{
	m_newStamps = pSession->getStampsNumber() - 1;
	if (m_newStamps >= 0)
	{
    	setStampsUI(pSession, m_newStamps);
    	setValueSliderStampsNumberUI(m_newStamps);
    	sliderStampsNumber.setValue(m_newStamps);
	}
}

void FreqModeConfigView::AddGate()
{
	m_newGate = m_gate + 1;
	if (m_newGate <= 254)
	{
		setValueSliderGateUI(m_newGate);
		sliderGate.setValue(m_newGate);
	}
}

void FreqModeConfigView::OddGate()
{
	m_newGate = m_gate - 1;
	if (m_newGate >= 0)
	{
		setValueSliderGateUI(m_newGate);
		sliderGate.setValue(m_newGate);
	}
}

void FreqModeConfigView::FinishSetupFreqModeSingle()
{
	updateFreqParameterBackend();

	presenter->askForDataFreqSingle();
	application().gotoFreqModeScreenWipeTransitionEast();
}

void FreqModeConfigView::FinishSetupFreqModeConst()
{
	updateFreqParameterBackend();

	presenter->askForDataFreqConst();
	application().gotoFreqModeScreenWipeTransitionEast();
}

void FreqModeConfigView::FinishSetupFreqModeStamps()
{
	updateFreqParameterBackend();

	presenter->askForDataFreqStamps();
	application().gotoFreqModeScreenWipeTransitionEast();
}

void FreqModeConfigView::FinishSetupFreqModeRepeat()
{
	updateFreqParameterBackend();

	presenter->askForDataFreqRepeat();
	application().gotoFreqModeScreenWipeTransitionEast();
}

void FreqModeConfigView::updateFreqParameterBackend()
{
	updateChannelBackendStruct(&DataExchange.FrequencyData.Channel1, pChannel1);

	updateChannelBackendStruct(&DataExchange.FrequencyData.Channel2, pChannel2);

	updateChannelBackendStruct(&DataExchange.FrequencyData.Channel3, pChannel3);

	updateChannelBackendStruct(&DataExchange.FrequencyData.Channel4, pChannel4);

	updateChannelBackendStruct(&DataExchange.FrequencyData.Channel5, pChannel5);

	updateChannelBackendStruct(&DataExchange.FrequencyData.Channel6, pChannel6);

	updateChannelBackendStruct(&DataExchange.FrequencyData.Channel7, pChannel7);

	updateChannelBackendStruct(&DataExchange.FrequencyData.Channel8, pChannel8);

	DataExchange.FrequencyData.MessSetup.hfInputState = m_hfInput;
	DataExchange.FrequencyData.MessSetup.gate = m_gate;

	updateSessionBackendStruct(&DataExchange.FrequencyData.FreqSession, pSession);
}

void FreqModeConfigView::updateChannelBackendStruct(FreqChannel_t *pChannelBack, std::shared_ptr<FreqModeParameter> pChannel)
{
	pChannelBack->channelState = pChannel->getStateChannel();
	pChannelBack->numberChanel = pChannel->getNumberChannel();
	pChannelBack->slope = static_cast<Slope_t>(pChannel->getSlope());
	pChannelBack->threshold = pChannel->getThreshold();
}

void FreqModeConfigView::updateSessionBackendStruct(SessionSetup_t *pSessionBack, std::shared_ptr<SessionSetup> pSession)
{
	pSessionBack->clock = static_cast<Clock_t>(pSession->getSourceClock());
	pSessionBack->repeat = pSession->getRepeat();
	pSessionBack->stampsNumber = pSession->getStampsNumber();
}
