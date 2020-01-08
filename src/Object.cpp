#include "Object.h"
#include "Scene.h"
#include "Ray.h"

glm::ivec3 Object::getDiffuseColour(glm::vec3& _normal, Intersection& _intersection, Scene* _scene)
{
	// Initialise randomDirection such that it enters the while loop
	glm::vec3 randomDirection = glm::vec3(1.0f, 1.0f, 1.0f);

	// Pick a random point within a unit sphere
	// If the random point is outside of the sphere, try again
	while (glm::length(randomDirection) > 1.0f)
	{
		// Generate random numbers between 0.0f and 1.0f
		randomDirection.x = float(rand()) / RAND_MAX;
		randomDirection.y = float(rand()) / RAND_MAX;
		randomDirection.z = float(rand()) / RAND_MAX;

		// Map the numbers from 0 to 1, to -1 to 1
		randomDirection = 2.0f * randomDirection - glm::vec3(1.0f, 1.0f, 1.0f);
	}

	// Direction for the reflected ray
	glm::vec3 direction(_normal + randomDirection);

	// Call Scene::traceRay recursively until the ray doesn't reflect into a sphere
	// The diffuse colour is equal to half of this object's colour plus half of the reflected ray's colour
	return colour / 2 + _scene->traceRay(Ray(_intersection.point, direction)) / 2;
}
