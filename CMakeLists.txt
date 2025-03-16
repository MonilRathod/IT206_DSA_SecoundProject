cmake_minimum_required(VERSION 3.10.0)
project(tetris VERSION 0.1.0 LANGUAGES C CXX)

list (APPEND CMAKE_PREFIX_PATH "C:/Users/M416/vcpkg/installed/x64-windows")

# Use the vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "C:/Users/M416/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Find Raylib via vcpkg
find_package(raylib CONFIG REQUIRED)

# Create the executable
add_executable(tetris main.cpp)

# Link Raylib
target_link_libraries(tetris PRIVATE raylib)
