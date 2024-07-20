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

    void SetVisibility(Board::RCIndex row, Board::RCIndex column,
        const bool isVisible) noexcept;


protected:
    VisibilityGrid m_CellsVisibility
    { 
        { 
            Board::GridMaxIndex, Board::RowColumn(Board::GridMaxIndex, true)
        } 
    };
};
