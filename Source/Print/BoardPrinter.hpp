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

    BoardPrinter(const Board& board, VisibilityGrid&& grid);

    virtual ~BoardPrinter() = default;

    virtual void PrintBoard() const noexcept = 0;

    BoardPrinter& operator = (const BoardPrinter&) = delete;
    BoardPrinter& operator = (BoardPrinter&&) = delete;

protected:
    const Board& m_Board;
    VisibilityGrid m_CellsVisibility;
};
