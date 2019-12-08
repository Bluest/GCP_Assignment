#include <vector>
#include <thread>

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Ray;
class Scene;

struct CameraSettings
{
	glm::vec3 position;
	int resolutionScale;
	int antialiasingLevel;
	int numberOfThreads;
};

class Camera
{
private:
	CameraSettings settings;
	SDL_Renderer* renderer;
	glm::ivec2 resolution;
	std::vector<std::vector<glm::ivec3>> screen;
	float aspectRatio;

	Ray createRay(float _x, float _y);
	void drawSegment(Scene _scene, int _startY, int _endY);
	void drawScreen();

public:
	Camera(SDL_Window* _window, CameraSettings _settings);
	~Camera();

	void draw(Scene _scene);
	void move(glm::vec3 _distance);
};
