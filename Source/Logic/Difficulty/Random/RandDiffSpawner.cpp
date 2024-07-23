#include "RandDiffSpawner.hpp"

#include <numeric>
#include <random>

RandDiffSpawner::RandDiffSpawner(const VisibleCellsCount count)
    : m_Count{ count % (Board::GridMaxIndex * Board::GridMaxIndex) }
{}

RandDiffSpawner::VisibilityGrid RandDiffSpawner::SpawnDifficulty() 
    noexcept
{
    VisibilityGrid grid{};

    const Board::RCIndex indicesSize = 
        Board::GridMaxIndex * Board::GridMaxIndex;
    const IndicesArray indices{ SpawnRandomIndices(indicesSize) };

    for (Board::RCIndex i = 0; i < m_Count; ++i)
    {
        const Board::RCIndex index = indices[i];

        const Board::RCIndex row = index / Board::GridMaxIndex;
        const Board::RCIndex column = index % Board::GridMaxIndex;

        grid.SetCellValue(row, column, true);
    }

    return grid;
}


RandDiffSpawner::IndicesArray RandDiffSpawner::SpawnRandomIndices
    (const VisibleCellsCount size) const noexcept
{
    IndicesArray indices(size);
    std::iota(indices.begin(), indices.end(), 0);

    std::mt19937 rng{ std::random_device{}() };
    std::shuffle(indices.begin(), indices.end(), rng);

    return indices;
}
