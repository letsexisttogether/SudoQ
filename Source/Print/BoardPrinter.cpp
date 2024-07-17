#include "BoardPrinter.hpp"

BoardPrinter::BoardPrinter(const Board& board, VisibilityGrid&& grid)
    : m_Board{ board }, m_CellsVisibility{ std::move(grid) }
{}

