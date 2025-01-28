#pragma once
#include <string>
#include <map>
#include <stdint.h>

class Evaluator
{
  public:
    static int evaluate(const std::string &expression);
    static int evaluate(std::string expression, const std::map<char, uint32_t> &variables);

  private:
    static int precedence(char op);
    static int applyOp(int a, int b, char op);
};
