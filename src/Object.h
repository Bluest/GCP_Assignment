#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>

class Ray;
class Scene;

struct Intersection
{
	bool hit;
	float distance;
};

class Object
{
protected:
	glm::ivec3 colour;

	glm::vec3 diffuse();

public:
	virtual Intersection rayHit(Ray& _ray) = 0;
	virtual glm::ivec3 returnColour(Scene* _scene, Ray& _ray, Intersection& _intersection) = 0;
};

#endif
