#include "GuaranteeDiffSpawner.hpp"
#include "Difficulty/Guarantee/GuaranteeArea.hpp"
#include <numeric>
#include <random>

GuaranteeDiffSpawner::GuaranteeDiffSpawner(const VisibleCellsCount count,
    const GuaranteeArea area)
    : RandDiffSpawner{ count }, m_Area{ area } 
{}

GuaranteeDiffSpawner::VisibilityGrid GuaranteeDiffSpawner::SpawnDifficulty()
    noexcept
{
    switch (m_Area)
    {
        case GuaranteeArea::Row:
            return SpawnByRow();
        case GuaranteeArea::Column:
            return SpawnByColumn();
        case GuaranteeArea::Triple:
            return SpawnByTriple();
    }

    return {};
}

GuaranteeDiffSpawner::VisibilityGrid GuaranteeDiffSpawner::SpawnByRow()
    const noexcept
{
    VisibilityGrid grid{};
    
    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {
        const IndicesArray indices
        { 
            SpawnRandomIndices(Board::GridMaxIndex) 
        };

        for (Board::RCIndex j = 0; j < m_Count; ++j)
        {
            grid.SetCellValue(i, indices[j], true);
        }
    }

    return grid;

}

GuaranteeDiffSpawner::VisibilityGrid GuaranteeDiffSpawner::SpawnByColumn()
    const noexcept
{
    VisibilityGrid grid{};
    
    for (Board::RCIndex i = 0; i < Board::GridMaxIndex; ++i)
    {
        const IndicesArray indices
        { 
            SpawnRandomIndices(Board::GridMaxIndex) 
        };

        for (Board::RCIndex j = 0; j < m_Count; ++j)
        {
            grid.SetCellValue(indices[j], i, true);
        }
    }

    return grid;
}

GuaranteeDiffSpawner::VisibilityGrid GuaranteeDiffSpawner::SpawnByTriple()
    const noexcept
{
    VisibilityGrid grid{};
    
    for (Board::RCIndex i = 0; i < Board::TripleMaxIndex; ++i)
    {
        for (Board::RCIndex j = 0; j < Board::TripleMaxIndex; ++j)
        {
            const IndicesArray indices
            { 
                SpawnRandomIndices(Board::GridMaxIndex) 
            };

            for (Board::RCIndex k = 0; k < m_Count; ++k)
            {
                const Board::RCIndex index = indices[k];

                const Board::RCIndex row = index / Board::TripleMaxIndex;
                const Board::RCIndex column = index % Board::TripleMaxIndex;

                const Board::RCIndex actualRow = i * Board::TripleMaxIndex
                    + row;
                const Board::RCIndex actualColumn = j * Board::TripleMaxIndex
                    + column;

                grid.SetCellValue(actualRow, actualColumn, true);
            }
        }
    }

    return grid;
}
