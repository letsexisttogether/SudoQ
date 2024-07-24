#pragma once

#include <cstdint>
#include <string>
#include <unordered_set>

class MenuItem
{
public:
    using Index = std::uint16_t;
    using Name = std::string; 

public:
    MenuItem() = default;
    MenuItem(const MenuItem&) = default;
    MenuItem(MenuItem&&) = default;

    MenuItem(const Index index);

    virtual ~MenuItem() = default;

    virtual void Execute() noexcept = 0;

    virtual void AddItem() noexcept = 0;
    virtual void RemoveItem() noexcept = 0;

    Index GetIndex() const noexcept;

public:
    struct Hash
    {
        using Result = std::size_t;
   
        Result operator () (const MenuItem& item) const noexcept;
    };

    struct Equal
    {
        bool operator () (const MenuItem& first, const MenuItem& second)
            const noexcept;
    };

public:
    using SubItems = std::unordered_set<MenuItem, Hash, Equal>;

protected:
    Index m_Index{};
    Name m_Name{}; 

    SubItems m_SubItems{};
};
