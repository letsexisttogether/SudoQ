#include "CellValueConverter.hpp"

CellValueConverter::ByteValue CellValueConverter::GetByteValue
    (const Board::CellValue value) const noexcept
{
    return (0b1 << value);
}
