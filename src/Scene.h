#include <list>

#include <glm/glm.hpp>

#include "Sphere.h"

class Ray;

class Scene
{
private:
	glm::ivec3 backgroundColour;
	std::list<Sphere> spheres;

public:
	Scene(glm::ivec3 _backgroundColour);

	void addSphere(glm::vec3 _centre, float _radius);
	glm::ivec3 traceRay(Ray _ray);
};
