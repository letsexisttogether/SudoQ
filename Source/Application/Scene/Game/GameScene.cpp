#include "GameScene.hpp"

void GameScene::UpdateLogic() noexcept
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

void GameScene::UpdateGraphic() noexcept
{
    m_Printer->PrintBoard(m_Board);
}

BoardPrinter* const GameScene::GetPrinter() noexcept
{
    return m_Printer.get();
}

void GameScene::SetPrinter(BoardPrinter* printer) noexcept
{
    m_Printer.reset(printer);
}

const Board& GameScene::GetBoard() const noexcept
{
    return m_Board;
}

void GameScene::SetBoard(Board&& board) noexcept
{
    m_Board = std::move(board);
}

InputTaker* const GameScene::GetInputTaker() noexcept
{
    return m_InputTaker.get();
}

void GameScene::SetInputTaker(InputTaker* inputTaker) noexcept
{
    m_InputTaker.reset(inputTaker);
}

InputHandler* const GameScene::GetInputHandler() noexcept
{
    return m_InputHandler.get();
}

void GameScene::SetInputHandler(InputHandler* inputHandler) noexcept
{
    m_InputHandler.reset(inputHandler);
}

void GameScene::SetInputValue(const BoardCell& inputValue) noexcept
{
    m_InputValue = inputValue;
}

void GameScene::SetVictoryHandle(VictoryHandler* victoryHandle) noexcept
{
    m_VictoryHandle.reset(victoryHandle);
}

bool GameScene::IsGuessed() const noexcept
{
    return (m_Board.GetCellValue(m_InputValue.Row, m_InputValue.Column)
        == m_InputValue.Value);
}

void GameScene::ChangeVisibility() noexcept
{
    m_Printer->SetCellVisibility(m_InputValue.Row, m_InputValue.Column,
        true);
}

bool GameScene::IsWinCondition() const noexcept
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
