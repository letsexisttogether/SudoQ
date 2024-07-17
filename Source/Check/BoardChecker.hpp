#pragma once 

#include <cstdint>
#include <unordered_map>

#include "Board/Board.hpp"
#include "Convert/CellValueConverter.hpp"

class BoardChecker
{
public:
    using ByteValue = std::uint16_t;
    using ByteValuesContainer = std::unordered_map
        <Board::CellValue, ByteValue>;

public:
    BoardChecker() = delete;
    BoardChecker(const BoardChecker&) = delete;
    BoardChecker(BoardChecker&&) = delete;

    BoardChecker(const Board& board);

    ~BoardChecker() = default;

    bool IsComplete() const noexcept;

    BoardChecker& operator = (const BoardChecker&) = delete;
    BoardChecker& operator = (BoardChecker&&) = delete;

private:
    static const ByteValue m_ProperValue; 

private:
    const Board& m_Board;

    const CellValueConverter m_Converter{};
};
