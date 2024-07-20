#include "ExitInputHandler.hpp"

#include "Application/Application.hpp"

ExitInputHandler::ExitInputHandler(const HandlerPtr& handler)
    : InputHandler{ handler }
{}

void ExitInputHandler::Handle(const HandleData& data) const noexcept
{
    if (CanHandle(data))
    {
        Application::GetApp().SetShouldContinue(false);
    }
}

bool ExitInputHandler::CanHandle(const HandleData& data) const noexcept
{
    return (data == "exit");
}
