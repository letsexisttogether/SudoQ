#include "RCVInputHandler.hpp"

#include <iostream>
#include <regex>
#include <sstream>

#include "Board/Board.hpp"

RCVInputHandler::RCVInputHandler(const HandlerPtr handler)
    : InputHandler{ handler }
{}

void RCVInputHandler::Handle(const HandleData& data) noexcept
{
    if (!CanHandle(data))
    {
        // Call for the next one probably
        std::cout << "Can't handle it" << std::endl;
        return; 
    }

    Board::RCIndex row{};
    Board::RCIndex column{};
    Board::CellValue value{};

    std::istringstream iss{ data };
    iss >> row >> column >> value;

    std::cout << "Row: " << row << " Column: " << column 
        << " Value: " << value << std::endl;
}

bool RCVInputHandler::CanHandle(const HandleData& data) const noexcept
{
    std::regex pattern(R"(\d+\s+\d+\s+\d+)");

    return std::regex_match(data, pattern);
}

