#include "Camera.h"
#include "Scene.h"
#include "Ray.h"

Camera::Camera(SDL_Window* _window, glm::vec3 _position)
{
	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	int w, h;
	SDL_GetWindowSize(_window, &w, &h);
	resolution = glm::ivec2(w, h);

	if (resolution.x > resolution.y)
		aspectRatio = float(resolution.x) / float(resolution.y);
	else
		aspectRatio = float(resolution.y) / float(resolution.x);
	
	position = _position;
}

Camera::~Camera()
{
	SDL_DestroyRenderer(renderer);
}

Ray Camera::createRay(int _x, int _y)
{
	float i, j;

	if (resolution.x > resolution.y)
	{
		i = 2 * aspectRatio * float(_x) / resolution.x - aspectRatio;
		j = 2 * float(_y) / resolution.y - 1.0f;
	}
	else
	{
		i = 2 * float(_x) / resolution.x - 1.0f;
		j = 2 * aspectRatio * float(_y) / resolution.y - aspectRatio;
	}

	return Ray(position, glm::vec3(i, j, -1.0f));
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
			setPixelColour(x, y, _scene.traceRay(createRay(x, resolution.y - y - 1)));
		}
	}

	SDL_RenderPresent(renderer);
}
