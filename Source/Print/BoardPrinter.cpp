#include "BoardPrinter.hpp"

BoardPrinter::BoardPrinter(VisibilityGrid&& grid)
    : m_CellsVisibility{ std::move(grid) }
{}

