#pragma once

#include "InputHandle/InputHandler.hpp"

class ExitInputHandler : public InputHandler
{
public:
    ExitInputHandler() = default;

    ExitInputHandler(const HandlerPtr& handler);

    ~ExitInputHandler() = default;

    void Handle(const HandleData& data) const noexcept override;

protected:
    bool CanHandle(const HandleData& data) const noexcept override;
};
