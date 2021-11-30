#include <iostream>
#include <catch2/catch.hpp>
#include <Parser/DataParser.h>
#include <fstream>

TEST_CASE("Parser test", "[parser]")
{
  DataParser parser;

  std::string level_str = "+_______________"
    "__+__________+__"
    "_+$__________$+_"
    "___*________*___"
    "________________"
    "________________"
    "____$___$$______"
    "________________"
    "________________"
    "____$___$$______"
    "________________"
    "__P_____________"
    "___*________*___"
    "_+*__________$+_"
    "__+__________+__"
    "________________";
  Level level;
  REQUIRE_NOTHROW(  level = parser.parseLevel(std::ifstream(std::string(TEST_DATA_DIR)+"/test.level")));
  REQUIRE(level.grid.size() == 16*16);
  REQUIRE(level.facing == DIRECTION::UP);

  std::string out(reinterpret_cast<char*>(level.grid.data()));
  REQUIRE(out == level_str);

}