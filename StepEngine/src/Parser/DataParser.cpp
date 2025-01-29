#include <Parser/DataParser.h>
#include <iostream>
#include <Parser/Exception.h>
#include <Parser/Defs.h>
#include <cstring>

Level DataParser::parseLevel(std::istream &&data)
{
    Level level;
    std::string line;

    if (!std::getline(data, line))
        throw FileMalform("No grid size info");

    uint32_t grid_size = static_cast<uint32_t>(std::stoi(line));

    assert(grid_size > 0 && grid_size < 256);

    level.grid.resize(grid_size * grid_size, ITEM::EMPTY);
    level.grid_size = grid_size;

    for (uint32_t i = 0; i < grid_size; i++) {
        if (!std::getline(data, line))
            throw FileMalform("Too little grid lines");

        memcpy(&level.grid[grid_size * i], &line[0], line.size() * sizeof(char));
    }

    if (!std::getline(data, line))
        throw FileMalform("No player direction info");
    level.facing = static_cast<DIRECTION>(line[0]);

    if (!validateLevel(level))
        throw GridMalform("Grid is malformed");

    return level;
}

bool DataParser::validateLevel(const Level &level)
{

    uint32_t player_count = 0;
    uint32_t treat_count = 0;

    for (auto &cell : level.grid) {
        if (cell == ITEM::PLAYER)
            player_count++;
        else if (cell == ITEM::TREAT)
            treat_count++;
    }

    if (treat_count == 0)
        throw GridMalform("No treats in the grid");

    if (player_count == 0)
        throw GridMalform("No player in the grid");

    if (player_count > 1)
        throw GridMalform("Too many players in the grid");

    return true;
}
