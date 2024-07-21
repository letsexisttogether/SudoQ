#pragma once

#include <array>
#include <istream>

#include "Board/Board.hpp"

class BoardCell
{
public:
    using RangeValues = std::array<Board::CellValue, Board::GridMaxIndex>;

public:
    void Reset() noexcept;

    friend std::istream& operator >> (std::istream& stream, BoardCell& cell);

public:
    static constexpr RangeValues PossibleValues{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    static constexpr Board::CellValue MinValue{ PossibleValues.front() };
    static constexpr Board::CellValue MaxValue{ PossibleValues.back() };


public:
    Board::RCIndex Column{};
    Board::CellValue Value{};
    Board::RCIndex Row{};
};
