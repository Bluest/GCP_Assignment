#include <list>

#include <glm/glm.hpp>

#include "Sphere.h"

class Ray;

class Scene
{
private:
	std::list<Sphere> spheres;

public:
	void addSphere(glm::vec3 _centre, float _radius);
	glm::ivec3 traceRay(Ray _ray);
};
