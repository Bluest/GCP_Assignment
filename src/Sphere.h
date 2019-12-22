#include <glm/glm.hpp>

#include "Object.h"

class Sphere : public Object
{
public:
	Sphere(glm::ivec3& _colour, glm::vec3& _centre, float _radius);

	Intersection rayHit(Ray& _ray);
	glm::ivec3 returnColour(Intersection& _intersection, Scene* _scene);

private:
	glm::vec3 centre;
	float radius;
};
