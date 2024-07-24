#include "MenuItem.hpp"

MenuItem::MenuItem(const Index index)
    : m_Index{ index }
{}

MenuItem::Index MenuItem::GetIndex() const noexcept
{   
    return m_Index;
}

MenuItem::Hash::Result MenuItem::Hash::operator () (const MenuItem& item)
    const noexcept
{
    return item.GetIndex();
}

bool MenuItem::Equal::operator () (const MenuItem& first,
    const MenuItem& second) const noexcept
{
    return first.GetIndex() == second.GetIndex();
}

