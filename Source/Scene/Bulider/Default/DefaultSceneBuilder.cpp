#include "DefaultSceneBuilder.hpp"
#include "Print/Cmd/BoardCmdPrinter.hpp"

SceneBuilder::SBRef DefaultSceneBuilder::BuildBoardPrinter() noexcept
{
    m_Scene->SetPrinter(new BoardCmdPrinter{{}});

    return *this;
}

SceneBuilder::SBRef DefaultSceneBuilder::BuildBoard() noexcept
{
    m_Scene->SetBoard(m_Spawner->SpawnBoard());

    return *this;
}
