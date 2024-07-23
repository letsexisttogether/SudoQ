#pragma once

#include <string>

#include "Input/Handle/InputHandler.hpp"

class InputTaker
{
public:
    using Message = std::string;

public:
    InputTaker() = default;

    InputTaker(Message&& message);

    virtual ~InputTaker() = default;

    virtual InputHandler::HandleData TakeData() noexcept = 0;

    const Message& GetMessage() const noexcept;
    void SetMessage(Message&& message) noexcept;

protected:
    Message m_Message{};
};
