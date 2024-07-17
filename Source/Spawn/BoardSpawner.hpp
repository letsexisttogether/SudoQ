#pragma once

#include "Board/Board.hpp"

class BoardSpawner
{
public:
    BoardSpawner() = default;

    virtual ~BoardSpawner() = default;

    virtual Board SpawnBoard() const noexcept = 0;
};
