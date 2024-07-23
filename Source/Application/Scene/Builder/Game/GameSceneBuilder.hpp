#pragma once

#include <memory>

#include "Application/Scene/Builder/SceneBuilder.hpp"
#include "Application/Scene/Game/GameScene.hpp"
#include "Logic/Spawn/Random/RandomBoardSpawner.hpp"

class GameSceneBuilder : public SceneBuilder
{
public:
    using SBRef = GameSceneBuilder&;

public:
    GameSceneBuilder() = default;
    GameSceneBuilder(const GameSceneBuilder&) = delete;
    GameSceneBuilder(GameSceneBuilder&&) = default;

    ~GameSceneBuilder() = default;

    SBRef BuildBoardPrinter() noexcept;
    SBRef BuildBoard() noexcept;
    SBRef BuildInputTaker() noexcept;
    SBRef BuildInputHandler() noexcept;
    SBRef BuildVictoryHandle() noexcept;

    ScenePtr GetResult() noexcept override;

    void Reset() noexcept override;

protected:
    void CreateIfOut() noexcept override;


private:
    std::shared_ptr<GameScene> m_Scene{};

    std::unique_ptr<BoardSpawner> m_Spawner
    {
        new RandomBoardSpawner{}
    };
};
