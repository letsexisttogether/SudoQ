#pragma once

#include "Application/Scene/Builder/SceneBuilder.hpp"

class SBDirector
{
public:
    virtual ~SBDirector() = default;

    virtual SceneBuilder::ScenePtr GetScene() noexcept = 0;
};
