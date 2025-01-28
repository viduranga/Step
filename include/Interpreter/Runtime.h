#pragma once
#include <Interpreter/Defs.h>
#include <stack>
#include <Interpreter/Function.h>
#include <Interpreter/Loop.h>
#include <Interpreter/StackFrame.h>

class Runtime
{
  public:
    Runtime();

    void load(Program _program);

    ACTION step();
    void reset();

  private:
    Program program;
    std::stack<StackFrame> stack;
};
