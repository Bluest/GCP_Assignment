#include "Scene.h"
#include "Sphere.h"
#include "Ray.h"

void Scene::addSphere(glm::vec3 _centre, float _radius)
{
	spheres.emplace_back(Sphere(_centre, _radius));
}

glm::ivec3 Scene::traceRay(Ray _ray)
{
	// TODO: Depth testing
	for (auto it = spheres.begin(); it != spheres.end(); it++)
	{
		Intersection i = _ray.hitSphere(*it);

		if (i.distance >= 0.0f)
		{
			glm::vec3 normal = glm::normalize(i.position - it->getCentre());
			return glm::ivec3(255 * abs(normal.x), 255 * abs(normal.y), 255 * abs(normal.z));
		}
	}

	return glm::ivec3(0, 0, 0);
}
