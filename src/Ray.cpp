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

glm::vec3 Ray::returnColour()
{
	return direction * 128.0f + 128.0f;
}
