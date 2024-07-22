#pragma once

#include "InputTaker/InputTaker.hpp"

class CmdInputTaker : public InputTaker
{
public:
    using Message = std::string;

public:
    CmdInputTaker() = default;
    CmdInputTaker(const CmdInputTaker&) = default;
    CmdInputTaker(CmdInputTaker&&) = default;

    CmdInputTaker(Message&& message);

    ~CmdInputTaker() = default;

    InputHandler::HandleData TakeData() noexcept override;

    CmdInputTaker& operator = (const CmdInputTaker&) = default;
    CmdInputTaker& operator = (CmdInputTaker&&) = default;
};
