cmake_minimum_required(VERSION 3.16)

project(SDL_OPENGL)

set(CMAKE_C_STANDARD 11)

# Find packages
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# Source files
file(GLOB SRC_FILES src/*.c)

add_executable(SDL_NEW_GAME ${SRC_FILES})

# Include directories
target_include_directories(SDL_NEW_GAME PRIVATE
    ${SDL2_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(SDL_NEW_GAME
    SDL2::SDL2
    OpenGL::GL
)
