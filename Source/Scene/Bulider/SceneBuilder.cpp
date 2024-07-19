#include "SceneBuilder.hpp"

SceneBuilder::SBRef SceneBuilder::BuildBoardPrinter() noexcept
{
    return *this;
}

SceneBuilder::SBRef SceneBuilder::BuildBoard() noexcept
{

    return *this;
}

SceneBuilder::ScenePtr SceneBuilder::GetResult() noexcept
{
    ScenePtr temp{ m_Scene };

    Reset();

    return temp;
}

void SceneBuilder::Reset() noexcept
{
    m_Scene.reset();
}
