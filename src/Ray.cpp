#include "Ray.h"

Ray::Ray(glm::vec3& _origin, glm::vec3& _direction)
{
	// Construct ray
	origin = _origin;
	direction = glm::normalize(_direction);
}

float Ray::getDistanceTo(glm::vec3& _point)
{
	// Get the amount of units along the ray to reach _point, or the point on the ray closest to it
	return glm::dot(_point - origin, direction);
}

glm::vec3 Ray::getPointAt(float _distance)
{
	// Get the 3D coordinates of the point at _distance units along the ray
	return origin + _distance * direction;
}
