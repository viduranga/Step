
add_library(interpreter STATIC)

target_sources(
        interpreter

        PUBLIC
        Evaluator.cpp
        Interpreter.cpp
        Runtime.cpp
)


target_link_libraries(
        interpreter

        PUBLIC
        steplang
)


