#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>

#include "util/random.h"
#include "rendering.h"
#include "data/rect.h"
#include "data/color.h"

class Game {

int playerDrawX{400};
int playerDrawHeight{500};
int playerJumpX{0};
int playerJumpHeight{0};
int errors{0};

int barGenerationX{0};

std::vector<Rect> bars{};
std::vector<Rect> barsBelow{{50, 0, 30, 10}, {0, 0, 30, 10}};

bool moveRight{false};

public: 
    Game();

    void update(long dt);
    void render(SDL_Renderer* renderer);
    
    void pressSpace();
    void pressControl();

};

#endif