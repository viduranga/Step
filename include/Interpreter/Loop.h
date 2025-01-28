#pragma once
#include <string>
#include <Interpreter/Defs.h>

struct Loop
{
    std::string condition;
    Body statements;
};
