#include "Interpreter/Defs.h"
#include "Parser/DataParser.h"
#include "Parser/Defs.h"
#include <Parser/Level.h>
#include <GameEngine/Game.h>

Game::Game() = default;

void Game::load(std::istream &&level_data, const std::string &program_data)
{
    this->level = DataParser::parseLevel(std::move(level_data));
    if (!program_data.empty()) {
        this->runtime.load(interpreter.parse(program_data));
    }

    treat_count = std::ranges::count(level.grid.begin(), level.grid.end(), ITEM::TREAT);
}


GameStatus Game::tick()
{
    if (status == GameStatus::ENDED) {
        return status;
    }

    if (status == GameStatus::NOT_STARTED) {
        status = GameStatus::IN_PROGRESS;
    }

    action = runtime.step();

    auto player_x = std::get<0>(level.player);
    auto player_y = std::get<1>(level.player);
    auto facing = level.facing;

    switch (action) {
    case ACTION::FORWARD: {
        switch (facing) {
        case DIRECTION::UP:
            player_y = player_y - 1;
            break;
        case DIRECTION::DOWN:
            player_y = player_y + 1;
            break;
        case DIRECTION::LEFT:
            player_x = player_x - 1;
            break;
        case DIRECTION::RIGHT:
            player_x = player_x + 1;
            break;
        }

        auto next = level[player_x, player_y];

        if (next == ITEM::VOID) {
            level.player = std::make_tuple(player_x, player_y);
            status = GameStatus::ENDED;
        } else if (next == ITEM::BARRIER || player_x >= level.grid_size || player_y >= level.grid_size) {
            // don't move
        } else if (next == ITEM::TREAT) {
            treat_count--;
            level[player_x, player_y] = ITEM::EMPTY;
            level.player = std::make_tuple(player_x, player_y);

            if (treat_count == 0) {
                status = GameStatus::ENDED;
            }
        } else if (next == ITEM::EMPTY) {
            level.player = std::make_tuple(player_x, player_y);
        }

        break;
    }
    case ACTION::LEFT: {
        switch (facing) {
        case DIRECTION::UP:
            facing = DIRECTION::LEFT;
            break;
        case DIRECTION::DOWN:
            facing = DIRECTION::RIGHT;
            break;
        case DIRECTION::LEFT:
            facing = DIRECTION::DOWN;
            break;
        case DIRECTION::RIGHT:
            facing = DIRECTION::UP;
            break;
        }
        break;
    }
    case ACTION::RIGHT: {
        switch (facing) {
        case DIRECTION::UP:
            facing = DIRECTION::RIGHT;
            break;
        case DIRECTION::DOWN:
            facing = DIRECTION::LEFT;
            break;
        case DIRECTION::LEFT:
            facing = DIRECTION::UP;
            break;
        case DIRECTION::RIGHT:
            facing = DIRECTION::DOWN;
            break;
        }
        break;
    }
    case ACTION::END:
        status = GameStatus::ENDED;
        break;
    }

    level.facing = facing;

    return status;
}
