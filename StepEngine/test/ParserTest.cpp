#include <iostream>
#include <Parser/DataParser.h>
#include <fstream>
#include <gtest/gtest.h>

TEST(ParserTest, BasicLevelParse)
{
  DataParser parser;

  std::string level_str =
    "+_______________"
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
  EXPECT_NO_THROW(level = parser.parseLevel(std::ifstream(std::string(TEST_DATA_DIR) + "/test.level")));
  EXPECT_EQ(level.grid.size(), 16 * 16);
  EXPECT_EQ(level.facing, DIRECTION::UP);

  std::string out(reinterpret_cast<char *>(level.grid.data()));
  EXPECT_EQ(out, level_str);
}
