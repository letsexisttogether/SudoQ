#include "BoardCmdPrinter.hpp"
#include <iostream>

BoardCmdPrinter::BoardCmdPrinter(const Board& board)
    : m_Board{ board }
{}

void BoardCmdPrinter::Print() const noexcept
{
    const Board::Grid& grid = m_Board.GetRawGrid();

    std::cout << '\n';

    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {
        for (Board::RCIndex j = 0; j < Board::GridMaxIndex; ++j)
        {
            std::cout << static_cast<std::uint16_t>(grid[i][j]) << ' ';
        }

        std::cout << '\n';
    }

    std::cout << std::endl;
}
