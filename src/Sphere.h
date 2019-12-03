#ifndef SPHERE_H
#define SPHERE_H

#include <glm/glm.hpp>

class Sphere
{
private:
	glm::vec3 centre;
	float radius;

public:
	Sphere(glm::vec3 _centre, float _radius);

	glm::vec3 getCentre();
	float getRadius();
};

#endif
