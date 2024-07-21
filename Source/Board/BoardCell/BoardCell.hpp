#pragma once

#include <istream>

#include "Board/Board.hpp"

class BoardCell
{
public:
    void Reset() noexcept;

    friend std::istream& operator >> (std::istream& stream, BoardCell& cell);

public:
    static const Board::CellValue MinValue;
    static const Board::CellValue MaxValue;

public:
    Board::RCIndex Column{};
    Board::CellValue Value{};
    Board::RCIndex Row{};
};
