#include "Ray.h"

Ray::Ray(glm::vec3 _origin, glm::vec3 _direction)
{
	origin = _origin;
	direction = _direction;
}

glm::vec3 Ray::getPointAt(float _t)
{
	return origin + _t * direction;
}