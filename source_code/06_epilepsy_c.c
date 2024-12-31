/*
 * GRADUALLY VARY THE COLOR OF THE SCREEN, ALLOW USER TO QUIT
 * MORE EFFICIENT VERSION
 */

#include <SDL2/SDL.h>
#include <stdio.h>

#define COLOR_DEPTH	256
#define TRUE		1
#define FALSE		0
#define DELAY		60

int main(void)
{
	int red, grn, blu, i;
	int active = TRUE;

	SDL_Init( SDL_INIT_VIDEO );

	SDL_Window *winnie;
	SDL_Surface *surfie;
	SDL_Event eve;

	winnie = SDL_CreateWindow( "Amazing Color Changing Window!!!",
				    SDL_WINDOWPOS_UNDEFINED,
				    SDL_WINDOWPOS_UNDEFINED,
				    1000, 700,
				    SDL_WINDOW_BORDERLESS );
	surfie = SDL_GetWindowSurface( winnie );
	if (winnie == NULL)
		exit (1);
	if (surfie == NULL)
		exit (1);

	while (active)
	{
		/* Generally, treat r,g,b as functions of i */
		for (i = 0; i < (3 * COLOR_DEPTH); ++i)
		{
			/* what if I put the event loop inside the color iteration? */
			while (SDL_PollEvent( &eve ))
			{
				if (eve.type == SDL_QUIT)
				{
					active = FALSE;
					break;
				}
			}
			red = i % COLOR_DEPTH;
			grn = (4*i + 1) % COLOR_DEPTH;
			blu = (i*i + 3*i) % COLOR_DEPTH;
			SDL_FillRect( surfie,
				      NULL,
				      SDL_MapRGB( surfie->format,
					          red, grn, blu));
			SDL_UpdateWindowSurface( winnie );
			/* printf("r:%d g:%d b:%d\n", red, grn, blu); */
		}
	}


	SDL_DestroyWindow( winnie );
	SDL_Quit();

	return 0;
}
