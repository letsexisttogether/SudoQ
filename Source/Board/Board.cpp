#include "Board.hpp"

#include <utility>

Board::Board(const Grid& grid)
    : m_Grid{ grid }
{}

Board::Board(Grid&& grid)
    : m_Grid{ std::move(grid) }
{}

Board::CellValue Board::GetCellValue(const RCIndex row, 
    const RCIndex column) const noexcept
{
    if (!IsInBoundries(row, column))
    {
        return CellValue{};
    }

    return m_Grid[row][column];
}

void Board::SetCellValue(const RCIndex row, const RCIndex column,
    const CellValue value) noexcept
{
    if (!IsInBoundries(row, column))
    {
        return;
    }

    m_Grid[row][column] = value;
}

bool Board::IsInBoundries(const RCIndex row, const RCIndex column)
    const noexcept
{
    return (row < m_Grid.size() && column < m_Grid[0].size());
}

const Board::Grid& Board::GetRawGrid() const noexcept
{
    return m_Grid;
}


const Board::RCIndex Board::GridMaxIndex = 9;
