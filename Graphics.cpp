#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include "Particle.hpp"
#include "vector"
using namespace std;

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

int main(int argc, char** argv){

    SDL_Init(SDL_INIT_EVERYTHING);
    auto window = SDL_CreateWindow("Physics Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event e;

    int x0 = 150;
    int y0 = 600;
    bool running = true;
    bool movement = false;
    SDL_Rect particle {x0, y0, 10, 10};   
    

    vector<Particle> particles;
    particles.push_back(Particle(30, 40, 0));
    particles.push_back(Particle(30, 25, 0));
    particles.push_back(Particle(30, 70, 0));
    vector<SDL_Rect> particleRects;

    #pragma omp parallel for
    for (int i = 0; i < particles.size(); i++){
       particles[i].setAngle(particles[i].getAngle()*M_PI/180); 
       particles[i].setTrajectory(particles[i].defaultTrajectory(60));
       SDL_Rect pr {100, (600 + (int)particles[i].getInitialPositionY()), 10, 10};
       particleRects.push_back(pr);
       particles[i].calculateTrajectory(6);
    }

    while (running) {   
        while (SDL_PollEvent(&e)){
            switch (e.type) {
            case SDL_QUIT:
                running = false;
                break;
            
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_SPACE){
                    movement = true;
                }
                break;

            default:
                break;
            }

            if (movement){

                for (int i = 0; i < particles.size(); ++i) {
                    auto& p = particles[i];
                    auto& rect = particleRects[i];
                    auto t = particles[i].getTrajectory();

                    for (const auto& entry : t) {
                        particleRects[i].x = x0 + ((entry.second.first) * 10);
                        particleRects[i].y = y0 -+ ((entry.second.second) * 10);

                        cout << "X: " << particleRects[i].x << " Y: " << particleRects[i].y <<endl;

                        SDL_SetRenderDrawColor(renderer, 0, 225, 0, 225);
                        SDL_RenderFillRect(renderer, &particleRects[i]);
                        
                        SDL_RenderPresent(renderer);
                        SDL_Delay(25);
                    }
                }
    
                movement = false;
            }
        
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(25);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}