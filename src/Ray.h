#include <glm/glm.hpp>

class Sphere;

struct Intersection
{
	float distance;
	glm::vec3 position;
};

class Ray
{
private:
	glm::vec3 origin;
	glm::vec3 direction;

public:
	Ray(glm::vec3 _origin, glm::vec3 _direction);

	Intersection hitSphere(Sphere _sphere);
};
