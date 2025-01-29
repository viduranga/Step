#pragma once
#include <Interpreter/Defs.h>
#include <stdint.h>
#include <map>

struct StackFrame
{
    Body *body;
    Body::iterator seeker;
    std::map<char, uint32_t> variables;
};
