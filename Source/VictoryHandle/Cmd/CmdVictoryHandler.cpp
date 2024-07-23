#include "CmdVictoryHandler.hpp"

#include "Application/Application.hpp"

#include <iostream>

CmdVictoryHandler::CmdVictoryHandler(Message&& victoryMessage)
    : VictoryHandler{ std::move(victoryMessage) }
{}

void CmdVictoryHandler::HandleVictory() noexcept
{
    Scene* const scene = Application::GetApp().GetScene();

    scene->GetPrinter()->PrintBoard(scene->GetBoard()); 

    std::cout << m_VictoryMessage;

    Application::GetApp().SetShouldContinue(false);
}
