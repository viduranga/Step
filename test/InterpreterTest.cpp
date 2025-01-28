#include <iostream>
#include <Interpreter/Interpreter.h>
#include <Interpreter/Runtime.h>
#include <Interpreter/Evaluator.h>
#include <gtest/gtest.h>

class InterpreterTest : public testing::Test
{
protected:
  Interpreter intepreter;
};

TEST_F(InterpreterTest, Evaluator)
{
  EXPECT_EQ(Evaluator::evaluate("12*4+(15-2)-10/5"), 59);
}

TEST_F(InterpreterTest, EvaluatorWithArgs)
{
  EXPECT_EQ(Evaluator::evaluate("10*x+y", { { 'x', 2 }, { 'y', 3 }, { '#', 3 } }), 23);
}

TEST_F(InterpreterTest, RecursiveProgram)
{
  const auto *code =
    "g(x)=ag(x-1)\n"
    "f(x)=g(x)rf(x-1)\n"
    "f(10)\n";

  auto program = intepreter.parse(code);

  Runtime runtime;
  runtime.load(program);

  std::string output;
  for (auto action = runtime.step(); action != ACTION::END; action = runtime.step()) {
    output += static_cast<char>(action);
  }

  EXPECT_EQ(output, "aaaaaaaaaaraaaaaaaaaraaaaaaaaraaaaaaaraaaaaaraaaaaraaaaraaaraarar");
}

TEST_F(InterpreterTest, IterativeProgram)
{
  const auto *code =
    "f(x)=<x>[a]rf(x-1)\n"
    "f(10)\n";

  auto program = intepreter.parse(code);

  Runtime runtime;
  runtime.load(program);

  std::string output;
  for (auto action = runtime.step(); action != ACTION::END; action = runtime.step()) {
    output += static_cast<char>(action);
  }

  EXPECT_EQ(output, "aaaaaaaaaaraaaaaaaaaraaaaaaaaraaaaaaaraaaaaaraaaaaraaaaraaaraarar");
}
