#include <glm/glm.hpp>

class Ray
{
private:
	glm::vec3 origin;
	glm::vec3 direction;

public:
	Ray(glm::vec3 _origin, glm::vec3 _direction);

	glm::vec3 getPointAt(float _t);
};
