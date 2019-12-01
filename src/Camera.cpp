#include "Camera.h"
#include "Ray.h"

void Camera::init(SDL_Window* _window, glm::vec3 _position)
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

void Camera::traceRay(int _x, int _y)
{
	// i ranges from -1 (at _x = 0) to 1 (at _x = resolution.x)
	float i = 2 * float(_x) / resolution.x - 1.0f;

	// j ranges from -1 (at _y = 0) to 1 (at _y = resolution.y)
	float j = 2 * float(_y) / resolution.y - 1.0f;

	Ray ray(position, glm::vec3(i, j, 1.0f));

	glm::vec3 colour = ray.returnColour();
	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, 255);
	SDL_RenderDrawPoint(renderer, _x, _y);
}

void Camera::draw()
{
	for (int y = 0; y < resolution.y; y++)
	{
		for (int x = 0; x < resolution.x; x++)
		{
			traceRay(x, y);
		}
	}

	SDL_RenderPresent(renderer);
}
