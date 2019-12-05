#include <glm/glm.hpp>

#include "Object.h"

class Sphere : public Object
{
private:
	glm::vec3 centre;
	float radius;
	glm::ivec3 colour;

public:
	Sphere(glm::vec3 _centre, float _radius, glm::ivec3 _colour);

	Intersection rayHit(Ray _ray);
	glm::ivec3 returnColour(glm::vec3 _point);
};
