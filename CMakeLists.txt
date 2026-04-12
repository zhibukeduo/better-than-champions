cmake_minimum_required(VERSION 3.20)
project(better-than-champions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

execute_process(COMMAND git config core.hooksPath hooks
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(better-than-champions ${SOURCES})

target_include_directories(better-than-champions PRIVATE src)
