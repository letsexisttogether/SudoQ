#pragma once

#include "Logic/Board/Board.hpp"

class BoardSpawner
{
public:
    BoardSpawner() = default;

    virtual ~BoardSpawner() = default;

    virtual Board SpawnBoard() const noexcept = 0;
};
