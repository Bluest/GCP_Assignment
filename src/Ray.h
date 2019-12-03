#include <glm/glm.hpp>

class Sphere;

class Ray
{
private:
	glm::vec3 origin;
	glm::vec3 direction;

public:
	Ray(glm::vec3 _origin, glm::vec3 _direction);

	bool hitSphere(Sphere _sphere);
};
