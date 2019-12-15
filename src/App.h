#include <SDL2/SDL.h>
#include <glm/glm.hpp>

struct CameraSettings;

class App
{
private:
	SDL_Window* window;
	SDL_Event event;

	bool processInput();

public:
	App(int _winW, int _winH);
	~App();

	void run(CameraSettings& _cameraSettings);
};
