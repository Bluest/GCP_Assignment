#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Camera
{
private:
	SDL_Renderer* renderer;

	glm::vec3 position;
	glm::ivec2 resolution;

	void traceRay(int _x, int _y);

public:
	void init(SDL_Window* _window, glm::vec3 _position);
	~Camera();

	void draw();
};
