#include "Scene.hpp"

#include <iostream>
#include <string>

void Scene::UpdateLogic() noexcept
{
    InputHandler::HandleData data{};
    
    std::cout << "Enter command:\n";

    std::getline(std::cin, data);

    std::cout << "Your command is " << data << std::endl;

    m_InputHandler->Handle(data);
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

void Scene::SetInputHandler(InputHandler* inputHandler) noexcept
{
    m_InputHandler.reset(inputHandler);
}

InputHandler* const Scene::GetInputHandler() noexcept
{
    return m_InputHandler.get();
}
