#include "Application/Application.hpp"
#include "Application/Scene/Director/Game/GSBDirector.hpp"

std::int32_t main(std::int32_t argc, char** argv)
{
    Application& app = Application::GetApp();

    app.SetSceneDirector(new GSBDirector{});
    app.DoTheHardWork();

    return EXIT_SUCCESS;
}
