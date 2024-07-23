#pragma once

#include <memory>

#include "Print/BoardPrinter.hpp"
#include "Logic/Board/BoardCell/BoardCell.hpp"
#include "Input/Handle/InputHandler.hpp"
#include "Input/Take/InputTaker.hpp"
#include "VictoryHandle/VictoryHandler.hpp"

class Scene
{
public:
    Scene() = default;
    Scene(const Scene&) = delete;
    Scene(Scene&&) = default;

    ~Scene() = default;

    void UpdateLogic() noexcept;
    void UpdateGraphic() noexcept;

    void SetPrinter(BoardPrinter* printer) noexcept;
    BoardPrinter* const GetPrinter() noexcept;

    void SetBoard(Board&& board) noexcept;
    const Board& GetBoard() const noexcept;

    void SetInputTaker(InputTaker* inputTaker) noexcept;
    InputTaker* const GetInputTaker() noexcept;

    void SetInputHandler(InputHandler* inputHandler) noexcept;
    InputHandler* const GetInputHandler() noexcept;

    void SetInputValue(const BoardCell& inputValue) noexcept;

    void SetVictoryHandle(VictoryHandler* victoryHandle) noexcept;

    Scene& operator = (const Scene&) = delete;
    Scene& operator = (Scene&&) = default;

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
