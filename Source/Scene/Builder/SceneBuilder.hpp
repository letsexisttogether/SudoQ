#pragma once

#include "Scene/Scene.hpp"

class SceneBuilder
{
public:
    using SBRef = SceneBuilder&;
    using ScenePtr = std::shared_ptr<Scene>;

public:
    SceneBuilder() = default;

    virtual ~SceneBuilder() = default;

    virtual SBRef BuildBoardPrinter() noexcept = 0;
    virtual SBRef BuildBoard() noexcept = 0;
    virtual SBRef BuildInputTaker() noexcept = 0;
    virtual SBRef BuildInputHandler() noexcept = 0;

    ScenePtr GetResult() noexcept;

protected:
    void CreateIfOut() noexcept;

private:
    void Reset() noexcept;

protected:
    ScenePtr m_Scene{};
};
