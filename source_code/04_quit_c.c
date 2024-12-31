/*
 * GRADUALLY VARY THE COLOR OF THE SCREEN, ALLOW USER TO QUIT
 */

#include <SDL2/SDL.h>
#include <stdio.h>

#define COLOR_DEPTH	256
#define TRUE		1
#define FALSE		0
#define DELAY		60

int main(void)
{
	int red, grn, blu;
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
		while (SDL_PollEvent( &eve ))
		{
			if (eve.type == SDL_QUIT)
			{
				active = FALSE;
				break;
			}
		}
		for (red = 0; red < COLOR_DEPTH; ++red)
		{
			for (grn = 0; grn < COLOR_DEPTH; ++grn)
			{
				for (blu = 0; blu < COLOR_DEPTH; ++blu)
				{
					SDL_FillRect( surfie,
						      NULL,
						      SDL_MapRGB( surfie->format,
							          red, grn, blu ));
					SDL_UpdateWindowSurface( winnie );
					/* for debugging */
					printf("r:%d g:%d b:%d\n", red, grn, blu);
				}
			}
		}
	}


	SDL_DestroyWindow( winnie );
	SDL_Quit();

	return 0;
}
