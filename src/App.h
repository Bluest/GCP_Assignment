#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class App
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

public:
	App(int _winW, int _winH);
	~App();

	void setPixelColour(int _x, int _y, glm::vec3 _colour);
	void draw();
	bool quit();
};
