#include "SDL/Include/SDL.h"
#pragma comment(lib,"SDL/Libraries/SDL2.lib")
#pragma comment(lib,"SDL/Libraries/SDL2main.lib")

int main(int argc, char* args[]) 
{
	SDL_Window* window = NULL;
	SDL_Renderer* blockRender = NULL;
	SDL_Event e;
	SDL_Rect rect;
	rect.w = 80;
	rect.h = 70;
	rect.x = 250;
	rect.y = 250;
	SDL_Rect blast;
	blast.w = 30;
	blast.h = 10;
	blast.x = -150;
	blast.y = -150;
	const int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 680;
	bool quit = false;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
	}
	else
	{
		window = SDL_CreateWindow("Red Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{

		}
		else
		{
			blockRender = SDL_CreateRenderer(window, -1, 0);
			while (rect.x <= 1280 && rect.x >= 0 && rect.y >= 0 && rect.y <= 680) {
				
				//Renders
				SDL_SetRenderDrawColor(blockRender, 0, 123, 255, 255);
				SDL_RenderClear(blockRender);
				SDL_SetRenderDrawColor(blockRender, 255, 0, 0, 255);
				SDL_RenderFillRect(blockRender, &rect);
				SDL_SetRenderDrawColor(blockRender, 0, 255, 0, 255);
				SDL_RenderFillRect(blockRender, &blast);
				SDL_RenderPresent(blockRender);
				break;
			}
			//QUIT
			while (!quit) {

				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						quit = true;
						break;
					}
				}
			}
		}
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
	}
}