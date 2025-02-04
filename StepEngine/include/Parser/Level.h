#pragma once

#include <Parser/Defs.h>
#include <stdint.h>

struct Level
{
    Grid grid;
    uint32_t grid_size;
    DIRECTION facing;


    ITEM &operator()(uint32_t x, uint32_t y)
    {
        return grid[y * grid_size + x];
    }
};
