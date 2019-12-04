#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere(glm::vec3 _centre, float _radius)
{
	centre = _centre;
	radius = _radius;
}

Intersection Sphere::rayHit(Ray _ray)
{
	float distanceToClosestPoint = _ray.getDistanceTo(centre);

	if (distanceToClosestPoint < 0.0f)
		return { false };

	float distanceFromCentre = glm::length(_ray.getPointAt(distanceToClosestPoint) - centre);

	if (distanceFromCentre > radius)
		return { false };

	float distanceToIntersection = distanceToClosestPoint - sqrt(radius * radius - distanceFromCentre * distanceFromCentre);

	return { true, _ray.getPointAt(distanceToIntersection), distanceToIntersection };
}

glm::ivec3 Sphere::returnColour(glm::vec3 _point)
{
	glm::vec3 normal = glm::normalize(_point - centre);
	return glm::ivec3(127 * (normal.x + 1.0f), 127 * (normal.y + 1.0f), 127 * (normal.z + 1.0f));
}
