#include "GSBDirector.hpp"

SceneBuilder::ScenePtr GSBDirector::GetScene() noexcept
{
    m_Builder.BuildBoard().BuildBoardPrinter()
        .BuildInputTaker().BuildInputHandler().BuildVictoryHandle();

    return m_Builder.GetResult();
}
