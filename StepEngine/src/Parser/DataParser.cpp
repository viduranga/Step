#include <Parser/DataParser.h>
#include <cstddef>
#include <iostream>
#include <Parser/Exception.h>
#include <Parser/Defs.h>
#include <cstring>

Level DataParser::parseLevel(std::istream &&data)
{
    Level level;
    std::string line;

    if (!std::getline(data, line)) {
        throw FileMalform("No grid size info");
    }

    auto grid_size = static_cast<size_t>(std::stoi(line));

    assert(grid_size > 0 && grid_size < 256);

    level.grid.resize(grid_size * grid_size, ITEM::EMPTY);
    level.grid_size = grid_size;

    for (size_t i = 0; i < grid_size; i++) {
        if (!std::getline(data, line)) {
            throw FileMalform("Too little grid lines");
        }

        memcpy(&level.grid[grid_size * i], line.data(), line.size() * sizeof(char));
    }

    if (!std::getline(data, line)) {
        throw FileMalform("No player direction info");
    }
    level.facing = static_cast<DIRECTION>(line[0]);

    if (!validateLevel(level)) {
        throw GridMalform("Grid is malformed");
    }

    // extractPlayer(level);

    auto player_it = std::find(level.grid.begin(), level.grid.end(), ITEM::PLAYER);

    auto player_index = std::distance(level.grid.begin(), player_it);
    level.grid[player_index] = ITEM::EMPTY;

    level.player = std::make_tuple(player_index % level.grid_size, player_index / level.grid_size);


    return level;
}

bool DataParser::validateLevel(const Level &level)
{

    uint32_t player_count = 0;
    uint32_t treat_count = 0;

    for (const auto &cell : level.grid) {
        if (cell == ITEM::PLAYER) {
            player_count++;
        } else if (cell == ITEM::TREAT) {
            treat_count++;
        }
    }

    if (treat_count == 0) {
        throw GridMalform("No treats in the grid");
    }

    if (player_count == 0) {
        throw GridMalform("No player in the grid");
    }

    if (player_count > 1) {
        throw GridMalform("Too many players in the grid");
    }

    return true;
}

// void DataParser::extractPlayer(Level &level)
// {
//     for (size_t i = 0; i < level.grid.size(); i++) {
//         if (level.grid[i] == ITEM::PLAYER) {
//             level.player = std::make_tuple(i % level.grid_size, i / level.grid_size);
//             level.grid[i] = ITEM::EMPTY;
//             return;
//         }
//     }
//     throw GridMalform("No player in the grid");
// }
