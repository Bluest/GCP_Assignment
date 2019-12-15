#include "Scene.h"
#include "Object.h"
#include "Sphere.h"
#include "Ray.h"

Scene::Scene(glm::ivec3& _backgroundColour)
{
	backgroundColour = _backgroundColour;
}

void Scene::addSphere(glm::ivec3& _colour, glm::vec3& _centre, float _radius)
{
	objects.emplace_back(std::make_shared<Sphere>(_colour, _centre, _radius));
}

glm::ivec3 Scene::traceRay(Ray& _ray)
{
	Intersection closest = { false, 0.0f };
	int objectIndex;
	glm::ivec3 colour = backgroundColour;

	for (size_t i = 0; i < objects.size(); i++)
	{
		Intersection intersection = objects[i]->rayHit(_ray);

		if (intersection.hit)
		{
			if (intersection.distance < closest.distance || !closest.hit)
			{
				objectIndex = i;
				closest = intersection;
			}
		}
	}

	if (closest.hit)
		colour = objects[objectIndex]->returnColour(this, _ray, closest);

	return colour;
}
