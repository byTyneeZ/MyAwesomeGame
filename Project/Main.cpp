#include "SDL/Include/SDL.h"
#include "SDL/Include/SDL_image.h"
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
	int velX = 1, velY = 1;
	bool mup = false, mdown = false, mleft = false, mright = false, mshoot = false;

	/*struct Bullet {
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
	};*/

	/*IMG_Init(IMG_INIT_PNG);

	SDL_Surface *image = IMG_Load("background.png");
	SDL_Texture *image_texture = SDL_CreateTextureFromSurface(blockRender, image);
	SDL_FreeSurface(image);

	SDL_Rect texture_destination;
	texture_destination.x = 0;
	texture_destination.y = 0;
	texture_destination.w = 1000;
	texture_destination.h = 563;

	SDL_RenderCopy(blockRender, image_texture, NULL, &texture_destination);*/

	
	if (SDL_Init(SDL_INIT_VIDEO) < 0){ }
	else
	{
		window = SDL_CreateWindow("Red Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL) {}

		else
		{
			blockRender = SDL_CreateRenderer(window, -1, 0);
			while (!quit)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_KEYUP)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							mup = false;
							break;
						case SDLK_DOWN:
							mdown = false;
							break;
						case SDLK_RIGHT:
							mright = false;
							break;
						case SDLK_LEFT:
							mleft = false;
							break;
						case SDLK_SPACE:
							mshoot = false;
							break;
						}
					}
					if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							mup = true;
							break;
						case SDLK_DOWN:
							mdown = true;
							break;
						case SDLK_RIGHT:
							mright = true;
							break;
						case SDLK_LEFT:
							mleft = true;
							break;
						case SDLK_SPACE:
							mshoot = true;
							break;
						case SDLK_ESCAPE:
							quit = true;
							break;
						}
					}
				}
				if (rect.x == 0) { mleft = false; }
				if (rect.x == 970) { mright = false; }
				if (rect.y == 0) { mup = false; }
				if (rect.y == 493) { mdown = false; }

				if (mleft == true) {
					rect.x -= velX;
					SDL_Delay(1);
				}
				if (mright == true) {
					rect.x += velX;
					SDL_Delay(1);
				}
				if (mup == true) {
					rect.y -= velY;
					SDL_Delay(1);
				}
				if (mdown == true) {
					rect.y += velY;
					SDL_Delay(1);
				}
				if (mshoot == true) {
					blast.y = rect.y + 30;
					blast.x = rect.x + 30 + velX;
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
			
	}
	/*SDL_DestroyTexture(image_texture);
	IMG_Quit();*/
	SDL_DestroyRenderer(blockRender);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}