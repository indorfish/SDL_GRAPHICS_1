/*
 * THIS ONE LETS US QUIT.
 */

#include <SDL2/SDL.h>
#include <stdio.h>

int main(void)
{
	int blue;
	int active = 1;

	SDL_Init( SDL_INIT_VIDEO );

	SDL_Window *winnie;
	SDL_Event eve;

	winnie = SDL_CreateWindow( "I'll let you quit.",
				   SDL_WINDOWPOS_UNDEFINED,
				   SDL_WINDOWPOS_UNDEFINED,
				   1000, 800,
				   SDL_WINDOW_MAXIMIZED );
	while (active)
	{
		while (SDL_PollEvent( &eve ))
		{
			if (eve.type == SDL_QUIT)
			{
				puts("User Quit! Goodbye!\n");
				active = 0;
				break;
			}
		}
	}

	SDL_DestroyWindow( winnie );
	SDL_Quit();

	return (0);
}
