#include <vector>
#include <list>
#include <thread>

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Ray;
class Scene;

class Camera
{
private:
	SDL_Renderer* renderer;
	glm::ivec2 resolution;
	std::vector<std::vector<glm::ivec3>> screen;
	float aspectRatio;
	int antialiasingSamples;
	int numberOfThreads;
	glm::vec3 position;

	Ray createRay(float _x, float _y);
	void drawSegment(Scene _scene, int _startY, int _endY);
	void drawScreen();

public:
	Camera(SDL_Window* _window, int _resolutionScale, int _antialiasingLevel, int _numberOfThreads, glm::vec3 _position);
	~Camera();

	void draw(Scene _scene);
	void move(glm::vec3 _distance);
};
