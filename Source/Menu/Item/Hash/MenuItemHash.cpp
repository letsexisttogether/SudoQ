#include "MenuItemHash.hpp"

MenuItemHash::Result MenuItemHash::operator () (const MenuItem& item)
    const noexcept
{
    return item.GetIndex();
}
