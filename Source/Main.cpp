#include <iostream>
#include <memory>

#include "Application/Application.hpp"
#include "Scene/Builder/Default/DefaultSceneBuilder.hpp"

std::int32_t main(std::int32_t argc, char** argv)
{
    std::cout << "Hello, SudoQ" << std::endl;

    std::unique_ptr<SceneBuilder> sceneBuilder{ new DefaultSceneBuilder{} };

    sceneBuilder->BuildBoardPrinter().BuildBoard();

    Application& app = Application::GetApp();
    app.SetScene(sceneBuilder->GetResult());
    app.DoTheHardWork();

    return EXIT_SUCCESS;
}
