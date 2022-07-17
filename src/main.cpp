#include <iostream>
#include <SDL2/SDL.h>
#include <string>

#include "game.h"
#include "rendering.h"
#include "util/random.h"
#include "data/color.h"
#include "data/rect.h"
#include "util/time.h"

const int WIDTH = 800, HEIGHT = 600;
const std::string title = "Hello Window";

void render(SDL_Renderer* renderer);

int main(int argc, char* argv[]) {
    std::cout.precision(17);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window {
        SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI)
    };

    if(window == NULL) {
        std::cout << "Window couldnt be created: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer* renderer{SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)};

    SDL_Event event;

    Game game{};

    long lastUpdate = getCurrentTime();
    long lastUpdateNano = getCurrentTimeNS();
    while(true) {
        long dt = getCurrentTime() - lastUpdate;
        long dtNano = getCurrentTimeNS() - lastUpdateNano;
        lastUpdate = getCurrentTime();
        lastUpdateNano = getCurrentTimeNS();

        std::cout << dt << "\n";
        long fps = dtNano != 0? 1000000000 / dtNano: 0;

        std::string newTitle{title + " (" + std::to_string(fps) + ")"};
        SDL_SetWindowTitle(window, newTitle.c_str());

        bool quit = false;
        while(SDL_PollEvent((&event))) {
            if(event.type == SDL_QUIT) {
                quit = true;
                break;
            }

            if(event.type == SDL_KEYDOWN) {
                int key{ event.key.keysym.sym};
                std::cout << "kd " << key << " " << (char)key << std::endl;
            }
        }
        if(quit) break;

        game.update(dt);
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        render(renderer);
        game.render(renderer);

        SDL_RenderPresent(renderer);

        sleep(lastUpdate + (1000/60) - getCurrentTime());
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void render(SDL_Renderer* renderer) {
    fillRect(renderer, {20, 20, 40, 40}, {0, 255, 0});
}