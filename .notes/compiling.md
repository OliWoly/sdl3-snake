# Current cmakelists.txt
```cmake
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sdl3-snake VERSION 1.0)

set(CMAKE_PREFIX_PATH "/opt/homebrew")
find_package(SDL3 REQUIRED)

add_executable(sdl3-snake src/main.cpp)

# Include SDL3 headers
target_include_directories(sdl3-snake PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL3_INCLUDE_DIRS}
)

# Link SDL3 to the executable
target_link_libraries(sdl3-snake ${SDL3_LIBRARIES})
```

# Where are these random variables coming from?
*(SDL3_INCLUDE_DIRS, SDL3_LIBRARIES)?!?!?*
```cmake
find_package().
```
- These variables are automatically created by the find_package() function built into cmake.

# How does it know where to look?
*Important Note*
Will have to install this with some sort of package manager.

```
find_package()
``` 
..looks for default directories in the system where these libraries could be.

## Macos Specific
Just so happens that the homebrew one is automatically found however in previous cases i had to include the;
```cmake
set(CMAKE_PREFIX_PATH "/opt/homebrew")
```

## Linux Specific
Appears to be just the same so far however will try and sort this out.

## Windows Specific 
Fuck off.