#include <SDL2/SDL.h>

class App
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

public:
	App(int _winW, int _winH);
	~App();

	bool run();
	void draw();
};
