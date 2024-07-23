#include "CmdVictoryHandler.hpp"

#include "Application/Application.hpp"
#include "Application/Scene/Game/GameScene.hpp"

#include <iostream>

CmdVictoryHandler::CmdVictoryHandler(Message&& victoryMessage)
    : VictoryHandler{ std::move(victoryMessage) }
{}

void CmdVictoryHandler::HandleVictory() noexcept
{
    GameScene* const scene = static_cast<GameScene*>
        (Application::GetApp().GetScene());

    scene->GetPrinter()->PrintBoard(scene->GetBoard()); 

    std::cout << m_VictoryMessage;

    Application::GetApp().SetShouldContinue(false);
}
