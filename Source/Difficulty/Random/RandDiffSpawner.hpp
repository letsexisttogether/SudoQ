#pragma once

#include "Difficulty/DifficultySpawner.hpp"

class RandDiffSpawner : public DifficultySpawner
{
public:
    RandDiffSpawner() = default;
    RandDiffSpawner(const RandDiffSpawner&) = default;
    RandDiffSpawner(RandDiffSpawner&&) = default;

    RandDiffSpawner(const VisibleCellsCount count); 

    ~RandDiffSpawner() = default;

    VisibilityGrid SpawnDifficulty() noexcept override; 
};
