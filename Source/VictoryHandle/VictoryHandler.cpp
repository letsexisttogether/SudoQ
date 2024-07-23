#include "VictoryHandler.hpp"

#include <utility>

VictoryHandler::VictoryHandler(Message&& victoryMessage)
    : m_VictoryMessage{ std::move(victoryMessage) }
{}

