#include "Scene.h"
#include "Object.h"
#include "Sphere.h"
#include "Ray.h"

Scene::Scene(glm::ivec3& _backgroundColour, glm::vec3& _lightPosition)
{
	backgroundColour = _backgroundColour;
	lightPosition = _lightPosition;
}

glm::vec3 Scene::getLightPosition()
{
	return lightPosition;
}

void Scene::addSphere(glm::ivec3& _colour, glm::vec3& _centre, float _radius)
{
	// Create a sphere with the passed parameters and add it to the objects list
	objects.emplace_back(std::make_shared<Sphere>(_colour, _centre, _radius));
}

glm::ivec3 Scene::traceRay(Ray& _ray)
{
	Intersection closest = { false };
	int closestIndex;
	glm::ivec3 colour = backgroundColour;

	for (size_t i = 0; i < objects.size(); i++)
	{
		Intersection intersection = objects[i]->rayHit(_ray);

		if (intersection.hit)
		{
			// If this intersection is closer than the previous closest, or if it's the first
			if (intersection.distance < closest.distance || !closest.hit)
			{
				// Store the index of this object, as it is new closest
				closestIndex = i;
				closest = intersection;
			}
		}
	}

	// If an object was hit, get its colour
	if (closest.hit)
	{
		colour = objects[closestIndex]->returnColour(closest, this);
	}

	// Then return the final colour
	return colour;
}

bool Scene::castShadow(Object* _object, Ray& _ray)
{
	// Check each object in the scene
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		// If this object is _object, skip it
		// This way, the passed _object does not cast a shadow on itself
		if (it->get() != _object)
		{
			// If the ray hits any object, there is a shadow
			if ((*it)->rayHit(_ray).hit)
			{
				return true;
			}
		}
	}

	// The ray did not hit any objects, there is no shadow
	return false;
}
