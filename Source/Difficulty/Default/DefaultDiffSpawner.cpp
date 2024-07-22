#include "DefaultDiffSpawner.hpp"

DefaultDiffSpawner::VisibilityGrid DefaultDiffSpawner::SpawnDifficulty() 
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

