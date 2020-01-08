#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>

class Ray;
class Scene;

// Struct containing information about an intersection
struct Intersection
{
	bool hit;
	float distance;
	glm::vec3 point;
};

class Object
{
public:
	// Determines whether a ray hits the object, and returns information on the intersection
	virtual Intersection rayHit(Ray& _ray) = 0;

	// Returns the colour of the object at _intersection
	virtual glm::ivec3 returnColour(Intersection& _intersection, Scene* _scene) = 0;

protected:
	glm::ivec3 colour;

	// Returns the diffuse colour of the intersected point by reflecting the ray randomly off of microfacets
	glm::ivec3 getDiffuseColour(glm::vec3& _normal, Intersection& _intersection, Scene* _scene);
};

#endif
