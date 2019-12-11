#include "Sphere.h"
#include "Ray.h"
#include "Scene.h"

Sphere::Sphere(glm::ivec3 _colour, glm::vec3 _centre, float _radius)
{
	colour = _colour;
	centre = _centre;
	radius = _radius;
}

Intersection Sphere::rayHit(Ray _ray)
{
	// Distance along the ray to the point closest to the sphere's centre
	float distanceToClosestPoint = _ray.getDistanceTo(centre);

	if (distanceToClosestPoint < 0.0f)
		return { false };

	float distanceFromCentre = glm::length(_ray.getPointAt(distanceToClosestPoint) - centre);

	if (distanceFromCentre > radius)
		return { false };

	float distanceToIntersection = distanceToClosestPoint - sqrt(radius * radius - distanceFromCentre * distanceFromCentre);

	return { true, distanceToIntersection };
}

glm::ivec3 Sphere::returnColour(Scene* _scene, Ray _ray, Intersection _intersection)
{
	glm::vec3 intersectionPoint = _ray.getPointAt(_intersection.distance);
	glm::vec3 normal = glm::normalize(intersectionPoint - centre);

	glm::vec3 direction(intersectionPoint + normal + diffuse());

	glm::vec3 returnColour = colour / 2 + _scene->traceRay(Ray(intersectionPoint, direction)) / 2;
	float specular = (glm::dot(normal, glm::vec3(0.0f, 1.0f, 0.0f)) + 1.0f) / 2;

	//return returnColour;

	return glm::vec3(specular * returnColour.x, specular * returnColour.y, specular * returnColour.z);

	//return colour / 2 + glm::ivec3(63 * (normal.x + 1.0f), 63 * (normal.y + 1.0f), 63 * (normal.z + 1.0f));
}
