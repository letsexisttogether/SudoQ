#include "SceneBuilder.hpp"

SceneBuilder::ScenePtr SceneBuilder::GetResult() noexcept
{
    ScenePtr temp{ m_Scene };

    Reset();

    return temp;
}

void SceneBuilder::CreateIfOut() noexcept
{
    if (!m_Scene)
    {
        m_Scene.reset(new Scene{});
    }
}

void SceneBuilder::Reset() noexcept
{
    m_Scene.reset();
}
