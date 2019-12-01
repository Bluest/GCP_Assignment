#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "Camera.h"

class App
{
private:
	SDL_Window* window;
	SDL_Event event;

	Camera camera;

	void processInput();

public:
	App(int _winW, int _winH);
	~App();

	void run();
};
