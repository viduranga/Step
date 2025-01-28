#pragma once
#include <variant>
#include <optional>
#include <map>
#include <cassert>

enum class ACTION : char {
  FORWARD = 'a',
  LEFT = 'l',
  RIGHT = 'r',
  END = 'e'
};

struct DebugInfo
{
  size_t line;
  size_t column;
};

template<typename T>
struct DebugWrap
{
  T &operator*()
  {
    return data;
  }

  T data;
  DebugInfo debugInfo;
};

struct Invocation;
struct Function;
struct Loop;

using Variable = std::optional<uint32_t>;

using Statement = std::variant<ACTION, Loop, Invocation>;
using Body = std::vector<DebugWrap<Statement>>;

using Program = std::map<char, DebugWrap<Function>>;

#define FUNC_MAIN '$'
#define SEEKER_VAR_1 '#'
