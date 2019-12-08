#include <vector>
#include <memory>

#include <glm/glm.hpp>

class Object;
class Ray;

class Scene
{
private:
	glm::ivec3 backgroundColour;
	std::vector<std::shared_ptr<Object>> objects;

public:
	Scene(glm::ivec3 _backgroundColour);

	void addSphere(glm::ivec3 _colour, glm::vec3 _centre, float _radius);
	glm::ivec3 traceRay(Ray _ray);
};
