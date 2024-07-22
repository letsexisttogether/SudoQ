#include "Application.hpp"

Application& Application::GetApp() noexcept
{
    static Application app{};

    return app;
}

void Application::DoTheHardWork() noexcept
{
    // Do the SetUp()

    while(m_ShouldContinue)
    {
        m_Scene->UpdateGraphic();

        m_Scene->UpdateLogic();
    }

    // Do the CleanUp()
}

void Application::SetScene(const ScenePtr scene) noexcept
{
    m_Scene = scene;
}

Scene* const Application::GetScene() noexcept
{
    return m_Scene.get();
}

void Application::SetShouldContinue(const bool shouldContinue) noexcept
{
    m_ShouldContinue = shouldContinue;
}
