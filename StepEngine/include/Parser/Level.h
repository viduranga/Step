#pragma once

#include <Parser/Defs.h>
#include <stdint.h>

struct Level
{
    Grid grid;
    uint32_t grid_size;
    DIRECTION facing;
};
