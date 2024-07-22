#include "VictoryHandle.hpp"

#include <utility>

VictoryHandle::VictoryHandle(Message&& victoryMessage)
    : m_VictoryMessage{ std::move(victoryMessage) }
{}

