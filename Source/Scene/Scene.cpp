#include "Scene.hpp"
#include "Application/Application.hpp"

#include <iostream>

void Scene::UpdateLogic() noexcept
{
    std::cout << "Enter indices and a value like\n" 
        << "row column value\n";

    InputHandler::HandleData data{};
    
    std::cout << "Enter command:\n";

    std::cin >> data;

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

void Scene::SetBoard(Board&& board) noexcept
{
    m_Board = std::move(board);
}

void Scene::SetInputHandler(InputHandler* inputHandler) noexcept
{
    m_InputHandler.reset(inputHandler);
}
