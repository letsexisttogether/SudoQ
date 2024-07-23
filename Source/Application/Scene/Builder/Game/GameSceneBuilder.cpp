#include "GameSceneBuilder.hpp"

#include <memory>

#include "Logic/Difficulty/Guarantee/GuaranteeDiffSpawner.hpp"
#include "Input/Handle/Exit/ExitInputHandler.hpp"
#include "Input/Handle/RowColumnValue/RCVInputHandler.hpp"
#include "Input/Take/Cmd/CmdInputTaker.hpp"
#include "Print/Cmd/BoardCmdPrinter.hpp"
#include "Application/Scene/Builder/SceneBuilder.hpp"
#include "VictoryHandle/Cmd/CmdVictoryHandler.hpp"

GameSceneBuilder::ScenePtr GameSceneBuilder::GetResult() noexcept
{
    ScenePtr temp{ m_Scene };

    Reset();

    return temp;
}

void GameSceneBuilder::CreateIfOut() noexcept
{
    if (!m_Scene)
    {
        m_Scene.reset(new GameScene{});
    }
}

void GameSceneBuilder::Reset() noexcept
{
    m_Scene.reset();
}

GameSceneBuilder::SBRef GameSceneBuilder::BuildBoardPrinter() noexcept
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

GameSceneBuilder::SBRef GameSceneBuilder::BuildBoard() noexcept
{
    CreateIfOut();

    m_Scene->SetBoard(m_Spawner->SpawnBoard());

    return *this;
}

GameSceneBuilder::SBRef GameSceneBuilder::BuildInputTaker() noexcept
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

GameSceneBuilder::SBRef GameSceneBuilder::BuildInputHandler() noexcept
{
    CreateIfOut();

    InputHandler* handler = new ExitInputHandler{};
    handler->SetNextHandler(std::make_shared<RCVInputHandler>());

    m_Scene->SetInputHandler(handler);

    return *this;
}

GameSceneBuilder::SBRef GameSceneBuilder::BuildVictoryHandle() noexcept
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
