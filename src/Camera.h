#include <mutex>

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Ray;
class Scene;

class Camera
{
private:
	SDL_Renderer* renderer;
	glm::ivec2 resolution;
	float aspectRatio;
	int antialiasingSamples;
	int numberOfThreads;
	std::mutex mutex;
	glm::vec3 position;

	Ray createRay(float _x, float _y);
	void setPixelColour(int _x, int _y, glm::ivec3 _colour);

public:
	Camera(SDL_Window* _window, int _resolutionScale, int _antialiasingLevel, int _numberOfThreads, glm::vec3 _position);
	~Camera();

	void drawSegment(Scene _scene, int _startY, int _endY);
	void draw(Scene _scene);
};
