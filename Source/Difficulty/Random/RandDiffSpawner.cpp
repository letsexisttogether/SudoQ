#include "RandDiffSpawner.hpp"

RandDiffSpawner::RandDiffSpawner(const VisibleCellsCount count)
    : DifficultySpawner{ count }
{}

RandDiffSpawner::VisibilityGrid RandDiffSpawner::SpawnDifficulty() 
    noexcept
{
    const VisibilityGrid grid
    {{
        { true, false, false, false, true, false, false, false, true },
        { false, true, false, true, false, true, false, true, false },
        { false, false, true, false, false, false, true, false, false },
        { true, false, false, true, false, true, false, false, true },
        { false, true, false, false, true, false, false, true, false },
        { true, false, true, false, true, false, true, false, true },
        { false, true, false, false, false, false, false, true, false },
        { true, false, true, false, false, false, true, false, true },
        { false, true, false, true, false, true, false, true, false }
    }};

    return grid;
}


