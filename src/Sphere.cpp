#include "Sphere.h"

Sphere::Sphere(glm::vec3 _centre, float _radius)
{
	centre = _centre;
	radius = _radius;
}

glm::vec3 Sphere::getCentre()
{
	return centre;
}

float Sphere::getRadius()
{
	return radius;
}
