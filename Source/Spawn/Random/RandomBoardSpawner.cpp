#include "RandomBoardSpawner.hpp"
#include "Board/BoardCell/BoardCell.hpp"

Board RandomBoardSpawner::SpawnBoard() const noexcept
{
    Board board{};

    RCByteContainer rowValues(Board::GridMaxIndex, ByteValue{});
    RCByteContainer columnValues(Board::GridMaxIndex, ByteValue{});
    RCByteMatrix tripleValues{ Board::TripleMaxIndex,
        RCByteContainer(Board::TripleMaxIndex, ByteValue{}) };

    FillBoard(board, rowValues, columnValues, tripleValues);

    return board; 
}

bool RandomBoardSpawner::FillBoard(Board& board, RCByteContainer& rowValues,
    RCByteContainer& columnValues, RCByteMatrix& tripleValues,
    const Board::RCIndex i, const Board::RCIndex j) const noexcept
{
    if (i == Board::GridMaxIndex)
    {
        return true;
    }
    if (j == Board::GridMaxIndex)
    {
        return FillBoard(board, rowValues, columnValues, 
            tripleValues, i + 1, 0);
    }

    for (Board::CellValue value = BoardCell::MinValue; 
        value <= BoardCell::MaxValue; ++value)
    {
        ByteValue byteValue = m_Converter.GetByteValue(value);

        ByteValue& rowValue = rowValues[i];
        ByteValue& columnValue = columnValues[j];
        ByteValue& tripleValue = tripleValues[i / Board::TripleMaxIndex]
            [j / Board::TripleMaxIndex];


        if ((byteValue & rowValue) || (byteValue & columnValue)
            || (byteValue & tripleValue))
        {
            continue;
        }

        board.SetCellValue(i, j, value);
        SetValue(byteValue, rowValue, columnValue, tripleValue);

        if (FillBoard(board, rowValues, columnValues, tripleValues, i, j + 1))
        {
            return true;
        }

        board.SetCellValue(i, j, Board::CellValue{});
        UnsetValue(byteValue, rowValue, columnValue, tripleValue);

    }

    return false;
}
    
void RandomBoardSpawner::SetValue(const ByteValue byteValue, 
    ByteValue& rowValue, ByteValue& columnValue, 
    ByteValue& tripleValue) const noexcept
{
    rowValue |= byteValue;
    columnValue |= byteValue;
    tripleValue |= byteValue; 
}

void RandomBoardSpawner::UnsetValue(const ByteValue byteValue, 
    ByteValue& rowValue, ByteValue& columnValue, 
    ByteValue& tripleValue) const noexcept 
{
    rowValue &= ~byteValue;
    columnValue &= ~byteValue;
    tripleValue &= ~byteValue; 
}

