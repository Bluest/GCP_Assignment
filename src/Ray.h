#include <glm/glm.hpp>

class Ray
{
public:
	Ray(glm::vec3& _origin, glm::vec3& _direction);

	float getDistanceTo(glm::vec3& _point);
	glm::vec3 getPointAt(float _distance);

private:
	glm::vec3 origin;
	glm::vec3 direction;
};
