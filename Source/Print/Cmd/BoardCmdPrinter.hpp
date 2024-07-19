#pragma once

#include "Print/BoardPrinter.hpp"

class BoardCmdPrinter : public BoardPrinter
{
public:
    BoardCmdPrinter() = delete;
    BoardCmdPrinter(const BoardCmdPrinter&) = delete;
    BoardCmdPrinter(BoardCmdPrinter&&) = delete;

    BoardCmdPrinter(VisibilityGrid&& grid);

    void PrintBoard(const Board& board) const noexcept override;

    ~BoardCmdPrinter() = default;

    BoardCmdPrinter& operator = (const BoardCmdPrinter&) = delete;
    BoardCmdPrinter& operator = (BoardCmdPrinter&&) = delete;
};
