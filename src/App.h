#include <memory>

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Scene;

class App
{
private:
	SDL_Window* window;
	std::shared_ptr<Scene> scene;
	SDL_Event event;

	void processInput();

public:
	App(int _winW, int _winH);
	~App();

	void run();
};
