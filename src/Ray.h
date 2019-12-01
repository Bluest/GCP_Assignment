#include <glm/glm.hpp>

class Sphere;

class Ray
{
private:
	glm::vec3 origin;
	glm::vec3 direction;

	bool hitSphere(Sphere _sphere);

public:
	Ray(glm::vec3 _origin, glm::vec3 _direction);

	glm::vec3 returnColour();
	glm::vec3 getPointAt(float _t);
};
