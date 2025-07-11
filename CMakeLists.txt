cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sdl3-snake VERSION 1.0)

set(CMAKE_PREFIX_PATH "/opt/homebrew")
find_package(SDL3 REQUIRED)
find_package(SDL3_TTF REQUIRED)

# Gather all .cpp files in the src directory
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
add_executable(sdl3-snake ${SRC_FILES})

# Include SDL3 headers
target_include_directories(sdl3-snake PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL3_INCLUDE_DIRS}
    ${SDL3_TTF_INCLUDE_DIRS}
)

target_link_libraries(sdl3-snake SDL3::SDL3 SDL3_ttf::SDL3_ttf)

