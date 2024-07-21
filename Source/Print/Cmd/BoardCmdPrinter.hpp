#pragma once

#include "Print/BoardPrinter.hpp"

class BoardCmdPrinter : public BoardPrinter
{
public:
    BoardCmdPrinter() = default;
    BoardCmdPrinter(const BoardCmdPrinter&) = delete;
    BoardCmdPrinter(BoardCmdPrinter&&) = delete;

    BoardCmdPrinter(VisibilityGrid&& grid);

    BoardCmdPrinter(const bool isFrame, const char emptyCellSign,
        VisibilityGrid&& grid);

    void PrintBoard(const Board& board) const noexcept override;

    ~BoardCmdPrinter() = default;

    BoardCmdPrinter& operator = (const BoardCmdPrinter&) = delete;
    BoardCmdPrinter& operator = (BoardCmdPrinter&&) = delete;

private:
    const bool m_IsFrame{ false };
    const char m_EmptyCellSign{ ' ' };
};
