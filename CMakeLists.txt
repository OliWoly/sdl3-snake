cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sdl3-snake VERSION 1.0)

set(CMAKE_PREFIX_PATH "/opt/homebrew")
find_package(SDL3 REQUIRED)

add_executable(sdl3-snake src/main.cpp src/game.cpp src/player.cpp)

# Include SDL3 headers
target_include_directories(sdl3-snake PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL3_INCLUDE_DIRS}
)

# Link SDL3 to the executable
target_link_libraries(sdl3-snake ${SDL3_LIBRARIES})

