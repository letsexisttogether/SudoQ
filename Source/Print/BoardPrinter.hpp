#pragma once

#include "Board/Board.hpp"

class BoardPrinter
{
public:
    using RowColumn = std::vector<bool>;
    // CHANGE IT ASAP
    using VisibilityGrid = Board;

public:
    BoardPrinter() = delete;
    BoardPrinter(const BoardPrinter&) = delete;
    BoardPrinter(BoardPrinter&&) = delete;

    BoardPrinter(VisibilityGrid&& grid);

    virtual ~BoardPrinter() = default;

    virtual void PrintBoard(const Board& board) const noexcept = 0;

    BoardPrinter& operator = (const BoardPrinter&) = delete;
    BoardPrinter& operator = (BoardPrinter&&) = delete;

protected:
    VisibilityGrid m_CellsVisibility;
};
