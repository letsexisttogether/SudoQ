#pragma once

#include "Print/BoardPrinter.hpp"

class DifficultySpawner
{
public:
    using VisibilityGrid = BoardPrinter::VisibilityGrid;

public:
    DifficultySpawner() = default;

    virtual ~DifficultySpawner() = default;

    virtual VisibilityGrid SpawnDifficulty() noexcept = 0; 
};
