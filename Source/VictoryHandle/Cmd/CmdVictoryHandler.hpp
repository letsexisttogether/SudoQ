#pragma once

#include "VictoryHandle/VictoryHandler.hpp"

class CmdVictoryHandler : public VictoryHandler
{
public:
    CmdVictoryHandler() = delete;
    CmdVictoryHandler(const CmdVictoryHandler&) = default;
    CmdVictoryHandler(CmdVictoryHandler&&) = default;

    CmdVictoryHandler(Message&& victoryMessage);

    ~CmdVictoryHandler() = default;

    void HandleVictory() noexcept override;

    CmdVictoryHandler& operator = (const CmdVictoryHandler&) = default;
    CmdVictoryHandler& operator = (CmdVictoryHandler&&) = default;
};
