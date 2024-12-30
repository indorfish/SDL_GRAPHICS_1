/* A HACK PROGRAM TO DISPLAY A SIMPLE WINDOW IN SDL
 * This one's buggy 'cause the window has no surface attached, and is running on
 * an infinite loop - can't even respond to events.
 */

#include <SDL2/SDL.h>
#define TRUE	     1
#define INIT_FLAG    SDL_INIT_VIDEO

/*
 * main - show me a window!
 * return: 0 for success, 1 for failure?
 */
int main(void)
{
	SDL_Init( INIT_FLAG );

	SDL_Window *winnie;
	winnie = SDL_CreateWindow( "My First Window",
				   SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				   600, 300,
				   SDL_WINDOW_RESIZABLE );
	if (winnie == NULL)
		return (1); /* is this legit? */
	while (TRUE)
		;

	SDL_DestroyWindow( winnie );
	SDL_Quit();

	return (0);
}
