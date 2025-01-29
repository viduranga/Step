include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.13.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE TEST_SRC CONFIGURE_DEPENDS "*.cpp")

add_executable(
        test
        ${TEST_SRC}
)

target_compile_definitions(test PRIVATE TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data")
target_link_libraries(
        test
        GTest::gtest_main
        interpreter
        steplang
        parser
)

include(GoogleTest)
gtest_discover_tests(test)

