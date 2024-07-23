#include "Scene.hpp"

void Scene::UpdateLogic() noexcept
{
    InputHandler::HandleData data{ m_InputTaker->TakeData() };

    m_InputHandler->Handle(data);

    if (IsGuessed())
    {
        ChangeVisibility();

        m_InputValue.Reset();
    }

    if (IsWinCondition())
    {
        m_VictoryHandle->HandleVictory();
    }
}

void Scene::UpdateGraphic() noexcept
{
    m_Printer->PrintBoard(m_Board);
}

void Scene::SetPrinter(BoardPrinter* printer) noexcept
{
    m_Printer.reset(printer);
}

BoardPrinter* const Scene::GetPrinter() noexcept
{
    return m_Printer.get();
}

void Scene::SetBoard(Board&& board) noexcept
{
    m_Board = std::move(board);
}

const Board& Scene::GetBoard() const noexcept
{
    return m_Board;
}

void Scene::SetInputTaker(InputTaker* inputTaker) noexcept
{
    m_InputTaker.reset(inputTaker);
}

InputTaker* const Scene::GetInputTaker() noexcept
{
    return m_InputTaker.get();
}

void Scene::SetInputHandler(InputHandler* inputHandler) noexcept
{
    m_InputHandler.reset(inputHandler);
}

InputHandler* const Scene::GetInputHandler() noexcept
{
    return m_InputHandler.get();
}

void Scene::SetInputValue(const BoardCell& inputValue) noexcept
{
    m_InputValue = inputValue;
}

void Scene::SetVictoryHandle(VictoryHandler* victoryHandle) noexcept
{
    m_VictoryHandle.reset(victoryHandle);
}

bool Scene::IsGuessed() const noexcept
{
    return (m_Board.GetCellValue(m_InputValue.Row, m_InputValue.Column)
        == m_InputValue.Value);
}

void Scene::ChangeVisibility() noexcept
{
    m_Printer->SetCellVisibility(m_InputValue.Row, m_InputValue.Column,
        true);
}

bool Scene::IsWinCondition() const noexcept
{
    for (const auto& row : m_Printer->GetRawGrid())
    {
        for (const auto& element : row)
        {
            if (!element)
            {
                return false;
            }
        }
    }

    return true;
}

