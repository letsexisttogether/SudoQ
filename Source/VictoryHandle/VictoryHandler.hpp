#pragma once

#include <string>

// I'll leave it in this state. 
// TODO: clean first order 
// Clean what?
class VictoryHandler
{
public:
    using Message = std::string;

public:
    VictoryHandler() = default;

    VictoryHandler(Message&& victoryMessage);

    virtual ~VictoryHandler() = default;

    virtual void HandleVictory() noexcept = 0;

protected:
    Message m_VictoryMessage{};    
};
