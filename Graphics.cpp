#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include "Particle.hpp"

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

int main(int argc, char** argv){

    SDL_Init(SDL_INIT_EVERYTHING);
    auto window = SDL_CreateWindow("Physics Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event e;

    bool running = true;
    bool movement = false;
    SDL_Rect particle {SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 10, 10};

    // Partícula de ejemplo
    Particle p(20, 30, 0);
    double tMax = 2*p.getInitialVelocity()*sin(p.getAngle())/9.81;
    double deltaTime = tMax/30;

    while (running) {   
        while (SDL_PollEvent(&e)){
            switch (e.type) {
            case SDL_QUIT:
                running = false;
                break;
            
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_SPACE){
                    // Movimiento de la partícula
                }
                break;

            default:
                break;
            }
        }
        

        SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
        SDL_RenderClear(renderer);

        // Partícula
        SDL_SetRenderDrawColor(renderer, 225, 0, 0, 225);
        SDL_RenderFillRect(renderer, &particle);

        SDL_RenderPresent(renderer);
        SDL_Delay(25);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}