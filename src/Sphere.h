#include <glm/glm.hpp>

#include "Object.h"

class Sphere : public Object
{
private:
	glm::vec3 centre;
	float radius;

public:
	Sphere(glm::ivec3 _colour, glm::vec3 _centre, float _radius);

	Intersection rayHit(Ray _ray);
	glm::ivec3 returnColour(Scene* _scene, Ray _ray, Intersection _intersection);
};
