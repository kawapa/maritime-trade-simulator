cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg

project(mts)

SET(SRC_LIST
    src/Alcohol.cpp
    src/Cargo.cpp
    src/Coordinates.cpp
    src/Game.cpp
    src/Fruit.cpp
    src/Island.cpp
    src/Item.cpp
    src/Map.cpp
    src/Player.cpp
    src/Ship.cpp
    src/Store.cpp
)

SET(SRC_LIST_TESTS
    tests/AlcoholTests.cpp
    tests/CoordinatesTests.cpp
    tests/FruitTests.cpp
    tests/ItemTests.cpp
    tests/PlayerTests.cpp
    tests/ShipTests.cpp
)

include_directories(src)
add_executable(${PROJECT_NAME} src/main.cpp ${SRC_LIST})
add_executable(${PROJECT_NAME}-ut ${SRC_LIST_TESTS} ${SRC_LIST})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic)
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -Werror -pedantic)

target_link_libraries(${PROJECT_NAME}-ut gtest_main)

enable_testing()
add_test(NAME Tests COMMAND ${PROJECT_NAME}-ut)