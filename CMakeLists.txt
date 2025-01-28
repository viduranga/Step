cmake_minimum_required(VERSION 3.28)

project(StepEngine CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

message("Detected cmake version ${CMAKE_VERSION}")

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.28.0)
  message("Detected cmake version 3.28.0 or higher. Experimental C++ modules are not required.")
else()
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
  if(${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.27.0)
    message("Detected cmake version 3.27.0 or higher")
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "aa1f7df0-828a-4fcd-9afc-2dc80491aca7")
  elseif(${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.26.0)
    message("Detected cmake version 3.26.0 or higher")
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
  endif()
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=stdlibc++")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=stdlibc++")

  include(gcc_modules.cmake)
endif()

#link_libraries("-fsanitize=undefined")
# set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Default to C++ extensions being off. Clang's modules support have trouble
# with extensions right now.
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MACOSX_RPATH 1)

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

include_directories($<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/StepLang> $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

add_subdirectory(src)
add_subdirectory(test)
