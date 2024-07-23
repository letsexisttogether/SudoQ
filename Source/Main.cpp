#include <iostream>
#include <memory>

#include "Application/Application.hpp"
#include "Application/Scene/Builder/Game/GameSceneBuilder.hpp"

std::int32_t main(std::int32_t argc, char** argv)
{
    std::cout << "Hello, SudoQ" << std::endl;

    std::unique_ptr<GameSceneBuilder> sceneBuilder{ new GameSceneBuilder{} };

    sceneBuilder->BuildBoardPrinter().BuildBoard()
        .BuildInputTaker().BuildInputHandler().BuildVictoryHandle();

    Application& app = Application::GetApp();

    // app.SetSceneDirector();

    app.SetScene(sceneBuilder->GetResult());
    app.DoTheHardWork();

    return EXIT_SUCCESS;
}
