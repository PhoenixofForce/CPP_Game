#include "game.h"

void Game::update(long dt) {

}

void Game::render(SDL_Renderer* renderer) {
    fillRect(renderer, {80, 80, 30, 20}, {255, 255, 0});
}
