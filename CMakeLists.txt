cmake_minimum_required(VERSION 3.0)
project(WallBall C CXX)

set(CMAKE_CXX_STANDARD 17)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(${PROJECT_NAME} main.cpp Player/Player.cpp Player/Player.h Block/Block.cpp Block/Block.h Ball/Ball.cpp Ball/Ball.h const.h)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
