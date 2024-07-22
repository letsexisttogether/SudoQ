#include "CmdVictoryHandle.hpp"

#include "Application/Application.hpp"

#include <iostream>

CmdVictoryHandle::CmdVictoryHandle(Message&& victoryMessage)
    : VictoryHandle{ std::move(victoryMessage) }
{}

void CmdVictoryHandle::HandleVictory() noexcept
{
    Scene* const scene = Application::GetApp().GetScene();

    scene->GetPrinter()->PrintBoard(scene->GetBoard()); 

    std::cout << m_VictoryMessage;

    Application::GetApp().SetShouldContinue(false);
}
