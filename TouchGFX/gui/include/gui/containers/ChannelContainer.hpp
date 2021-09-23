#ifndef CHANNELCONTAINER_HPP
#define CHANNELCONTAINER_HPP

#include <gui_generated/containers/ChannelContainerBase.hpp>

class ChannelContainer : public ChannelContainerBase
{
public:
    ChannelContainer();
    virtual ~ChannelContainer() {}

    virtual void initialize();

    void updateText(int16_t value);
protected:
};

#endif // CHANNELCONTAINER_HPP
