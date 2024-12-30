
#include "SDL.h"
#include <iostream>

using namespace std;

int main( int argc, char *argv[] )
{
	SDL_Window *my_win;

	SDL_Init( SDL_INIT_EVERYTHING );
	
	my_win = SDL_CreateWindow(
		  "My FIRST WINDOW yayy!!!",
	  	  SDL_WINDOWPOS_UNDEFINED,
		  SDL_WINDOWPOS_UNDEFINED,
		  500, 300,
		  SDL_WINDOW_RESIZABLE );
	
	if ( my_win == NULL ) {
		cout << "Error creating window.\n" << SDL_GetError();
	}

	SDL_Delay( 5000 );
	SDL_DestroyWindow( my_win );

	SDL_Quit();

	return 0;
}
