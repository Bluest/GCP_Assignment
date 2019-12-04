#include "Ray.h"
#include "Sphere.h"

Ray::Ray(glm::vec3 _origin, glm::vec3 _direction)
{
	origin = _origin;
	direction = glm::normalize(_direction);
}

glm::vec3 Ray::getPointAt(float _t)
{
	return origin + _t * direction;
}

Intersection Ray::hitSphere(Sphere _sphere)
{
	glm::vec3 rayOriginToSphereCentre = _sphere.getCentre() - origin;
	float t = glm::dot(rayOriginToSphereCentre, direction);

	if (t < 0.0f)
		return { -1.0f, glm::vec3() };

	float distanceFromCentre = glm::length(rayOriginToSphereCentre - t * direction);

	if (distanceFromCentre > _sphere.getRadius())
		return { -1.0f, glm::vec3() };

	float x = sqrt(_sphere.getRadius() * _sphere.getRadius() - distanceFromCentre * distanceFromCentre);

	return { t, getPointAt(t - x) };
}
