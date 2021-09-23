/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CHANNELCONTAINERBASE_HPP
#define CHANNELCONTAINERBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class ChannelContainerBase : public touchgfx::Container
{
public:
    ChannelContainerBase();
    virtual ~ChannelContainerBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TextAreaWithOneWildcard textChannel;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTCHANNEL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textChannelBuffer[TEXTCHANNEL_SIZE];

private:

};

#endif // CHANNELCONTAINERBASE_HPP
