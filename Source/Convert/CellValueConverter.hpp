#pragma once

#include "Board/Board.hpp"

class CellValueConverter
{
public:
    using ByteValue = std::uint16_t;
    
public:
    CellValueConverter() = default;
    CellValueConverter(const CellValueConverter&) = delete;
    CellValueConverter(CellValueConverter&&) = delete;

    ~CellValueConverter() = default;

    ByteValue GetByteValue(const Board::CellValue value) 
        const noexcept;

    CellValueConverter& operator = (const CellValueConverter&) = delete;
    CellValueConverter& operator = (CellValueConverter&) = delete;
};
