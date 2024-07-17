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
            columnValue |= m_Converter.GetByteValue(columnElement);
        }

        if ((rowValue != m_ProperValue) || (columnValue != m_ProperValue))
        {
            return false;
        }
    }

    // It starts with the sub-grid at the top-left corner [0...2][0...2],
    // then moves horizontally to the sub-grid at [0...2][3...5], 
    // and then to [0...2][6...8]. After completing the first row of sub-grids,
    // it moves to the next row, starting with the sub-grid at [3...5][0...2],
    // then [3...5][3...5], and so on

    for (Board::RCIndex tripleRowStart = 0;
        tripleRowStart < Board::GridMaxIndex;
        tripleRowStart += Board::TripleMaxIndex)
    {
        for (Board::RCIndex tripleColumnStart = 0;
            tripleColumnStart < Board::GridMaxIndex;
            tripleColumnStart += Board::TripleMaxIndex)
        {
            ByteValue tripleValue = 0b0;

            for (Board::RCIndex i = tripleRowStart;
                i < tripleRowStart + Board::TripleMaxIndex; ++i)
            {
                for (Board::RCIndex j = tripleColumnStart;
                    j < tripleColumnStart + Board::TripleMaxIndex; ++j)
                {
                    tripleValue |= m_Converter.GetByteValue(grid[i][j]);
                }
            }

            if (tripleValue != m_ProperValue)
            {
                return false;
            }
        }
    }

    return true;
}
