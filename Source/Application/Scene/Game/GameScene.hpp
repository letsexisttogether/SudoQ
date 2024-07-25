#pragma once

#include <memory>

#include "Application/Scene/Scene.hpp"
#include "Print/BoardPrinter.hpp"
#include "Logic/Board/BoardCell/BoardCell.hpp"
#include "Input/Handle/InputHandler.hpp"
#include "Input/Take/InputTaker.hpp"
#include "VictoryHandle/VictoryHandler.hpp"

class GameScene : public Scene
{
public:
    GameScene() = default;
    GameScene(const GameScene&) = delete;
    GameScene(GameScene&&) = default;

    ~GameScene() = default;

    void UpdateLogic() noexcept override;
    void UpdateGraphic() noexcept override;

    BoardPrinter* const GetPrinter() noexcept;
    void SetPrinter(BoardPrinter* printer) noexcept;

    const Board& GetBoard() const noexcept;
    void SetBoard(Board&& board) noexcept;

    InputTaker* const GetInputTaker() noexcept;
    void SetInputTaker(InputTaker* inputTaker) noexcept;

    InputHandler* const GetInputHandler() noexcept;
    void SetInputHandler(InputHandler* inputHandler) noexcept;

    void SetInputValue(const BoardCell& inputValue) noexcept;

    void SetVictoryHandle(VictoryHandler* victoryHandle) noexcept;

    GameScene& operator = (const GameScene&) = delete;
    GameScene& operator = (GameScene&&) = default;

private:
    bool IsGuessed() const noexcept;
    void ChangeVisibility() noexcept;

    bool IsWinCondition() const noexcept;

private:
    std::unique_ptr<BoardPrinter> m_Printer{};  
    Board m_Board{};

    std::unique_ptr<InputTaker> m_InputTaker{};
    std::unique_ptr<InputHandler> m_InputHandler{};

    BoardCell m_InputValue{};

    std::unique_ptr<VictoryHandler> m_VictoryHandle{};
};
