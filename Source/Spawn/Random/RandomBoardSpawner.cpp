#include "RandomBoardSpawner.hpp"
#include "Convert/CellValueConverter.hpp"

#include <vector>

Board RandomBoardSpawner::SpawnBoard() const noexcept
{
    Board board{};

    RCByteContainer rowValues(Board::GridMaxIndex, 
            CellValueConverter::ByteValue{});
    RCByteContainer columnValues(Board::GridMaxIndex, 
            CellValueConverter::ByteValue{});
    RCByteContainer sectionValues(Board::GridMaxIndex, 
            CellValueConverter::ByteValue{});

    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {
        for (Board::RCIndex j = i; j < Board::GridMaxIndex; ++j)
        {
            if (i != j)
            {
                Board::CellValue rowValue = SpawnValue(rowValues[i], 
                    columnValues[j], sectionValues[i]);
                board.SetCellValue(i, j, rowValue);

            }

            Board::CellValue columnValue = SpawnValue(rowValues[j], 
                columnValues[i], sectionValues[j % 3]);
            board.SetCellValue(j, i, columnValue);
        }
    }

    return board; 
}

Board::CellValue RandomBoardSpawner::SpawnValue(ByteValue& rowValue,
    ByteValue& columnValue, ByteValue& sectionValue) const noexcept
{
    for (Board::CellValue value = 1; value <= 9; ++value)
    {
         ByteValue cellByteValue = m_Converter.GetByteValue(value);

        if (!(cellByteValue & rowValue) && !(cellByteValue & columnValue)
            && !(cellByteValue & sectionValue))
        {
            rowValue |= cellByteValue;
            columnValue |= cellByteValue;
            sectionValue |= cellByteValue;

            return value; 
        }
    }

    return {};
}
