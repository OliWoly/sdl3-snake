# Snake Game
*SDL3 Implementation with C++*

# TODO
- [n] Make the grid a tile system.

    - [n] Each tile should be able to be replaced/hidden by an apple/snake.

    - [n] Each tile should have its own position, colour, etc. Basically an entity. 

    - [n] Grid should work off of tiles and dynamically remove/hide them when obstructed.

# Compilation
## Dependencies
Dependencies should be installed using the systems package manager globally as shared libs.

### MacOS
Homebrew
```bash
brew install sdl3 sdl3_ttf
```
Homebrew install packages to /opt/homebrew
Packages should be able to be found there. As seen in the cmakelists.txt file.


### Linux
Arch - Pacman/Yay
```bash
sudo pacman -S sdl3
yay -S sdl3_ttf-git
```
Pacman should handle all necessary dependencies too.
I've had more luck using the sdl3_ttf-git package to install ttf - building from source.

```bash
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig
```
Its important this env variable is set.

```bash
pkg-config --modversion sdl3-ttf
```
Using this you can check if SDL3_ttf is installed correctly..

## Building

### Terminal
Make sure you are in the source directory (not /src).
```bash
mkdir build
cd build
cmake ..
make
./sdl3-snake
```

### IDE
You can also set up IDE's to build, e.g, I use CLion. 
On MacOS, it seems to work perfectly. On linux setup is needed.
