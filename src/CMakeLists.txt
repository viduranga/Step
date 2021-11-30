file(GLOB StepLang_SRC "StepLang/*.cpp")
file(GLOB Interpreter_SRC "Interpreter/*.cpp")
file(GLOB Parser_SRC "Parser/*.cpp")
file(GLOB GDNative_SRC "GDNative/*.cpp")

include_directories(${antlr4-cppruntime_INCLUDES})
# Generic test that uses conan libs
add_library(step_lang STATIC ${StepLang_SRC})
set_property(TARGET step_lang PROPERTY CXX_STANDARD 11)
target_link_libraries(step_lang antlr4-cppruntime::antlr4-cppruntime)
target_include_directories(step_lang PRIVATE ${CMAKE_SOURCE_DIR}/include/StepLang)

add_library(interpreter STATIC ${Interpreter_SRC})
target_link_libraries(interpreter
        PRIVATE project_options
                project_warnings
                step_lang)

add_library(parser STATIC ${Parser_SRC})
target_link_libraries(parser
        PRIVATE project_options
                project_warnings)

add_library(step_engine_gdnative SHARED ${GDNative_SRC})

target_link_libraries(step_engine_gdnative
        PRIVATE project_options
                project_warnings
                interpreter
                parser
                godot-cpp::godot-cpp)

#target_link_libraries(
#  intro
#  PRIVATE project_options
#          project_warnings
#          docopt::docopt
#          fmt::fmt
#          spdlog::spdlog)
