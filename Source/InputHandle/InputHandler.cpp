#include "InputHandler.hpp"

InputHandler::InputHandler(const HandlerPtr handler)
    : m_NextHanlder{ handler }
{}

void InputHandler::SetNextHandler(const HandlerPtr handler) noexcept
{
    m_NextHanlder = handler;
}

void InputHandler::CallNextHandler(const HandleData& data) noexcept
{
    if (m_NextHanlder)
    {
        m_NextHanlder->Handle(data);
    }
}
