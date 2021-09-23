#include <gui/containers/ChannelContainer.hpp>

ChannelContainer::ChannelContainer()
{

}

void ChannelContainer::initialize()
{
    ChannelContainerBase::initialize();
}

void ChannelContainer::updateText(int16_t value)
{
	Unicode::snprintf(textChannelBuffer, TEXTCHANNEL_SIZE, "%d", value);
	textChannel.invalidate();
}
