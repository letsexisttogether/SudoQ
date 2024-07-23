#include "InputTaker.hpp"

InputTaker::InputTaker(Message&& message)
    : m_Message{ std::move(message) }
{}

const InputTaker::Message& InputTaker::GetMessage()
    const noexcept
{
    return m_Message;
}

void InputTaker::SetMessage(Message&& message) noexcept
{
    m_Message = std::move(message);
}
