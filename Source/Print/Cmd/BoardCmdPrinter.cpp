#include "BoardCmdPrinter.hpp"

#include <iostream>

BoardCmdPrinter::BoardCmdPrinter(VisibilityGrid&& grid)
    : BoardPrinter{ std::move(grid) }
{}

void BoardCmdPrinter::PrintBoard(const Board& board) const noexcept
{
    system("cls");

    const Board::Grid& grid = board.GetRawGrid();

    std::cout << "The board:\n";

    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {
        if (!(i % 3))
        {
            std::cout << "+-------+-------+-------+\n";
        }

        for (Board::RCIndex j = 0; j < Board::GridMaxIndex; ++j)
        {

            if (!(j % 3))
            {
                std::cout << "| ";
            }

            if (m_CellsVisibility.GetCellValue(i, j))
            {
                std::cout << grid[i][j] << ' ';
            }
            else 
            {
                std::cout << "  ";
            }
        }

        std::cout << "|\n";
    }

    std::cout << "+-------+-------+-------+" << std::endl;
}
