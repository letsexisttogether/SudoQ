#include "DefaultSceneBuilder.hpp"
#include "InputHandle/Exit/ExitInputHandler.hpp"
#include "InputHandle/InputHandler.hpp"
#include "InputHandle/RowColumnValue/RCVInputHandler.hpp"
#include "Print/Cmd/BoardCmdPrinter.hpp"
#include <memory>

SceneBuilder::SBRef DefaultSceneBuilder::BuildBoardPrinter() noexcept
{
    CreateIfOut();

    BoardPrinter* printer = new BoardCmdPrinter
    {
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


SceneBuilder::SBRef DefaultSceneBuilder::BuildInputHandler() noexcept
{
    CreateIfOut();

    InputHandler* handler = new ExitInputHandler{};
    handler->SetNextHandler(std::make_shared<RCVInputHandler>());

    m_Scene->SetInputHandler(handler);

    return *this;
}
