#pragma once

#include "Board/Board.hpp"
#include "Print/BoardPrinter.hpp"

class DifficultySpawner
{
public:
    using VisibilityGrid = BoardPrinter::VisibilityGrid;
    using VisibleCellsCount = Board::RCIndex;

public:
    DifficultySpawner() = default;

    DifficultySpawner(const VisibleCellsCount count); 

    virtual ~DifficultySpawner() = default;

    virtual VisibilityGrid SpawnDifficulty() noexcept = 0; 

protected:
    VisibleCellsCount m_Count{};    
};
