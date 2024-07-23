#pragma once

#include "Application/Scene/Builder/Game/GameSceneBuilder.hpp"
#include "Application/Scene/Director/SBDirector.hpp"

class GSBDirector : public SBDirector
{
public:
    GSBDirector() = default;
    GSBDirector(const GSBDirector&) = delete;
    GSBDirector(GSBDirector&&) = delete;

    ~GSBDirector() = default;

    SceneBuilder::ScenePtr GetScene() noexcept override;

    GSBDirector& operator = (const GSBDirector&) = delete;
    GSBDirector& operator = (GSBDirector&&) = delete;

private:
    GameSceneBuilder m_Builder{};
};
