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
