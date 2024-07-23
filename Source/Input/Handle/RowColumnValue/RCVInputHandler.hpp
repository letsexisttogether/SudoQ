#pragma once

#include "Input/Handle/InputHandler.hpp"

class RCVInputHandler : public InputHandler
{
public:
    RCVInputHandler() = default;

    RCVInputHandler(const HandlerPtr handler);

    ~RCVInputHandler() = default;

    void Handle(const HandleData& data) noexcept override;

protected:
    bool CanHandle(const HandleData& data) const noexcept override;
};
