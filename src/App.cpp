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

bool App::run()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT: return false;
		}
	}

	return true;
}

void App::draw()
{
	SDL_RenderPresent(renderer);
}
