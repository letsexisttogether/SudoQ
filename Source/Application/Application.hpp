#pragma once

#include <memory>

#include "Application/Scene/Director/SBDirector.hpp"
#include "Scene/Scene.hpp"

class Application
{
public:
    using ScenePtr = std::shared_ptr<Scene>;

public:
    static Application& GetApp() noexcept;

public:
    void DoTheHardWork() noexcept;

    void SetSceneDirector(SBDirector* director) noexcept;
    Scene* const GetScene() noexcept;

    void SetShouldContinue(const bool shouldContinue) noexcept;

private:
    Application() = default;
    Application(const Application&) = delete;
    Application(Application&&) = delete;

    ~Application() = default;

private:
    std::unique_ptr<SBDirector> m_SceneDirector{};
    ScenePtr m_Scene{};

    bool m_ShouldContinue{ true };
};
