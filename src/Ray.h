#include <glm/glm.hpp>

class Ray
{
private:
	glm::vec3 origin;
	glm::vec3 direction;

	bool hitSphere(glm::vec3 _sphereCentre, float _sphereRadius);

public:
	Ray(glm::vec3 _origin, glm::vec3 _direction);

	glm::vec3 returnColour();
	glm::vec3 getPointAt(float _t);
};
