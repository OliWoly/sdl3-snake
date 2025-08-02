cmake_minimum_required(VERSION 3.10)
project(sdl3-snake VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# PLATFROM DETECTION
if(APPLE)
    message(STATUS "Building on macOS")
    set(CMAKE_PREFIX_PATH "/opt/homebrew")
elseif(LINUX)
    message(STATUS "Building on Linux")
endif()


find_package(SDL3 QUIET)
find_package(SDL3_ttf QUIET)

# Fallback to pkg-config if CMake packages not found
if(NOT SDL3_FOUND)
    if(LINUX)
        find_package(PkgConfig REQUIRED)
        pkg_check_modules(SDL3 REQUIRED sdl3)
    endif()
endif()

if(NOT SDL3_TTF_FOUND)
    if(LINUX)
        message(STATUS "ONLY LINUX")
        pkg_check_modules(SDL3_TTF REQUIRED sdl3-ttf)
    endif()
endif()

# Add your sources
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        ${SDL3_INCLUDE_DIRS}
        ${SDL3_TTF_INCLUDE_DIRS}
)

#target_link_libraries(${PROJECT_NAME}
#        ${SDL3_LIBRARIES}
#        ${SDL3_TTF_LIBRARIES}
#)

target_link_libraries(sdl3-snake SDL3::SDL3 SDL3_ttf::SDL3_ttf)