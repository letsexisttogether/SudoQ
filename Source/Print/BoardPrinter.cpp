#include "BoardPrinter.hpp"

BoardPrinter::BoardPrinter(VisibilityGrid&& grid)
    : m_CellsVisibility{ std::move(grid) }
{}

void BoardPrinter::SetVisibility(Board::RCIndex row,
    Board::RCIndex column, const bool isVisible) noexcept
{
    m_CellsVisibility.SetCellValue(row, column, isVisible);
}

