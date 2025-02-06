#pragma once

#include <Interpreter/Interpreter.h>
#include <Interpreter/Runtime.h>
#include <Parser/Level.h>
#include <Interpreter/Defs.h>
#include <Interpreter/Function.h>
#include <Interpreter/Loop.h>
#include <Interpreter/StackFrame.h>
#include <GameEngine/Defs.h>

class Game
{
  public:
    Game();
    void load(std::istream &&level_data, const std::string &program_data);

    GameStatus tick();
    [[nodiscard]] const Level &getLevel() const { return level; }

    uint32_t treat_count = 0;

    Level level;
    Runtime runtime;
    GameStatus status = GameStatus::NOT_STARTED;
    Interpreter interpreter;
    ACTION action = ACTION::FORWARD;
};
