#include "App.h"

App::App(int _winW, int _winH)
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("GCP Assignment", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _winW, _winH, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	event = { NULL };

	camera.init(renderer, glm::vec3(0.0f, 0.0f, -1.0f), _winW, _winH);
}

App::~App()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void App::run()
{
	camera.rayTrace();
}

void App::draw()
{
	SDL_RenderPresent(renderer);

	bool quit = false;
	while (!quit)
	{
		if (SDL_WaitEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE) quit = true; break;
			case SDL_QUIT: quit = true;
			}
		}
	}
}
