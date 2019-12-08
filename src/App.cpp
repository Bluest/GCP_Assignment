#include <thread>

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

bool App::processInput()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE) return false; break;
		case SDL_QUIT: return false;
		}
	}

	return true;
}

void App::run()
{
	Scene scene(glm::ivec3(0, 0, 0));
	scene.addSphere(glm::vec3(0.0f, 0.0f, -1.0f), 0.5f, glm::ivec3(255, 255, 255));
	scene.addSphere(glm::vec3(-0.7f, 0.7f, -1.0f), 0.1f, glm::ivec3(255, 0, 0));
	scene.addSphere(glm::vec3(1.0f, 0.0f, -1.5f), 0.25f, glm::ivec3(0, 255, 0));
	scene.addSphere(glm::vec3(0.3f, -0.1f, -0.5f), 0.1f, glm::ivec3(0, 0, 255));

	CameraSettings cameraSettings = { glm::vec3(0.0f, 0.0f, 0.0f), 1, 1, std::thread::hardware_concurrency() };
	Camera camera(window, cameraSettings);
	camera.draw(scene);

	while (processInput())
	{

	}
}
