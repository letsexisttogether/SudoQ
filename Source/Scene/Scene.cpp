#include "Scene.hpp"
#include "Application/Application.hpp"

#include <iostream>

void Scene::UpdateLogic() noexcept
{
    std::cout << "Enter indices and a value like\n" 
        << "row column value\n";

    Board::RCIndex row{};
    Board::RCIndex column{};
    Board::CellValue value{};

    std::cin >> row >> column >> value;

    std::cout << "Row: " << row << " Column: " << column 
        << " Value: " << value << std::endl;

    Application::GetApp().SetShouldContinue(false);
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
