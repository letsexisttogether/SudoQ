#pragma once

#include <memory>

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
    void SetBoard(Board&& board) noexcept;

    Scene& operator = (const Scene&) = delete;
    Scene& operator = (Scene&&) = default;

private:
    std::unique_ptr<BoardPrinter> m_Printer{};  
    Board m_Board{};

    // Input
    // InputParser
    // 
};
