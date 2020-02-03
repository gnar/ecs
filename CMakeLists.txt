cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp src/ECS.cpp src/ECS.h src/Component.cpp src/Component.h src/components/Actor.cpp src/components/Actor.h src/components/Pos2d.cpp src/components/Pos2d.h src/systems/GameLogic.cpp src/systems/GameLogic.h)