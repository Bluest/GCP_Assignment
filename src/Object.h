#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>

class Ray;

struct Intersection
{
	bool hit;
	float distance;
	glm::vec3 point;
};

class Object
{
public:
	virtual Intersection rayHit(Ray _ray) = 0;
	virtual glm::ivec3 returnColour(glm::vec3 _point) = 0;
};

#endif