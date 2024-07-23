#pragma once

#include <unordered_map>

#include "Utility/Clone/Clonable.hpp"

#define Template template <class _FindBy, class _CloneType>
#define AbsFacT AbstractFactory<_FindBy, _CloneType>
#define AbsFacTDef(returnType) Template \
    returnType AbsFacT

Template
class AbstractFactory
{
public:
    using Container = std::unordered_map<_FindBy, Clonable<_CloneType*>>;

public:
    AbstractFactory() = default;
    AbstractFactory(const AbstractFactory&) = default;
    AbstractFactory(AbstractFactory&&) = default;

    AbstractFactory(Container&& fabrics);

    ~AbstractFactory() = default;

    _CloneType* GetFabric(const _FindBy& key) const noexcept;

    AbstractFactory& operator = (const AbstractFactory&) = default;
    AbstractFactory& operator = (AbstractFactory&&) = default;

private:
    Container m_Fabrics{};    
};


AbsFacTDef()::AbstractFactory(Container&& fabrics)
    : m_Fabrics{ std::move(fabrics) }
{}

AbsFacTDef(_CloneType*)::GetFabric(const _FindBy& key) const noexcept
{
    auto foundFabric = m_Fabrics.find(key);

    if (foundFabric == m_Fabrics.end())
    {
        return nullptr;
    }

    return foundFabric.Clone();
}
