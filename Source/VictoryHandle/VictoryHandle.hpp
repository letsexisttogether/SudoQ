#pragma once

#include <string>

// I'll leave it in this state. 
// TODO: clean first order 
class VictoryHandle
{
public:
    using Message = std::string;

public:
    VictoryHandle() = default;

    VictoryHandle(Message&& victoryMessage);

    virtual ~VictoryHandle() = default;

    virtual void HandleVictory() noexcept = 0;

protected:
    Message m_VictoryMessage{};    
};
