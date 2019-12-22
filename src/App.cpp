#include <iostream>
#include <thread>

#include "App.h"
#include "Scene.h"
#include "Camera.h"

App::App(int _winW, int _winH)
{
	// Initialise SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "Failed to initialise SDL: " << SDL_GetError() << std::endl;
	}

	// Create window
	window = SDL_CreateWindow("GCP Assignment",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		_winW, _winH, SDL_WINDOW_SHOWN);

	if (!window)
	{
		std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
	}

	// Initialise event union
	event = { NULL };
}

App::~App()
{
	// Clean-up: Destroy window and quit SDL
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void App::run(CameraSettings& _cameraSettings)
{
	// Initialise and populate the scene
	Scene scene(glm::ivec3(255, 255, 255), glm::vec3(-1.0f, 1.0f, 0.0f));
	scene.addSphere(glm::ivec3(255, 255, 255), glm::vec3(0.0f, 0.0f, -1.0f), 0.5f);
	scene.addSphere(glm::ivec3(255, 0, 0), glm::vec3(-0.3f, 0.3f, -0.5f), 0.05f);
	scene.addSphere(glm::ivec3(0, 0, 255), glm::vec3(0.3f, -0.1f, -0.5f), 0.1f);
	scene.addSphere(glm::ivec3(0, 0, 0), glm::vec3(1.0f, 0.0f, -1.5f), 0.25f);

	// Initialise camera with the chosen settings and display the scene
	CameraSettings cameraSettings = _cameraSettings;
	Camera camera(window, cameraSettings);
	camera.useOrthogonal(false);
	camera.draw(scene);

	// Wait for the user to quit
	processInput();
}

void App::processInput()
{
	// Loop here until the user presses the esc key or closes the window

	bool quit = false;
	while (!quit)
	{
		if (SDL_WaitEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE) quit = true; break;
			case SDL_QUIT: quit = true; break;
			}
		}
	}
}
