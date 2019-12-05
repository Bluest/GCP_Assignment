#include "Scene.h"
#include "Object.h"
#include "Sphere.h"
#include "Ray.h"

Scene::Scene(glm::ivec3 _backgroundColour)
{
	backgroundColour = _backgroundColour;
}

void Scene::addSphere(glm::vec3 _centre, float _radius, glm::ivec3 _colour)
{
	objects.emplace_back(std::make_shared<Sphere>(_centre, _radius, _colour));
}

glm::ivec3 Scene::traceRay(Ray _ray)
{
	Intersection closest = { false, 0.0f };
	glm::ivec3 colour = backgroundColour;

	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		Intersection intersection = (*it)->rayHit(_ray);

		if (intersection.hit)
		{
			if (intersection.distance < closest.distance || !closest.hit)
			{
				closest = intersection;
				colour = (*it)->returnColour(closest.point);
			}
		}
	}

	return colour;
}
