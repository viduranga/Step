#include <Interpreter/Evaluator.h>
#include <stack>
#include <Interpreter/Exception.h>

void findAndReplaceAll(std::string &data, const std::string &toSearch, const std::string &replaceStr)
{
  // Get the first occurrence
  size_t pos = data.find(toSearch);

  // Repeat till end is reached
  while (pos != std::string::npos) {
    // Replace this occurrence of Sub String
    data.replace(pos, toSearch.size(), replaceStr);
    // Get the next occurrence from the current position
    pos = data.find(toSearch, pos + replaceStr.size());
  }
}

int Evaluator::precedence(char op)
{
  if (op == '+' || op == '-') {
    return 1;
  }
  if (op == '*' || op == '/') {
    return 2;
  }
  return 0;
}

int Evaluator::applyOp(int a, int b, char op)
{
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  default:
    throw InvalidOperator(op);
  }
}

int Evaluator::evaluate(const std::string &expression)
{
  uint32_t i;

  std::stack<int> values;

  std::stack<char> ops;

  for (i = 0; i < expression.length(); i++) {
    if (expression[i] == ' ') {
      continue;
    }
    if (expression[i] == '(') {
      ops.push(expression[i]);
    } else if (isdigit(expression[i])) {
      int val = 0;
      while (i < expression.length() && isdigit(expression[i])) {
        val = (val * 10) + (expression[i] - '0');
        i++;
      }
      i--;// Because for loop increases again
      values.push(val);
    } else if (expression[i] == ')') {
      while (!ops.empty() && ops.top() != '(') {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
      }
      if (!ops.empty())
        ops.pop();
    } else {
      // While top of 'ops' has same or greater
      // precedence to current token, which
      // is an operator. Apply operator on top
      // of 'ops' to top two elements in values stack.
      while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
      }

      // Push current token to 'ops'.
      ops.push(expression[i]);
    }
  }

  // Entire expression has been parsed at this
  // point, apply remaining ops to remaining
  // values.
  while (!ops.empty()) {
    int val2 = values.top();
    values.pop();

    int val1 = values.top();
    values.pop();

    char op = ops.top();
    ops.pop();

    values.push(applyOp(val1, val2, op));
  }

  // Top of 'values' contains result, return it.
  return values.top();
}

int Evaluator::evaluate(std::string expression, const std::map<char, uint32_t> &variables)
{
  for (auto [var, val] : variables) {
    findAndReplaceAll(expression, std::string(1, var), std::to_string(val));
  }
  return Evaluator::evaluate(expression);
}
