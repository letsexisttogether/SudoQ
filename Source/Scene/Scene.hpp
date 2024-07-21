#pragma once

#include <memory>

#include "Board/BoardCell/BoardCell.hpp"
#include "InputHandle/InputHandler.hpp"
#include "Print/BoardPrinter.hpp"

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

    void SetInputHandler(InputHandler* inputHandler) noexcept;
    InputHandler* const GetInputHandler() noexcept;

    void SetInputValue(const BoardCell& inputValue) noexcept;

    Scene& operator = (const Scene&) = delete;
    Scene& operator = (Scene&&) = default;

private:
    bool IsGuessed() const noexcept;
    void ChangeVisibility() noexcept;

    bool IsWinCondition() const noexcept;

private:
    std::unique_ptr<BoardPrinter> m_Printer{};  
    Board m_Board{};

    // Input taker
    std::unique_ptr<InputHandler> m_InputHandler{};

    BoardCell m_InputValue{};

    // Win handler
};
