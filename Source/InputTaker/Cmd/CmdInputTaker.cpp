#include "CmdInputTaker.hpp"
#include <iostream>
#include <string>

CmdInputTaker::CmdInputTaker(Message&& message) 
    : InputTaker{ std::move(message) }
{}

InputHandler::HandleData CmdInputTaker::TakeData() noexcept 
{
    std::cout << m_Message;

    InputHandler::HandleData data{};

    std::getline(std::cin, data);

    return data;
}
