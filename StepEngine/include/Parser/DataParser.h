#pragma once
#include <Parser/Level.h>
#include <istream>

class DataParser
{
  public:
    static Level parseLevel(std::istream &&data);
    static bool validateLevel(const Level &level);
};
