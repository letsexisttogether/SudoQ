#pragma once

#include <cstddef>

#include "Menu/Item/MenuItem.hpp"

class MenuItemHash
{
public:
    using Result = std::size_t;

public:
    Result operator () (const MenuItem& item) const noexcept;
};

