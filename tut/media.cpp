#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Window *gameWindow = NULL;
SDL_Surface *gScreensurface = NULL;
SDL_Surface *grender = NULL;

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to initialize\n");
        success = false;
    }
    else
    {
        gameWindow = SDL_CreateWindow("Maze game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 640, SDL_WINDOW_SHOWN);
        if (gameWindow == NULL)
        {
            printf("Window failed to be created\n");
            success = false;
        }
        else 
        {
            gScreensurface = SDL_GetWindowSurface(gameWindow);
        }
    }
    return success;
}

bool loadMedia()
{
    bool success = true;

    grender = SDL_LoadBMP("img.bmp");
    if (grender == NULL)
    {
        printf("Cannot Load\n");
        success = false;
    }
    return success;
}

void close()
{
    SDL_FreeSurface(grender);
    grender = NULL;

    SDL_DestroyWindow(gameWindow);
    gameWindow = NULL;

    SDL_Quit();

}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( grender, NULL, gScreensurface, NULL );
            //Update the surface
            SDL_UpdateWindowSurface( gameWindow );
            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}