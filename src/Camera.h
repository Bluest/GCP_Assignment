#include <memory>

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Scene;

class Camera
{
private:
	SDL_Renderer* renderer;
	std::shared_ptr<Scene> scene;
	glm::vec3 position;
	glm::ivec2 resolution;

	void traceRay(int _x, int _y);

public:
	Camera(SDL_Window* _window, std::shared_ptr<Scene> _scene, glm::vec3 _position);
	~Camera();

	void draw();
};
