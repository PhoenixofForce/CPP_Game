#ifndef RENDERING_H
#define RENDERING_H

#include <SDL2/SDL.h>

#include <string>

#include "data/color.h"
#include "data/rect.h"

void fillRect(SDL_Renderer* renderer, const Rect& r, const Color& c);

#endif