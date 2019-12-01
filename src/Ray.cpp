#include "Ray.h"

Ray::Ray(glm::vec3 _origin, glm::vec3 _direction)
{
	origin = _origin;
	direction = glm::normalize(_direction);
}

bool Ray::hitSphere(glm::vec3 _sphereCentre, float _sphereRadius)
{
	glm::vec3 originToCentre = _sphereCentre - origin;
	float distanceFromCentre = glm::length(originToCentre - glm::dot(originToCentre, direction) * direction);
	return distanceFromCentre < _sphereRadius;
}

glm::vec3 Ray::returnColour()
{
	if (hitSphere(glm::vec3(0.0f, 0.0f, 0.0f), 0.5f))
		return glm::vec3(0.0f, 0.0f, 0.0f);

	return direction * 128.0f + 128.0f;
}

glm::vec3 Ray::getPointAt(float _t)
{
	return origin + _t * direction;
}
