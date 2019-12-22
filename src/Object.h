#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>

class Ray;
class Scene;

struct Intersection
{
	bool hit;
	float distance;
	glm::vec3 point;
};

class Object
{
protected:
	glm::ivec3 colour;

	glm::ivec3 getDiffuseColour(glm::vec3& _normal, Intersection& _intersection, Scene* _scene);

public:
	// Determines whether or not a ray hits the object, and returns information on the intersection
	virtual Intersection rayHit(Ray& _ray) = 0;

	// Returns the colour of the object at _intersection
	virtual glm::ivec3 returnColour(Intersection& _intersection, Scene* _scene) = 0;
};

#endif
