#pragma once

#include "Logic/Board/BoardCell/BoardCell.hpp"
#include "Utility/Convert/CellValueConverter.hpp"
#include "Logic/Spawn/BoardSpawner.hpp"

class RandomBoardSpawner : public BoardSpawner
{
public:
    using ByteValue = CellValueConverter::ByteValue;
    using RCByteContainer = std::vector<CellValueConverter::ByteValue>;
    using RCByteMatrix = std::vector<RCByteContainer>;

public:
    RandomBoardSpawner() = default;
    RandomBoardSpawner(const RandomBoardSpawner&) = delete;
    RandomBoardSpawner(RandomBoardSpawner&&) = delete;

    ~RandomBoardSpawner() = default;

    Board SpawnBoard() const noexcept override;

    RandomBoardSpawner& operator = (const RandomBoardSpawner&) = delete;
    RandomBoardSpawner& operator = (RandomBoardSpawner&&) = delete;

private:
    bool FillBoard(Board& board, RCByteContainer& rowValues, 
        RCByteContainer& columnValues, RCByteMatrix& tripleValues,
        const Board::RCIndex i = 0, const Board::RCIndex j = 0)
        const noexcept;
    
    void SetValue(const ByteValue byteValue, ByteValue& rowValue, 
        ByteValue& columnValue, ByteValue& tripleValue) const noexcept;

    void UnsetValue(const ByteValue byteValue, ByteValue& rowValue, 
        ByteValue& columnValue, ByteValue& tripleValue) const noexcept;

private:
    CellValueConverter m_Converter{};

    mutable BoardCell::RangeValues m_PossibleValues
        { BoardCell::PossibleValues };
};
