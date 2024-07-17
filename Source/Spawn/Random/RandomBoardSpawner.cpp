#include "RandomBoardSpawner.hpp"
#include "Convert/CellValueConverter.hpp"

Board RandomBoardSpawner::SpawnBoard() const noexcept
{
    Board board{};

    RCByteContainer rowValues(Board::GridMaxIndex, ByteValue{});
    RCByteContainer columnValues(Board::GridMaxIndex, ByteValue{});
    RCByteMatrix tripleValues{ Board::TripleMaxIndex,
        RCByteContainer(Board::TripleMaxIndex, ByteValue{}) };

    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {
        for (Board::RCIndex j = 0; j < Board::GridMaxIndex; ++j)
        {
            Board::CellValue rowValue = SpawnValue(rowValues[i], 
                columnValues[j], tripleValues[i / 3][j / 3]);
            board.SetCellValue(i, j, rowValue);
        }
    }

    return board; 
}

Board::CellValue RandomBoardSpawner::SpawnValue(ByteValue& rowValue,
    ByteValue& columnValue, ByteValue& tripleValue) const noexcept
{
    for (Board::CellValue value = 1; value <= 9; ++value)
    {
         ByteValue cellByteValue = m_Converter.GetByteValue(value);

        if (!(cellByteValue & rowValue) && !(cellByteValue & columnValue)
            && !(cellByteValue & tripleValue))
        {
            rowValue |= cellByteValue;
            columnValue |= cellByteValue;
            tripleValue |= cellByteValue;

            return value; 
        }
    }

    return {};
}
