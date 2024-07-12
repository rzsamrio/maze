#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>


SDL_Window *gWindow = NULL;
SDL_Surface *gSurface = NULL;
SDL_Surface *currSurface = NULL;
SDL_Renderer *gRenderer = NULL;

enum keyspress
{
    KEY_DEFAULT,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_TOTAL
};

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not initialise Game, Failed with %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 640, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Could not initialise window, Failed with %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer = NULL)
            {
                printf("Could not initialise renderer, Failed with %s\n", SDL_GetError());
                success = false;
            }
            else {/* Set Renderer features */}
            gSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}