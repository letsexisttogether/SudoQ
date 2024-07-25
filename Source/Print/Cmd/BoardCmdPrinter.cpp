#include "BoardCmdPrinter.hpp"

#include <iostream>

BoardCmdPrinter::BoardCmdPrinter(VisibilityGrid&& grid)
    : BoardPrinter{ std::move(grid) }
{}

BoardCmdPrinter::BoardCmdPrinter(const bool isFrame, 
    const char emptyCellSign, VisibilityGrid&& grid)
    : m_IsFrame{ isFrame }, m_EmptyCellSign{ emptyCellSign },
    BoardPrinter{ std::move(grid) }
{}

void BoardCmdPrinter::PrintBoard(const Board& board) const noexcept
{
    system("cls");

    const Board::Grid& grid = board.GetRawGrid();

    std::cout << "The board:\n  ";

    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {
        if (m_IsFrame && !(i % 3))
        {
            std::cout << "  ";
        }

        std::cout << i + 1 << ' ';
    }

    std::cout << '\n';

    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {

        if (m_IsFrame && !(i % 3))
        {
            std::cout << "  +-------+-------+-------+\n" << i + 1 << ' ';
        }
        else 
        {
            std::cout << i + 1 << ' ';
        }

        for (Board::RCIndex j = 0; j < Board::GridMaxIndex; ++j)
        {
            if (m_IsFrame && !(j % 3))
            {
                std::cout << "| ";
            }

            if (m_CellsVisibility.GetCellValue(i, j))
            {
                std::cout << grid[i][j] << ' ';
            }
            else 
            {
                std::cout << m_EmptyCellSign << ' '; 
            }
        }

        std::cout << ((m_IsFrame) ? ('|') : (' ')) << '\n';
    }

    if (m_IsFrame)
    {
        std::cout << "  +-------+-------+-------+" << std::endl;
    }
}
