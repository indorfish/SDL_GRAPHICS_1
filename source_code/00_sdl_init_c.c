/* BASIC INITIALIZATION AND SHUTDOWN SDL PROGRAM */

#include <SDL2/SDL.h>

int main(void)
{
	/* initialize SDL */
	SDL_Init( SDL_INIT_EVERYTHING );
	/* do stuff here */
	/* shut down SDL */
	SDL_Quit();

	return 0;
}
