#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

SDL_Window *gameWindow = NULL;
SDL_Surface *gScreensurface = NULL;
SDL_Surface *currentSurface = NULL;
SDL_Surface *grender = NULL;

// Declare an enumeration to avoid using const int declarations. Each element is given values 0..n
enum keys
{
	KEY_DEFAULT,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_TOTAL
};
SDL_Surface *keypressSurface[KEY_TOTAL];

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

SDL_Surface *loadSurface(std::string path)
{
	SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Load Image Failed\n");
	}
	return loadedSurface;
}

bool loadMedia()
{
	bool success = true;

	keypressSurface[KEY_DEFAULT] = loadSurface("def.bmp");
	if (keypressSurface[KEY_DEFAULT] == NULL)
	{
		std::cout<< "Failed to load default" <<std::endl;
		success = false;
	}

	keypressSurface[KEY_UP] = loadSurface("up.bmp");
	if (keypressSurface[KEY_UP] == NULL)
	{
		std::cout<< "Failed to load up" <<std::endl;
		success = false;
	}

	keypressSurface[KEY_DOWN] = loadSurface("down.bmp");
	if (keypressSurface[KEY_DOWN] == NULL)
	{
		std::cout<< "Failed to load down" <<std::endl;
		success = false;
	}

	keypressSurface[KEY_LEFT] = loadSurface("left.bmp");
	if (keypressSurface[KEY_LEFT] == NULL)
	{
		std::cout<< "Failed to load left" <<std::endl;
		success = false;
	}

	keypressSurface[KEY_RIGHT] = loadSurface("right.bmp");
	if (keypressSurface[KEY_RIGHT] == NULL)
	{
		std::cout<< "Failed to load right" <<std::endl;
		success = false;
	}
	return success;
}

void close()
{
	for (int i = 0; i < KEY_TOTAL; i++)
	{
		SDL_FreeSurface(keypressSurface[i]);
		keypressSurface[i] = NULL;
	}

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
