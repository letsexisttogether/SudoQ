#pragma once

#include "Difficulty/DifficultySpawner.hpp"

class RandDiffSpawner : public DifficultySpawner
{
public:
    using VisibleCellsCount = Board::RCIndex;
    
public:
    RandDiffSpawner() = default;
    RandDiffSpawner(const RandDiffSpawner&) = default;
    RandDiffSpawner(RandDiffSpawner&&) = default;

    RandDiffSpawner(const VisibleCellsCount count); 

    ~RandDiffSpawner() = default;

    VisibilityGrid SpawnDifficulty() noexcept override; 

    RandDiffSpawner& operator = (const RandDiffSpawner&) = default;
    RandDiffSpawner& operator = (RandDiffSpawner&&) = default;

private:
    VisibleCellsCount m_Count{};    
};
