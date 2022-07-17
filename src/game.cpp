#include "game.h"
#include <iostream>

const int barSpacingX = 50;
const int barSpacingY = 35;

Game::Game() {
    for(int i = 0; i < 20; i++) {
        bool goesLeft = rnd::random() < 0.5;
        barGenerationX += goesLeft? -barSpacingX: barSpacingX;
        bars.push_back({barGenerationX, 0, 30, 10});
    }
}

void Game::update(long dt) {}

void Game::render(SDL_Renderer* renderer) {
    fillRect(renderer, {playerDrawX, playerDrawHeight, 20, 30}, {0, 255, 0});

    for(int i = 0; i < bars.size(); i++) {
        Rect& bar = bars.at(i);
        bar.y = playerDrawHeight + 30 - (i + 1) * barSpacingY;
        fillRect(renderer, {playerDrawX + bar.x - playerJumpX, bar.y, bar.w, bar.h}, {255, 255, 0});
    }

    for(int i = 0; i < barsBelow.size(); i++) {
         Rect& bar = barsBelow.at(i);
        int distanceToPlayer = barsBelow.size() - i;
        fillRect(renderer, {playerDrawX - 5 + bar.x - playerJumpX, playerDrawHeight + distanceToPlayer * barSpacingY, 30, 10}, {255, 255, 0});
    }

    Rect percentBar{10, 10, 100, 20};
    fillRect(renderer, percentBar, {255, 255, 255});

    float percentage = (float) errors / std::max(1, playerJumpHeight);
    int errorBarWidth = percentage * 96;
    fillRect(renderer, {12, 12, errorBarWidth, 16}, {255, 0, 0}); 

}

// go left
void Game::pressSpace() {
    const Rect& bar = bars.at(0);

   if(moveRight && (bar.x > playerJumpX) || !moveRight && (bar.x < playerJumpX)) {
    playerJumpHeight += 1;
    playerJumpX = bar.x;

    barsBelow.push_back({bar.x, bar.y, bar.w, bar.y});
    barsBelow.erase(barsBelow.begin());

    bars.erase(bars.begin());
    bool goesLeft = rnd::random() < 0.5;
    barGenerationX += goesLeft? -barSpacingX: barSpacingX;
    bars.push_back({barGenerationX, 0, 30, 10});
   } else errors++;
}

// go right
void Game::pressControl() {
    const Rect& bar = bars.at(0);

   if(!(moveRight && (bar.x > playerJumpX) || !moveRight && (bar.x < playerJumpX))) {
    moveRight = !moveRight;
    pressSpace();
   } else errors++;
}