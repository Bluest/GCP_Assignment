#include <list>

#include "Camera.h"
#include "Scene.h"
#include "Ray.h"

Camera::Camera(SDL_Window* _window, CameraSettings _settings)
{
	settings = _settings;

	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	int w, h;
	SDL_GetWindowSize(_window, &w, &h);
	resolution = glm::ivec2(w / settings.resolutionScale, h / settings.resolutionScale);
	SDL_RenderSetLogicalSize(renderer, resolution.x, resolution.y);

	screen.resize(resolution.y, std::vector<glm::ivec3>(resolution.x));

	if (resolution.x > resolution.y)
		aspectRatio = float(resolution.x) / float(resolution.y);
	else
		aspectRatio = float(resolution.y) / float(resolution.x);


}

Camera::~Camera()
{
	SDL_DestroyRenderer(renderer);
}

Ray Camera::createRay(float _x, float _y)
{
	float i, j;

	if (resolution.x > resolution.y)
	{
		i = 2 * aspectRatio * _x / resolution.x - aspectRatio;
		j = 2 * _y / resolution.y - 1.0f;
	}
	else
	{
		i = 2 * _x / resolution.x - 1.0f;
		j = 2 * aspectRatio * _y / resolution.y - aspectRatio;
	}

	return Ray(settings.position, glm::vec3(i, j, -1.0f));
}

void Camera::drawSegment(Scene _scene, int _startY, int _endY)
{
	for (int y = _startY; y < _endY; y++)
	{
		for (int x = 0; x < resolution.x; x++)
		{
			glm::ivec3 averageColour;

			for (float sampleX = 0; sampleX < settings.antialiasingLevel; sampleX++)
			{
				float offsetX = sampleX / settings.antialiasingLevel;

				for (float sampleY = 0; sampleY < settings.antialiasingLevel; sampleY++)
				{
					float offsetY = sampleY / settings.antialiasingLevel;

					Ray ray = createRay(x + offsetX, y + offsetY);
					averageColour += _scene.traceRay(ray);
				}
			}

			averageColour /= settings.antialiasingLevel * settings.antialiasingLevel;
			screen[resolution.y - y - 1][x] = averageColour;
		}
	}
}

void Camera::drawScreen()
{
	for (size_t y = 0; y < screen.size(); y++)
	{
		for (size_t x = 0; x < screen[y].size(); x++)
		{
			glm::ivec3 pixel = screen[y][x];
			SDL_SetRenderDrawColor(renderer, pixel.r, pixel.g, pixel.b, 255);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}

	SDL_RenderPresent(renderer);
}

void Camera::draw(Scene _scene)
{
	if (settings.numberOfThreads <= 1)
	{
		drawSegment(_scene, 0, resolution.y);
	}
	else
	{
		int segmentSize = resolution.y / settings.numberOfThreads;

		std::list<std::thread> threads;

		for (unsigned int i = 0; i < settings.numberOfThreads; i++)
		{
			threads.emplace_back(std::thread(&Camera::drawSegment, this, _scene, i * segmentSize, (i + 1) * segmentSize));
		}

		// Ask Leigh if I'm launching and joining these threads correctly
		// And actually just general feedback with how everything's structured, or what I should add
		// Is hardware_concurrency() the correct amount of maximum threads?
		for (auto it = threads.begin(); it != threads.end(); it++)
		{
			it->join();
		}
	}

	drawScreen();
	printf("Time taken: %ims\n", SDL_GetTicks());
}

void Camera::move(glm::vec3 _distance)
{
	settings.position += _distance;
}
