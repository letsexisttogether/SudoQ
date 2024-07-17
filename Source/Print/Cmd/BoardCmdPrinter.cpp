#include "BoardCmdPrinter.hpp"

#include <iostream>

BoardCmdPrinter::BoardCmdPrinter(const Board& board, VisibilityGrid&& grid)
    : BoardPrinter{ board, std::move(grid) }
{}

void BoardCmdPrinter::PrintBoard() const noexcept
{
    const Board::Grid& grid = m_Board.GetRawGrid();

    std::cout << '\n';

    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {
        for (Board::RCIndex j = 0; j < Board::GridMaxIndex; ++j)
        {
            if (m_CellsVisibility.GetCellValue(i, j))
            {
                std::cout << static_cast<std::uint16_t>(grid[i][j]) << ' ';
            }
            else 
            {
                std::cout << "  ";
            }
        }

        std::cout << '\n';
    }

    std::cout << std::endl;
}
