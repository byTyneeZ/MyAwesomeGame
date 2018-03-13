#include "SDL/Include/SDL.h"
#include "SDL_Image/Include/SDL_image.h"
#pragma comment(lib,"SDL/Libraries/SDL2.lib")
#pragma comment(lib,"SDL/Libraries/SDL2main.lib")
#pragma comment(lib,"SDL_Image/Lib/SDL2_image.lib")


int main(int argc, char* args[]) 
{
	SDL_Window* window = NULL;
	SDL_Renderer* blockRender = NULL;
	SDL_Event e;
	SDL_Rect rect;
	rect.w = 30;
	rect.h = 70;
	rect.x = 50;
	rect.y = 250;

	SDL_Rect blast;
	blast.w = 30;
	blast.h = 10;
	blast.x = -150;
	blast.y = -150;

	const int SCREEN_WIDTH = 1000, SCREEN_HEIGHT = 563;
	bool quit = false;
	bool alive = true;

	struct Bullet{
		bool shooting;
	SDL_Rect bullet;
	};

	struct Enemy {
		SDL_Rect collision;
		bool render;
	};

	struct Boss {
		SDL_Rect boss;
		int live;
	};

	IMG_Init(IMG_INIT_PNG);

	SDL_Surface *image = IMG_Load("background.png");
	SDL_Texture *image_texture = SDL_CreateTextureFromSurface(blockRender, image);
	SDL_FreeSurface(image);

	SDL_Rect texture_destination;
	texture_destination.x = 0;
	texture_destination.y = 0;
	texture_destination.w = 1000;
	texture_destination.h = 563;

	SDL_RenderCopy(blockRender, image_texture, NULL, &texture_destination);

	
	
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
			while (!quit) {
					while (SDL_PollEvent(&e))
					{
						if (e.type == SDL_QUIT) {
							quit = true;
							break;
						}
						switch (e.type)
						{
						case SDL_QUIT:
							quit = true;
							break;
						case SDL_KEYDOWN:
							switch(e.key.keysym.sym)
							{
							case SDLK_UP:
								rect.y -= 10;
								break;
							case SDLK_DOWN:
								rect.y += 10;
								break;
							case SDLK_RIGHT:
								rect.x += 10;
								break;
							case SDLK_LEFT:
								rect.x -= 10;
								break;
							case SDLK_SPACE:
								blast.x = rect.x + 30;
								blast.y = rect.y + 30;
								blast.x++;
								break;
							case SDLK_ESCAPE:
								quit = true;
								break;
							}
						}
					}

				//Renders
				SDL_SetRenderDrawColor(blockRender, 0, 0, 255, 255);
				SDL_RenderClear(blockRender);
				SDL_SetRenderDrawColor(blockRender, 255, 0, 0, 255);
				SDL_RenderFillRect(blockRender, &rect);
				SDL_SetRenderDrawColor(blockRender, 0, 255, 0, 255);
				SDL_RenderFillRect(blockRender, &blast);
				SDL_RenderPresent(blockRender);
				
			}
			
		}

		SDL_DestroyTexture(image_texture);
		IMG_Quit();
		SDL_DestroyRenderer(blockRender);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
	}
}