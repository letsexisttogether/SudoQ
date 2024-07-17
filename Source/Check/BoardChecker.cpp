#include "BoardChecker.hpp"

BoardChecker::BoardChecker(const Board& board)
    : m_Board{ board }
{}

bool BoardChecker::IsComplete() const noexcept
{
    const Board::Grid& grid = m_Board.GetRawGrid();

    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {
        ByteValue rowValue = 0b0;
        ByteValue columnValue = 0b0;

        for (Board::RCIndex j = 0; j < Board::GridMaxIndex; ++j)
        {
            const Board::CellValue rowElement = grid[i][j];
            const Board::CellValue columnElement = grid[j][i];

            rowValue |= m_Converter.GetByteValue(rowElement);
            columnValue |= m_Converter.GetByteValue(rowElement);
        }

        if ((rowValue != m_ProperValue) || (columnValue != m_ProperValue))
        {
            return false;
        }
    }

    return true;
}

const BoardChecker::ByteValue BoardChecker::m_ProperValue = 0b111111111;
