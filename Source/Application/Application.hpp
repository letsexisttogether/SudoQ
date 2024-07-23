#pragma once

#include <memory>

#include "Scene/Scene.hpp"

class Application
{
public:
    using ScenePtr = std::shared_ptr<Scene>;

public:
    static Application& GetApp() noexcept;

public:
    void DoTheHardWork() noexcept;

    void SetScene(const ScenePtr scene) noexcept;
    Scene* const GetScene() noexcept;

    void SetShouldContinue(const bool shouldContinue) noexcept;

private:
    Application() = default;
    Application(const Application&) = delete;
    Application(Application&&) = delete;

    ~Application() = default;

private:
    ScenePtr m_Scene{};

    bool m_ShouldContinue{ true };
};
