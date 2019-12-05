#include <list>
#include <memory>

#include <glm/glm.hpp>

class Object;
class Ray;

class Scene
{
private:
	glm::ivec3 backgroundColour;
	std::list<std::shared_ptr<Object>> objects;

public:
	Scene(glm::ivec3 _backgroundColour);

	void addSphere(glm::vec3 _centre, float _radius, glm::ivec3 _colour);
	glm::ivec3 traceRay(Ray _ray);
};
