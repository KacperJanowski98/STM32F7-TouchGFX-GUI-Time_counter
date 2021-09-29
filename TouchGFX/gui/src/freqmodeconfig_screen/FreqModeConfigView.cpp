#include <gui/freqmodeconfig_screen/FreqModeConfigView.hpp>

FreqModeConfigView::FreqModeConfigView()
	: scrollWheelINPUTAnimateToCallback(this, &FreqModeConfigView::scrollWheelINPUTAnimateToHandler)
	, Channel1(1, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel2(2, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel3(3, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel4(4, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel5(5, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel6(6, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel7(7, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
	, Channel8(8, false, SlopeName::UP, ThresholdName::Manula, 0, false, 0)
{
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
}

// obsluga przycisku toogle button
void FreqModeConfigView::toggleChannelState()
{

}







