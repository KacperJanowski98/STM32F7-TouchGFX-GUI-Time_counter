#ifndef CHANNELCONTAINERCENTER_HPP
#define CHANNELCONTAINERCENTER_HPP

#include <gui_generated/containers/ChannelContainerCenterBase.hpp>

class ChannelContainerCenter : public ChannelContainerCenterBase
{
public:
    ChannelContainerCenter();
    virtual ~ChannelContainerCenter() {}

    virtual void initialize();

    void updateText(int16_t value);
protected:
};

#endif // CHANNELCONTAINERCENTER_HPP
