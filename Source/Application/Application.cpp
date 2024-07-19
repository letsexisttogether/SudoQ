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
        m_Scene.UpdateGraphic();

        m_Scene.UpdateLogic();
    }

    // Do the CleanUp()
}

void Application::SetScene(Scene&& scene) noexcept
{
    m_Scene = std::move(scene);
}

void Application::SetShouldContinue(const bool shouldContinue) noexcept
{
    m_ShouldContinue = shouldContinue;
}
