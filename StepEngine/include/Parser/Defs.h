#pragma once
#include <vector>

#include <cassert>

enum class ITEM : char {
    EMPTY = '_',
    PLAYER = 'P',
    BARRIER = '+',
    VOID = '*',
    TREAT = '$'
};

enum class DIRECTION : char {
    UP = 'U',
    DOWN = 'D',
    LEFT = 'L',
    RIGHT = 'R'
};

using Grid = std::vector<ITEM>;
