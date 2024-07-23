#include "RCVInputHandler.hpp"

#include <regex>
#include <sstream>

#include "Application/Application.hpp"
#include "Application/Scene/Game/GameScene.hpp"
#include "Logic/Board/BoardCell/BoardCell.hpp"

RCVInputHandler::RCVInputHandler(const HandlerPtr handler)
    : InputHandler{ handler }
{}

void RCVInputHandler::Handle(const HandleData& data) noexcept
{
    if (!CanHandle(data))
    {
        CallNextHandler(data);

        return;
    }

    // There should be Parser with this code
    BoardCell cell{};

    std::istringstream iss{ data };
    iss >> cell;

    if (cell.Value < BoardCell::MinValue
        || cell.Value > BoardCell::MaxValue)
    {
        return;
    }

    --cell.Row;
    --cell.Column;

    GameScene* const scene = static_cast<GameScene*>
        (Application::GetApp().GetScene());

    scene->SetInputValue(cell);
}

bool RCVInputHandler::CanHandle(const HandleData& data) const noexcept
{
    // This code should also come from Parser
    std::regex pattern(R"(\d+\s+\d+\s+\d+)");

    return std::regex_match(data, pattern);
}

