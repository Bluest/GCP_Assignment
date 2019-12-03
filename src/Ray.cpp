#include "Ray.h"
#include "Sphere.h"

Ray::Ray(glm::vec3 _origin, glm::vec3 _direction)
{
	origin = _origin;
	direction = glm::normalize(_direction);
}

bool Ray::hitSphere(Sphere _sphere)
{
	glm::vec3 originToCentre = _sphere.getCentre() - origin;
	float distanceFromCentre = glm::length(originToCentre - glm::dot(originToCentre, direction) * direction);
	return distanceFromCentre < _sphere.getRadius();
}
