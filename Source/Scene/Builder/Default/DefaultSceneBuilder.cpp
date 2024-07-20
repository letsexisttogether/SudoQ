#include "DefaultSceneBuilder.hpp"
#include "InputHandle/Exit/ExitInputHandler.hpp"
#include "InputHandle/InputHandler.hpp"
#include "Print/Cmd/BoardCmdPrinter.hpp"

SceneBuilder::SBRef DefaultSceneBuilder::BuildBoardPrinter() noexcept
{
    CreateIfOut();

    m_Scene->SetPrinter(new BoardCmdPrinter{{}});

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

    m_Scene->SetInputHandler(handler);

    return *this;
}
