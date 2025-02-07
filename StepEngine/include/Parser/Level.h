#pragma once

#include <Parser/Defs.h>
#include <stdint.h>

struct Level
{
    Grid grid;
    std::tuple<uint32_t, uint32_t> player;

    uint32_t grid_size;
    DIRECTION facing;


    ITEM &operator[](uint32_t x, uint32_t y)
    {
        return grid[(y * grid_size) + x];
    }

    const ITEM &operator[](uint32_t x, uint32_t y) const
    {
        return grid[(y * grid_size) + x];
    }
};
