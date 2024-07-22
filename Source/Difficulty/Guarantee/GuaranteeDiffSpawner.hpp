#pragma once

#include "Difficulty/Guarantee/GuaranteeArea.hpp"
#include "Difficulty/Random/RandDiffSpawner.hpp"

class GuaranteeDiffSpawner : public RandDiffSpawner 
{
public:
    GuaranteeDiffSpawner() = default;
    GuaranteeDiffSpawner(const GuaranteeDiffSpawner&) = default;
    GuaranteeDiffSpawner(GuaranteeDiffSpawner&&) = default;

    GuaranteeDiffSpawner(const VisibleCellsCount count,
        const GuaranteeArea area); 

    ~GuaranteeDiffSpawner() = default;

    VisibilityGrid SpawnDifficulty() noexcept override; 

    GuaranteeDiffSpawner& operator = (const GuaranteeDiffSpawner&) = default;
    GuaranteeDiffSpawner& operator = (GuaranteeDiffSpawner&&) = default;

private:
    VisibilityGrid SpawnByRow() const noexcept;
    VisibilityGrid SpawnByColumn() const noexcept;
    VisibilityGrid SpawnByTriple() const noexcept;

private:
    GuaranteeArea m_Area{};
};
