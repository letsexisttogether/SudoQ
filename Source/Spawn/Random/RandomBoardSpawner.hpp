#pragma once

#include "Convert/CellValueConverter.hpp"
#include "Spawn/BoardSpawner.hpp"

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
    Board::CellValue SpawnValue(ByteValue& rowValue, 
        ByteValue& columnValue, ByteValue& tripleValue) const noexcept;

private:
    CellValueConverter m_Converter{};
};
