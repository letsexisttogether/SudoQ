#include "MenuItemEqual.hpp"


bool MenuItemEqual::operator () (const MenuItem& first,
    const MenuItem& second) const noexcept
{
    return first.GetIndex() == second.GetIndex();
}
