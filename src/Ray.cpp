#include "Ray.h"

Ray::Ray(glm::vec3& _origin, glm::vec3& _direction)
{
	origin = _origin;
	direction = glm::normalize(_direction);
}

float Ray::getDistanceTo(glm::vec3& _point)
{
	return glm::dot(_point - origin, direction);
}

glm::vec3 Ray::getPointAt(float _distance)
{
	return origin + _distance * direction;
}
