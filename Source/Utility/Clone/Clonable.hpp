#pragma once

template <class _CloneType>
class Clonable
{
public:
    virtual ~Clonable() = default;

    virtual _CloneType* Clone() const noexcept = 0;
};
