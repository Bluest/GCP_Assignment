#include <iostream>
#include <SDL.h>

void init(SDL_Window** _window, SDL_Renderer** _renderer)
{
	const int winW = 640;
	const int winH = 480;

	SDL_Init(SDL_INIT_VIDEO);

	*_window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winW, winH, SDL_WINDOW_SHOWN);
	*_renderer = SDL_CreateRenderer(*_window, -1, SDL_RENDERER_ACCELERATED);
}

int main(int argc, char* argv[])
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	init(&window, &renderer);
	std::cout << "START" << std::endl;

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);

	int posX = 0;
	int posY = 0;
	for (float j = 0.0f; j < 1.0f; j += 0.001f)
	{
		for (float i = 0.0f; i < 1.0f; i += 0.001f)
		{
			int r = static_cast<int>(255 - (256 * j));
			int g = static_cast<int>(255 * i);
			int b = static_cast<int>(256 * j);
			SDL_SetRenderDrawColor(renderer, r, g, b, 255);
			SDL_RenderDrawPoint(renderer, posX, posY);
			posX = static_cast<int>(640 * i);
		}
		posY = static_cast<int>(480 * j);
	}

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT: { quit = true; break; }
			}
		}
		
		SDL_RenderPresent(renderer);
	}

	std::cout << "END" << std::endl;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
