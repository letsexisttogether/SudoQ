#include "DefaultSceneBuilder.hpp"

#include <memory>

#include "Difficulty/Guarantee/GuaranteeDiffSpawner.hpp"
#include "Difficulty/Random/RandDiffSpawner.hpp"
#include "InputHandle/Exit/ExitInputHandler.hpp"
#include "InputHandle/InputHandler.hpp"
#include "InputHandle/RowColumnValue/RCVInputHandler.hpp"
#include "InputTaker/Cmd/CmdInputTaker.hpp"
#include "Print/Cmd/BoardCmdPrinter.hpp"

SceneBuilder::SBRef DefaultSceneBuilder::BuildBoardPrinter() noexcept
{
    CreateIfOut();

    std::unique_ptr<DifficultySpawner> diffSpawner
    { 
        // new RandDiffSpawner{ 40 }
        new GuaranteeDiffSpawner{ 3, GuaranteeArea::Triple }
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
