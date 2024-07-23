#pragma once

#include "Logic/Spawn/BoardSpawner.hpp"

class DefaultBoardSpawner : public BoardSpawner
{
public:
    DefaultBoardSpawner() = default;
    DefaultBoardSpawner(const DefaultBoardSpawner&) = default;
    DefaultBoardSpawner(DefaultBoardSpawner&&) = default;

    ~DefaultBoardSpawner() = default;

    Board SpawnBoard() const noexcept override;

    DefaultBoardSpawner& operator = (const DefaultBoardSpawner&) = delete;
    DefaultBoardSpawner& operator = (DefaultBoardSpawner&) = delete;
};
