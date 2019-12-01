#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "Camera.h"

class App
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	Camera camera;

public:
	App(int _winW, int _winH);
	~App();

	void run();
	void draw();
};
