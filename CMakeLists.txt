cmake_minimum_required(VERSION 3.10)
project(shm)

SET(SRC_LIST
    src/Alcohol.cpp
    src/Cargo.cpp
    src/Coordinates.cpp
    src/DryFruit.cpp
    src/Fruit.cpp
    src/Island.cpp
    src/Item.cpp
    src/Map.cpp
    src/Player.cpp
    src/Ship.cpp
    src/Store.cpp
)

include_directories(inc)
add_executable(${PROJECT_NAME} src/main.cpp ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic)