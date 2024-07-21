#pragma once

#include "Board/Board.hpp"

class BoardPrinter
{
public:
    using RowColumn = std::vector<bool>;
    // CHANGE IT ASAP
    using VisibilityGrid = Board;

public:
    BoardPrinter() = default;

    BoardPrinter(VisibilityGrid&& grid);

    virtual ~BoardPrinter() = default;

    virtual void PrintBoard(const Board& board) const noexcept = 0;

    void SetCellVisibility(Board::RCIndex row, Board::RCIndex column,
        const bool isVisible) noexcept;
    bool GetCellVisibility(Board::RCIndex row, Board::RCIndex column)
        const noexcept;

    const VisibilityGrid::Grid& GetRawGrid() const noexcept;

protected:
    VisibilityGrid m_CellsVisibility
    { 
        { 
            Board::GridMaxIndex, Board::RowColumn(Board::GridMaxIndex, true)
        } 
    };
};
