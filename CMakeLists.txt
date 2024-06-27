cmake_minimum_required(VERSION 3.28)

project(dragonfly_engine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
  src/managers/include
)

set(SOURCES
  src/managers/Manager.cpp
  src/managers/LogManager.cpp
)

set(HEADERS
  src/managers/include/Manager.h
  src/managers/include/LogManager.h
)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)

add_library(dragonfly_engine STATIC ${SOURCES} ${HEADERS})
