#include <vector>

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Ray;
class Scene;

struct CameraSettings
{
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	int resolutionScale = 1;
	int antialiasingLevel = 1;
	unsigned int numberOfThreads = 1;
};

class Camera
{
public:
	Camera(SDL_Window* _window, CameraSettings& _settings);
	~Camera();

	void useOrthogonal(bool _value);
	void move(glm::vec3& _distance);
	void draw(Scene& _scene);

private:
	CameraSettings settings;
	SDL_Renderer* renderer;
	glm::ivec2 resolution;
	std::vector<std::vector<glm::ivec3>> screen;
	float aspectRatio;
	bool orthogonalView;
	
	void drawSegment(Scene& _scene, int _startY, int _endY);
	Ray createRay(float _x, float _y);
	void drawScreen();
};
