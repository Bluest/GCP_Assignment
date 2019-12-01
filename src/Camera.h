#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Camera
{
private:
	SDL_Renderer* renderer;

	glm::vec3 position;
	glm::ivec2 resolution;

	void setPixelColour(int _x, int _y, glm::vec3 _colour);

public:
	void init(SDL_Renderer* _renderer, glm::vec3 _position, int _width, int _height);
	void rayTrace();
};
