
# FetchContent_Declare(ftxui
#     GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
#     GIT_TAG v5.0.0
# )
# FetchContent_MakeAvailable(ftxui)

# if(NOT ftxui_POPULATED)
#     FetchContent_Populate(ftxui)
#     add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
# endif()

find_package(ftxui REQUIRED)

add_executable(step_tui main.cpp)
target_link_libraries(step_tui

    PUBLIC
    game_engine
    interpreter
    parser
    steplang
    ftxui::ftxui
)
