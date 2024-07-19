#pragma once

#include "Scene/Scene.hpp"

class Application
{
public:
    static Application& GetApp() noexcept;

public:
    void DoTheHardWork() noexcept;

    void SetScene(Scene&& scene) noexcept;

    void SetShouldContinue(const bool shouldContinue) noexcept;

private:
    Application() = default;
    Application(const Application&) = delete;
    Application(Application&&) = delete;

    ~Application() = default;

private:
    Scene m_Scene{};

    bool m_ShouldContinue{ true };
};
