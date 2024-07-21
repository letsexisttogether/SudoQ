#include "BoardCell.hpp"

void BoardCell::Reset() noexcept
{
    *this = BoardCell{};
}

std::istream& operator>>(std::istream& stream, BoardCell& cell)
{
    stream >> cell.Row >> cell.Column >> cell.Value;

    return stream;
}

const Board::CellValue BoardCell::MinValue{ 1 };
const Board::CellValue BoardCell::MaxValue{ 9 };
