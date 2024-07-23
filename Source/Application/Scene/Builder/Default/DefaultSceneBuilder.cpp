#include "DefaultSceneBuilder.hpp"

#include <memory>

#include "Logic/Difficulty/Guarantee/GuaranteeDiffSpawner.hpp"
#include "Input/Handle/Exit/ExitInputHandler.hpp"
#include "Input/Handle/RowColumnValue/RCVInputHandler.hpp"
#include "Input/Take/Cmd/CmdInputTaker.hpp"
#include "Print/Cmd/BoardCmdPrinter.hpp"
#include "Application/Scene/Builder/SceneBuilder.hpp"
#include "VictoryHandle/Cmd/CmdVictoryHandler.hpp"

SceneBuilder::SBRef DefaultSceneBuilder::BuildBoardPrinter() noexcept
{
    CreateIfOut();

    std::unique_ptr<DifficultySpawner> diffSpawner
    { 
        new GuaranteeDiffSpawner{ 5, GuaranteeArea::Triple }
    };

    BoardPrinter* printer = new BoardCmdPrinter
    {
        true, '.', diffSpawner->SpawnDifficulty()
    };

    m_Scene->SetPrinter(printer);

    return *this;
}

SceneBuilder::SBRef DefaultSceneBuilder::BuildBoard() noexcept
{
    CreateIfOut();

    m_Scene->SetBoard(m_Spawner->SpawnBoard());

    return *this;
}

SceneBuilder::SBRef DefaultSceneBuilder::BuildInputTaker() noexcept
{   
    CreateIfOut();

    InputTaker* taker = new CmdInputTaker
    {
        "You can type row, column, value [1; 9] " \
            "like 1 2 2 or exit.\nEnter command: "
    };

    m_Scene->SetInputTaker(taker);

    return *this;
}

SceneBuilder::SBRef DefaultSceneBuilder::BuildInputHandler() noexcept
{
    CreateIfOut();

    InputHandler* handler = new ExitInputHandler{};
    handler->SetNextHandler(std::make_shared<RCVInputHandler>());

    m_Scene->SetInputHandler(handler);

    return *this;
}

SceneBuilder::SBRef DefaultSceneBuilder::BuildVictoryHandle() noexcept
{
    CreateIfOut();

    VictoryHandler* handler = new CmdVictoryHandler
    {
        "Congratulations, You have solved this puzzle\n" \
        "You have won SudoQ\nThis time it's officially nepemora\n"
    };

    m_Scene->SetVictoryHandle(handler);

    return *this;
}
