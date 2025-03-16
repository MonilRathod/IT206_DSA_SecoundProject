cmake_minimum_required(VERSION 3.10.0)
project(tetris VERSION 0.1.0 LANGUAGES C CXX)
list(APPEND CMAKE_PREFIX_PATH "{CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/share/raylib/raylib-config.cmake")

add_executable(tetris main.cpp)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(tetris PRIVATE raylib)

