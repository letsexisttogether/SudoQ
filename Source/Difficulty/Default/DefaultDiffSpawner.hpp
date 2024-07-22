#pragma once

#include "Difficulty/DifficultySpawner.hpp"

class DefaultDiffSpawner : public DifficultySpawner
{
public:
    DefaultDiffSpawner() = default;
    DefaultDiffSpawner(const DefaultDiffSpawner&) = default;
    DefaultDiffSpawner(DefaultDiffSpawner&&) = default;

    DefaultDiffSpawner(const VisibleCellsCount count); 

    ~DefaultDiffSpawner() = default;

    VisibilityGrid SpawnDifficulty() noexcept override; 
};
