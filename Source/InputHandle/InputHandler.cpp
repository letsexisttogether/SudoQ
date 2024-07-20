#include "InputHandler.hpp"

InputHandler::InputHandler(const HandlerPtr& handler)
    : m_NextHanlder{ handler }
{}

void InputHandler::SetNextHandler(const HandlerPtr& handler) noexcept
{
    m_NextHanlder = handler;
}
