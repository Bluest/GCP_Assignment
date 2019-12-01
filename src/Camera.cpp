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

void Camera::setPixelColour(int _x, int _y, glm::vec3 _colour)
{
	SDL_SetRenderDrawColor(renderer, _colour.r, _colour.g, _colour.b, 255);
	SDL_RenderDrawPoint(renderer, _x, _y);
}

void Camera::draw()
{
	for (int y = 0; y < resolution.y; y++)
	{
		for (int x = 0; x < resolution.x; x++)
		{
			// i ranges from -1 (at x = 0) to 1 (at x = winW)
			float i = 2 * float(x) / resolution.x - 1.0f;

			// j ranges from -1 (at y = 0) to 1 (at y = winH)
			float j = 2 * float(y) / resolution.y - 1.0f;

			Ray ray(position, glm::vec3(i, j, 1.0f));
			setPixelColour(x, y, ray.returnColour());
		}
	}

	SDL_RenderPresent(renderer);
}
