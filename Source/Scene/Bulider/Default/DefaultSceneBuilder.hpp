#pragma once

#include <memory>

#include "Scene/Bulider/SceneBuilder.hpp"
#include "Spawn/Random/RandomBoardSpawner.hpp"

class DefaultSceneBuilder : public SceneBuilder
{
public:
    DefaultSceneBuilder() = default;
    DefaultSceneBuilder(const DefaultSceneBuilder&) = delete;
    DefaultSceneBuilder(DefaultSceneBuilder&&) = default;

    ~DefaultSceneBuilder() = default;

    SBRef BuildBoardPrinter() noexcept override;
    SBRef BuildBoard() noexcept override;

private:
    std::unique_ptr<BoardSpawner> m_Spawner
    {
        new RandomBoardSpawner{}
    };
};
