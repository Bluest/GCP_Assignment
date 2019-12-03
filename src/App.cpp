#include "App.h"
#include "Scene.h"
#include "Camera.h"

App::App(int _winW, int _winH)
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("GCP Assignment",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		_winW, _winH, SDL_WINDOW_SHOWN);
	event = { NULL };
}

App::~App()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void App::processInput()
{
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

void App::run()
{
	Scene scene;
	scene.addSphere(glm::vec3(0.0f, 0.0f, 0.0f), 0.5f);
	scene.addSphere(glm::vec3(1.0f, 0.0f, 0.5f), 0.25f);

	Camera camera(window, glm::vec3(0.0f, 0.0f, -1.0f));
	camera.draw(scene);

	processInput();
}
