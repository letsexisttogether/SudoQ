#pragma once

#include "Difficulty/DifficultySpawner.hpp"

class RandDiffSpawner : public DifficultySpawner
{
public:
    using VisibleCellsCount = Board::RCIndex;
    using IndicesArray = std::vector<VisibleCellsCount>;
    
public:
    RandDiffSpawner() = default;
    RandDiffSpawner(const RandDiffSpawner&) = default;
    RandDiffSpawner(RandDiffSpawner&&) = default;

    RandDiffSpawner(const VisibleCellsCount count); 

    virtual ~RandDiffSpawner() = default;

    VisibilityGrid SpawnDifficulty() noexcept override; 

    RandDiffSpawner& operator = (const RandDiffSpawner&) = default;
    RandDiffSpawner& operator = (RandDiffSpawner&&) = default;

protected:
    IndicesArray SpawnRandomIndices(const VisibleCellsCount size)
        const noexcept;

protected:
    VisibleCellsCount m_Count{};    
};
