#pragma once

#include <memory>

#include "Application/Scene/Builder/SceneBuilder.hpp"
#include "Logic/Spawn/Random/RandomBoardSpawner.hpp"

class DefaultSceneBuilder : public SceneBuilder
{
public:
    DefaultSceneBuilder() = default;
    DefaultSceneBuilder(const DefaultSceneBuilder&) = delete;
    DefaultSceneBuilder(DefaultSceneBuilder&&) = default;

    ~DefaultSceneBuilder() = default;

    SBRef BuildBoardPrinter() noexcept override;
    SBRef BuildBoard() noexcept override;
    SBRef BuildInputTaker() noexcept override;
    SBRef BuildInputHandler() noexcept override;
    SBRef BuildVictoryHandle() noexcept override;

private:
    std::unique_ptr<BoardSpawner> m_Spawner
    {
        new RandomBoardSpawner{}
    };
};
