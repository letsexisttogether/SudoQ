#pragma once

#include "Board/Board.hpp"

class BoardCmdPrinter
{
public:
    BoardCmdPrinter() = delete;
    BoardCmdPrinter(const BoardCmdPrinter&) = delete;
    BoardCmdPrinter(BoardCmdPrinter&&) = delete;

    BoardCmdPrinter(const Board& board);

    void Print() const noexcept;

    ~BoardCmdPrinter() = default;

    BoardCmdPrinter& operator = (const BoardCmdPrinter&) = delete;
    BoardCmdPrinter& operator = (BoardCmdPrinter&&) = delete;

private:
    const Board& m_Board;
};
