#include <iostream>
#include <list>
#include <thread>

#include <glm/ext.hpp>

#include "Camera.h"
#include "Scene.h"
#include "Ray.h"

Camera::Camera(SDL_Window* _window, CameraSettings& _settings)
{
	// Initialise camera settings
	settings = _settings;

	// Create renderer
	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (!renderer)
	{
		std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
	}

	// Set renderer's logical size based on the user-specified resolution scale
	int w, h;
	SDL_GetWindowSize(_window, &w, &h);
	resolution = glm::ivec2(w / settings.resolutionScale, h / settings.resolutionScale);
	SDL_RenderSetLogicalSize(renderer, resolution.x, resolution.y);

	screen.resize(resolution.y, std::vector<glm::ivec3>(resolution.x));

	// Calculate aspect ratio, either horizontally or vertically (whichever is longer, such that aspectRatio >= 1)
	// If resolution.x and resolution.y are equal, the aspectRatio will be 1
	if (resolution.x > resolution.y)
	{
		aspectRatio = float(resolution.x) / float(resolution.y);
	}
	else
	{
		aspectRatio = float(resolution.y) / float(resolution.x);
	}

	// Do not use orthogonal view by default
	orthogonalView = false;
}

Camera::~Camera()
{
	// Clean-up: Destroy renderer
	SDL_DestroyRenderer(renderer);
}

void Camera::useOrthogonal(bool _value)
{
	orthogonalView = _value;
}

void Camera::move(glm::vec3& _distance)
{
	settings.position += _distance;
}

void Camera::draw(Scene& _scene)
{
	if (settings.numberOfThreads <= 1)
	{
		// If the user chooses to use 1 or fewer threads, draw the whole screen as one segment
		drawSegment(_scene, 0, resolution.y);
	}
	else
	{
		// Otherwise, divide the screen by the number of threads, into rows for each thread to draw
		int segmentSize = resolution.y / settings.numberOfThreads;

		// Create the list of threads and populate it with numberOfThreads threads, which each draw a segment of the scene
		std::list<std::thread> threads;
		for (unsigned int i = 0; i < settings.numberOfThreads; i++)
		{
			threads.emplace_back(std::thread(&Camera::drawSegment, this, _scene, i * segmentSize, (i + 1) * segmentSize));
		}

		// Wait for all threads to finish before continuing
		for (auto it = threads.begin(); it != threads.end(); it++)
		{
			it->join();
		}
	}

	// Present the scene to the window, and log the amount of milliseconds taken
	drawScreen();
	std::cout << "Time taken: " << SDL_GetTicks() << "ms" << std::endl;
}

void Camera::drawSegment(Scene& _scene, int _startY, int _endY)
{
	// For each pixel in this segment...
	for (int y = _startY; y < _endY; y++)
	{
		for (int x = 0; x < resolution.x; x++)
		{
			// Trace multiple rays per pixel and calculate the average colour
			glm::ivec3 averageColour;

			for (float sampleX = 0; sampleX < settings.antialiasingLevel; sampleX++)
			{
				// Set this ray's sub-pixel direction in the x-axis
				float offsetX = sampleX / settings.antialiasingLevel;

				for (float sampleY = 0; sampleY < settings.antialiasingLevel; sampleY++)
				{
					// Set this ray's sub-pixel direction in the y-axis
					float offsetY = sampleY / settings.antialiasingLevel;

					// Create a ray from the camera in this direction
					Ray ray = createRay(x + offsetX, y + offsetY);
					// Trace the ray and add the returned colour to the stored average
					averageColour += _scene.traceRay(ray);
				}
			}

			averageColour /= settings.antialiasingLevel * settings.antialiasingLevel;
			screen[resolution.y - y - 1][x] = averageColour;
		}
	}
}

Ray Camera::createRay(float _x, float _y)
{
	if (!orthogonalView)
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
	else
	{
		glm::vec3 offset = glm::vec3(0.0f, 0.0f, 0.0f);

		if (resolution.x > resolution.y)
		{
			offset.x = 2 * aspectRatio * _x / resolution.x - aspectRatio;
			offset.y = 2 * _y / resolution.y - 1.0f;
		}
		else
		{
			offset.x = 2 * _x / resolution.x - 1.0f;
			offset.y = 2 * aspectRatio * _y / resolution.y - aspectRatio;
		}

		return Ray(settings.position + offset, glm::vec3(0.0f, 0.0f, -1.0f));
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
