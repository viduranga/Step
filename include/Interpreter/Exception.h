#pragma once
#include <exception>
#include <string>


class InvalidOperator : virtual public std::exception
{

  public:
    explicit InvalidOperator(char _op)
    {
        op = std::string(static_cast<unsigned long>(_op), 1);
        error_message = std::string("Invalid operator:") + op;
    }

    ~InvalidOperator() noexcept override = default;

    [[nodiscard]] const char *what() const noexcept override
    {
        return error_message.c_str();
    }

  private:
    std::string op{};
    std::string error_message{};
};
