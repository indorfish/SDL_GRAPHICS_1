/* BONE-HEADED COLOR UPDATE WINDOW */	

#include <SDL2/SDL.h>
#define FAILURE 	1
#define DELAY		20
#define RED		60
#define GREEN		70

/**
 * main - update color of window.
 * Return: 0 for success.
 */
int main(void)
{
	int blue;

	SDL_Init( SDL_INIT_VIDEO );

	SDL_Window *winnie;
	SDL_Surface *surfie;

	winnie = SDL_CreateWindow( "Magical Color-Changing Window",
				   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				   1000, 800,
				   SDL_WINDOW_BORDERLESS );
	if (winnie == NULL)
		return (FAILURE);
	surfie = SDL_GetWindowSurface( winnie );
	if (surfie == NULL)
		return (FAILURE);

	for (blue = 0 ; blue < 256 ; ++blue)
	{
		SDL_FillRect( surfie, NULL,
			      SDL_MapRGB( surfie->format, RED, GREEN, blue )
			    );
		SDL_UpdateWindowSurface( winnie );
		SDL_Delay( DELAY );
	}
	SDL_Delay( 1000*DELAY );

	SDL_FreeSurface( surfie );
	SDL_DestroyWindow( winnie );
	SDL_Quit();

	return (0);
}
