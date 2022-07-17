#include "rendering.h"

void fillRect(SDL_Renderer* renderer, const Rect& r, const Color& c) {
    SDL_Rect rect{r.x, r.y, r.w, r.h};

    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(renderer, &rect);
}