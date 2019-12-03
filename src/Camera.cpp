#include "Camera.h"
#include "Scene.h"
#include "Ray.h"

Camera::Camera(SDL_Window* _window, glm::vec3 _position)
{
	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	position = _position;

	int w, h;
	SDL_GetWindowSize(_window, &w, &h);
	resolution = glm::ivec2(w, h);
}

Camera::~Camera()
{
	SDL_DestroyRenderer(renderer);
}

Ray Camera::createRay(int _x, int _y)
{
	// i ranges from -1 (at _x = 0) to 1 (at _x = resolution.x)
	// i ranges from -_x/_y (at _x = 0)
	float i = 2 * float(_x) / resolution.x - 1.0f;

	// j ranges from -1 (at _y = 0) to 1 (at _y = resolution.y)
	float j = 2 * float(_y) / resolution.y - 1.0f;

	Ray ray(position, glm::vec3(i, j, 1.0f));

	return ray;
}

void Camera::setPixelColour(int _x, int _y, glm::ivec3 _colour)
{
	SDL_SetRenderDrawColor(renderer, _colour.r, _colour.g, _colour.b, 255);
	SDL_RenderDrawPoint(renderer, _x, _y);
}

void Camera::draw(Scene _scene)
{
	for (int y = 0; y < resolution.y; y++)
	{
		for (int x = 0; x < resolution.x; x++)
		{
			setPixelColour(x, y, _scene.traceRay(createRay(x, y)));
		}
	}

	SDL_RenderPresent(renderer);
}
