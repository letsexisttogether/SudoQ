#include "RCVInputHandler.hpp"

#include <iostream>
#include <regex>
#include <sstream>

#include "Application/Application.hpp"
#include "Board/Board.hpp"

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
    Board::RCIndex row{};
    Board::RCIndex column{};
    Board::CellValue value{};

    std::istringstream iss{ data };
    iss >> row >> column >> value;

    Scene* const scene = Application::GetApp().GetScene();
    BoardPrinter* printer = scene->GetPrinter();

    if (scene->GetBoard().GetCellValue(--row, --column) == value)
    {
        std::cout << "You guessed right" << std::endl;
        printer->SetVisibility(row, column, true);
    }
}

bool RCVInputHandler::CanHandle(const HandleData& data) const noexcept
{
    // This code should also come from Parser
    std::regex pattern(R"(\d+\s+\d+\s+\d+)");

    return std::regex_match(data, pattern);
}

