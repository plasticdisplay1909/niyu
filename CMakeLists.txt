cmake_minimum_required(VERSION 3.20)

project(Niyu LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(niyu_lib
    src/compiler.cpp
)

target_include_directories(niyu_lib
    PUBLIC include
)

add_executable(niyu
    src/main.cpp
)

target_link_libraries(niyu
    PRIVATE niyu_lib
)