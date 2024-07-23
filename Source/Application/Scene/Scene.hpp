#pragma once

class Scene
{
public:
    ~Scene() = default;

    virtual void UpdateLogic() noexcept = 0;
    virtual void UpdateGraphic() noexcept = 0;
};
