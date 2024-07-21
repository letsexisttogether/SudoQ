#include "RCVInputHandler.hpp"

#include <regex>
#include <sstream>

#include "Application/Application.hpp"
#include "Board/BoardCell/BoardCell.hpp"

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

    --cell.Row;
    --cell.Column;

    Application::GetApp().GetScene()->SetInputValue(cell);
}

bool RCVInputHandler::CanHandle(const HandleData& data) const noexcept
{
    // This code should also come from Parser
    std::regex pattern(R"(\d+\s+\d+\s+\d+)");

    return std::regex_match(data, pattern);
}

