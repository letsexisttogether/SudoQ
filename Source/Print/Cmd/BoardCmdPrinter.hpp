#pragma once

#include "Print/BoardPrinter.hpp"

class BoardCmdPrinter : public BoardPrinter
{
public:
    BoardCmdPrinter() = delete;
    BoardCmdPrinter(const BoardCmdPrinter&) = delete;
    BoardCmdPrinter(BoardCmdPrinter&&) = delete;

    BoardCmdPrinter(const Board& board, VisibilityGrid&& grid);

    void PrintBoard() const noexcept override;

    ~BoardCmdPrinter() = default;

    BoardCmdPrinter& operator = (const BoardCmdPrinter&) = delete;
    BoardCmdPrinter& operator = (BoardCmdPrinter&&) = delete;
};
