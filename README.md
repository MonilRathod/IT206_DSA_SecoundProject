# Tetris Game

This project is a simple implementation of the classic Tetris game using the Raylib library.

## Features

- Classic Tetris gameplay
- Score tracking
- Game over and restart functionality
- Dynamic block falling speed based on score

## Prerequisites

- C++ compiler (e.g., g++, clang++)
- Raylib library

## Setup

1. Clone the repository:
    ```sh
    git clone <repository-url>
    cd <repository-directory>
    ```

2. Install Raylib:
    - Follow the instructions on the [Raylib website](https://www.raylib.com/).
    - For example, on Windows, you can use vcpkg:
        ```sh
        vcpkg install raylib
        ```

3. Build the project:
    ```sh
    g++ main.cpp game.cpp -o tetris -lraylib -lopengl32 -lgdi32 -lwinmm
    ```

## Usage

1. Run the game:
    ```sh
    ./tetris
    ```

2. Controls:
    - Arrow keys to move the blocks
    - `R` to restart the game after a game over

## File Structure

- `main.cpp`: Contains the main game loop and rendering logic.
- `game.cpp` and `game.h`: Contains the game logic and state management.
- `resources/`: Directory containing game resources such as fonts.

## Code Overview

### main.cpp

- Initializes the game window and sets up the main game loop.
- Handles input and updates the game state.
- Renders the game elements including the score and game over screen.

### game.cpp

- Implements the game logic such as block movement, collision detection, and score calculation.
- Manages the game state including the current block, next block, and game over condition.

### game.h

- Declares the `game` class and its member functions and variables.

## Project Members

- Monil Rathod (ID: 202101409)
- Manush Jada  (ID: 202401070)

## Acknowledgements

- [Raylib](https://www.raylib.com/) - A simple and easy-to-use library to enjoy videogames programming.
- [Tetris](https://en.wikipedia.org/wiki/Tetris) - The classic tile-matching puzzle video game.
