#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "rendering.h"
#include "data/rect.h"
#include "data/color.h"

class Game {

public: 
    void update(long dt);
    void render(SDL_Renderer* renderer);

};

#endif