#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 640;

int main(int argc, char *argv[])
{
	SDL_Window* window = NULL; /* SDL window we'd be using */

	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("SDL could not be initialized! Error: %s\n", SDL_GetError());
	else
	{
		window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		
		//Get window surface
		screenSurface = SDL_GetWindowSurface( window );

		//Fill the surface white
		SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

		//Update the surface
		SDL_UpdateWindowSurface( window );	
		
        // Keep Window up
		SDL_Event e; 
		bool quit = false; 
		while( quit == false )
		{
			while( SDL_PollEvent( &e ) )
			{
				if( e.type == SDL_QUIT )
					quit = true; 
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
