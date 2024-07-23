#pragma once

#include <memory>

#include "Application/Scene/Scene.hpp"

class SceneBuilder
{
public:
    using ScenePtr = std::shared_ptr<Scene>;

public:
    virtual ~SceneBuilder() = default;

    virtual ScenePtr GetResult() noexcept = 0;

    virtual void Reset() noexcept = 0;

protected:
    virtual void CreateIfOut() noexcept = 0;
};
