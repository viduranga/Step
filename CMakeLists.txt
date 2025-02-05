cmake_minimum_required(VERSION 3.28)

project(Step CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Don't check C compiler
set(CMAKE_C_COMPILER_WORKS 1)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -std=c++20")

endif()

# set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MACOSX_RPATH 1)


include_directories($<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/StepEngine/include/StepLang>
                    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/StepEngine/include>)

add_subdirectory(StepEngine)
add_subdirectory(StepTUI)
