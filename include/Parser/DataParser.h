#pragma once
#include <Parser/Level.h>
#include <istream>

class DataParser
{
  public:
    Level parseLevel(std::istream &&data);
    bool validateLevel(const Level &level);
};
