#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>

class Ray;

struct Intersection
{
	bool hit;
	glm::vec3 point;
	float distance;
};

class Object
{
public:
	virtual Intersection rayHit(Ray _ray) = 0;
};

#endif
