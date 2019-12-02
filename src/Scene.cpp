#include "Scene.h"
#include "Sphere.h"

void Scene::addSphere(glm::vec3 _centre, float _radius)
{
	spheres.emplace_back(std::make_shared<Sphere>(_centre, _radius));
}
