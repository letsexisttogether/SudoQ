#pragma once

#include "VictoryHandle/VictoryHandle.hpp"

class CmdVictoryHandle : public VictoryHandle
{
public:
    CmdVictoryHandle() = delete;
    CmdVictoryHandle(const CmdVictoryHandle&) = default;
    CmdVictoryHandle(CmdVictoryHandle&&) = default;

    CmdVictoryHandle(Message&& victoryMessage);

    ~CmdVictoryHandle() = default;

    void HandleVictory() noexcept override;

    CmdVictoryHandle& operator = (const CmdVictoryHandle&) = default;
    CmdVictoryHandle& operator = (CmdVictoryHandle&&) = default;
};
