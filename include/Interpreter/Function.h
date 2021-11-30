#pragma once
#include <map>
#include <string>
#include <Interpreter/Defs.h>
#include <variant>
#include <Interpreter/Invocation.h>
#include <vector>

struct Function {
    char name;
    std::vector<char> parameters;
    Body statements;
};



