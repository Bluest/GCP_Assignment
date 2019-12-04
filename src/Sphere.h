#ifndef SPHERE_H
#define SPHERE_H

#include <glm/glm.hpp>

#include "Object.h"

class Sphere
{
private:
	glm::vec3 centre;
	float radius;

public:
	Sphere(glm::vec3 _centre, float _radius);

	Intersection rayHit(Ray _ray);
	glm::ivec3 returnColour(glm::vec3 _point);
};

#endif
