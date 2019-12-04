#include "Scene.h"
#include "Sphere.h"
#include "Ray.h"

Scene::Scene(glm::ivec3 _backgroundColour)
{
	backgroundColour = _backgroundColour;
}

void Scene::addSphere(glm::vec3 _centre, float _radius)
{
	spheres.emplace_back(Sphere(_centre, _radius));
}

glm::ivec3 Scene::traceRay(Ray _ray)
{
	Intersection closest = { false };
	glm::ivec3 colour = backgroundColour;

	for (auto it = spheres.begin(); it != spheres.end(); it++)
	{
		Intersection intersection = it->rayHit(_ray);

		if (intersection.hit)
		{
			if (!closest.hit)
			{
				closest = intersection;
				colour = it->returnColour(closest.point);
			}
			else if (intersection.distance < closest.distance)
			{
				closest = intersection;
				colour = it->returnColour(closest.point);
			}
		}
	}

	return colour;
}
