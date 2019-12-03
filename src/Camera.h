#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Ray;
class Scene;

class Camera
{
private:
	SDL_Renderer* renderer;
	glm::vec3 position;
	glm::ivec2 resolution;

	Ray createRay(int _x, int _y);
	void setPixelColour(int _x, int _y, glm::ivec3 _colour);

public:
	Camera(SDL_Window* _window, glm::vec3 _position);
	~Camera();

	void draw(Scene _scene);
};
