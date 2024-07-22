#pragma once

#include "Difficulty/DifficultySpawner.hpp"

class DefaultDiffSpawner : public DifficultySpawner
{
public:
    DefaultDiffSpawner() = default;
    DefaultDiffSpawner(const DefaultDiffSpawner&) = default;
    DefaultDiffSpawner(DefaultDiffSpawner&&) = default;

    ~DefaultDiffSpawner() = default;

    VisibilityGrid SpawnDifficulty() noexcept override; 

    DefaultDiffSpawner& operator = (const DefaultDiffSpawner&) 
        = default;
    DefaultDiffSpawner& operator = (DefaultDiffSpawner&&) 
        = default;
};
