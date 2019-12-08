#include <ctime>
#include "Object.h"

glm::vec3 Object::diffuse()
{
	glm::vec3 randomDirection;

	do
	{
		randomDirection.x = float(rand()) / (RAND_MAX + 1);
		randomDirection.y = float(rand()) / (RAND_MAX + 1);
		randomDirection.z = float(rand()) / (RAND_MAX + 1);
		randomDirection = 2.0f * randomDirection - glm::vec3(1.0f, 1.0f, 1.0f);
	} while (glm::length(randomDirection) > 1.0f);

	return randomDirection;
}
