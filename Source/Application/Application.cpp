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

void Application::SetSceneDirector(SBDirector* director) noexcept
{
    m_SceneDirector.reset(director);

    m_Scene = director->GetScene();
}

Scene* const Application::GetScene() noexcept
{
    return m_Scene.get();
}

void Application::SetShouldContinue(const bool shouldContinue) noexcept
{
    m_ShouldContinue = shouldContinue;
}
