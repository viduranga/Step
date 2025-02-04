FetchContent_Declare(
        antlr4
        GIT_REPOSITORY https://github.com/antlr/antlr4
        GIT_TAG v4.11.1
        SOURCE_SUBDIR runtime/Cpp
)
#
FetchContent_MakeAvailable(antlr4)

add_library(steplang STATIC)

target_sources(
       steplang

        PUBLIC
        StepLangBaseListener.cpp
        StepLangBaseVisitor.cpp
        StepLangLexer.cpp
        StepLangListener.cpp
        StepLangParser.cpp
        StepLangVisitor.cpp
)

target_include_directories(
        steplang

        PUBLIC
        ${LIBANTLR4_SOURCE_DIR}/runtime/src
)

target_link_libraries(
        steplang

        PUBLIC
        antlr4_static
)


