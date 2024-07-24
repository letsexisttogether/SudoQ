#pragma once

#include "Menu/Item/MenuItem.hpp"

class MenuItemEqual
{
public:
    bool operator () (const MenuItem& first, const MenuItem& second)
        const noexcept;
};
