#include "DefaultSceneBuilder.hpp"
#include "InputHandle/Exit/ExitInputHandler.hpp"
#include "InputHandle/InputHandler.hpp"
#include "InputHandle/RowColumnValue/RCVInputHandler.hpp"
#include "InputTaker/Cmd/CmdInputTaker.hpp"
#include "Print/Cmd/BoardCmdPrinter.hpp"
#include "Scene/Builder/SceneBuilder.hpp"
#include <memory>

SceneBuilder::SBRef DefaultSceneBuilder::BuildBoardPrinter() noexcept
{
    CreateIfOut();

    BoardPrinter* printer = new BoardCmdPrinter
    {
        true, '.',
        {{
            { true, false, false, false, true, false, false, false, true },
            { false, true, false, true, false, true, false, true, false },
            { false, false, true, false, false, false, true, false, false },
            { true, false, false, true, false, true, false, false, true },
            { false, true, false, false, true, false, false, true, false },
            { true, false, true, false, true, false, true, false, true },
            { false, true, false, false, false, false, false, true, false },
            { true, false, true, false, false, false, true, false, true },
            { false, true, false, true, false, true, false, true, false }
        }}
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
