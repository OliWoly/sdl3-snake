// Oliwier Kulczycki
#pragma once
#include "colour.h"


// Refresh Rates
constexpr float PHYSICS_REFRESH_RATE = 1000.0/240;
constexpr float SNAKE_MOVE_RATE = 1000.0/20;
constexpr float DEBUG_REFRESH_RATE = 1000.0/10;

// Styling
constexpr float SCREEN_PADDING_Y = 5;
constexpr float SCREEN_PADDING_X = 5;

// Colours
constexpr auto WHITE = Colour{255, 255, 255, 255};
constexpr auto RED = Colour{255, 0, 0, 255};
constexpr auto GREEN = Colour{0, 255, 0, 255};
constexpr auto BLUE = Colour{0, 0, 255, 255};

    // Game Objects
    constexpr auto SNAKE_HEAD_COLOUR = Colour{64, 209, 90, 255};
    constexpr auto SNAKE_BODY_COLOUR = Colour{130, 209, 66, 255};
    constexpr auto APPLE_COLOUR = Colour{242, 99, 60, 255};

    // UI
    constexpr auto TITLE_TEXT_COLOUR = SDL_Color{255, 255, 255, 255};
    constexpr auto DEBUG_TEXT_COLOUR = SDL_Color{87, 255, 62, 255};
    constexpr auto STATISTICS_TEXT_COLOUR = SDL_Color{62, 184, 209, 255};
