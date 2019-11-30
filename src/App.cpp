#include "App.h"

App::App(int _winW, int _winH)
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("GCP Assignment", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _winW, _winH, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	event = { NULL };
}

App::~App()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void App::setPixelColour(int _x, int _y, glm::vec3 _colour)
{
	SDL_SetRenderDrawColor(renderer, _colour.r, _colour.g, _colour.b, 255);
	SDL_RenderDrawPoint(renderer, _x, _y);
}

void App::draw()
{
	SDL_RenderPresent(renderer);
}

bool App::quit()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE) return true; break;
		case SDL_QUIT: return true;
		}
	}

	return false;
}
