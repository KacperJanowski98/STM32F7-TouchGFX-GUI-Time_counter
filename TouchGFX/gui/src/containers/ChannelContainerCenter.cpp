#include <gui/containers/ChannelContainerCenter.hpp>

ChannelContainerCenter::ChannelContainerCenter()
{

}

void ChannelContainerCenter::initialize()
{
    ChannelContainerCenterBase::initialize();
}

void ChannelContainerCenter::updateText(int16_t value)
{
	Unicode::snprintf(textChannelBuffer, TEXTCHANNEL_SIZE, "%d", value);
	textChannel.invalidate();
}
