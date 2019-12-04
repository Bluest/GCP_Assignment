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
	Intersection closest = { INFINITY, glm::vec3() };
	glm::ivec3 colour = backgroundColour;

	for (auto it = spheres.begin(); it != spheres.end(); it++)
	{
		Intersection i = _ray.hitSphere(*it);

		if (i.distance >= 0.0f)
		{
			if (i.distance < closest.distance)
			{
				closest = i;

				glm::vec3 normal = glm::normalize(closest.position - it->getCentre());
				colour = glm::ivec3(127 * (normal.x + 1.0f), 127 * (normal.y + 1.0f), 127 * (normal.z + 1.0f));
			}
		}
	}

	return colour;
}
