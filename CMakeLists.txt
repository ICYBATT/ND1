cmake_minimum_required(VERSION 3.15)
project(ND1_v2_0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(nd1_lib
    studentas.cpp
    FileIO.cpp
    Output.cpp
    NaturalSort.cpp
    Menu.cpp
    Generator.cpp
    Input.cpp
    Tyrimas.cpp
)

target_include_directories(nd1_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ND1
    main.cpp
)

target_link_libraries(ND1 PRIVATE nd1_lib)