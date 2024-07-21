#include "BoardPrinter.hpp"

BoardPrinter::BoardPrinter(VisibilityGrid&& grid)
    : m_CellsVisibility{ std::move(grid) }
{}

void BoardPrinter::SetCellVisibility(Board::RCIndex row,
    Board::RCIndex column, const bool isVisible) noexcept
{
    m_CellsVisibility.SetCellValue(row, column, isVisible);
}

bool BoardPrinter::GetCellVisibility(Board::RCIndex row,
    Board::RCIndex column) const noexcept
{
    return m_CellsVisibility.GetCellValue(row, column);
}

const BoardPrinter::VisibilityGrid::Grid& BoardPrinter::GetRawGrid()
    const noexcept
{
   return m_CellsVisibility.GetRawGrid();
}
