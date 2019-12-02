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

glm::vec3 Ray::returnColour()
{
	// TODO: Loop through objects in scene
	if (hitSphere(Sphere(glm::vec3(0.0f, 0.0f, 0.0f), 0.5f)))
		return glm::vec3(0.0f, 0.0f, 0.0f);

	return direction * 128.0f + 128.0f;
}

glm::vec3 Ray::getPointAt(float _t)
{
	return origin + _t * direction;
}
