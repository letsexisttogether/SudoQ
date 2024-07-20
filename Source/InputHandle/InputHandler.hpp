#pragma once

#include <memory>
#include <string>

class InputHandler
{
public:
    using HandlerPtr = std::shared_ptr<InputHandler>;
    using HandleData = std::string;

public:
    InputHandler() = default;

    InputHandler(const HandlerPtr& handler);

    virtual ~InputHandler() = default;

    virtual void Handle(const HandleData& data) const noexcept = 0;

    void SetNextHandler(const HandlerPtr& handler) noexcept;

protected:
    virtual bool CanHandle(const HandleData& data) const noexcept = 0;

protected:
    HandlerPtr m_NextHanlder{};
};
