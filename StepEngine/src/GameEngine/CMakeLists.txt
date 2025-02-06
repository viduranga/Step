
add_library(game_engine STATIC)

target_sources(
       game_engine

        PUBLIC
        Game.cpp
)

target_link_libraries(
        game_engine

        PUBLIC
        interpreter
        parser
        steplang
)



