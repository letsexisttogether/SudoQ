#pragma once

#include <unordered_map>

#include "Board/Board.hpp"

class CellValueConverter
{
public:
    using ByteValue = std::uint16_t;
    using ByteValuesContainer = std::unordered_map
        <Board::CellValue, ByteValue>;
    
public:
    CellValueConverter();
    CellValueConverter(const CellValueConverter&) = delete;
    CellValueConverter(CellValueConverter&&) = delete;

    ~CellValueConverter() = default;

    ByteValue GetByteValue(const Board::CellValue value) 
        const noexcept;

    CellValueConverter& operator = (const CellValueConverter&) = delete;
    CellValueConverter& operator = (CellValueConverter&) = delete;

private:
    const ByteValuesContainer m_ByteValues; 
};
