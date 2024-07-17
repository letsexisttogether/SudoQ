#include "CellValueConverter.hpp"

CellValueConverter::CellValueConverter()
    : m_ByteValues
    {
        { 1, 0b00000001 },
        { 2, 0b00000010 },
        { 3, 0b00000100 },
        { 4, 0b00001000 },
        { 5, 0b00010000 },
        { 6, 0b00100000 },
        { 7, 0b01000000 },
        { 8, 0b10000000 },
        { 9, 0b100000000 }
    }
{}


CellValueConverter::ByteValue CellValueConverter::GetByteValue
    (const Board::CellValue value) const noexcept
{
    auto iter = m_ByteValues.find(value);

    if (iter == m_ByteValues.end())
    {
        return {};
    }

    return iter->second;
}

