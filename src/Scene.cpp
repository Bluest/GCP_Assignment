#include "Scene.h"
#include "Sphere.h"
#include "Ray.h"

void Scene::addSphere(glm::vec3 _centre, float _radius)
{
	spheres.emplace_back(Sphere(_centre, _radius));
}

glm::ivec3 Scene::traceRay(Ray _ray)
{
	for (auto it = spheres.begin(); it != spheres.end(); it++)
	{
		if (_ray.hitSphere(*it))
			return glm::ivec3(0, 0, 0);
	}

	return glm::ivec3(0, 255, 0);
}
