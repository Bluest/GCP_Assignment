#include <vector>
#include <memory>

#include <glm/glm.hpp>

class Object;
class Ray;

class Scene
{
public:
	Scene(glm::ivec3& _backgroundColour, glm::vec3& _lightPosition);

	glm::vec3 getLightPosition();
	void addSphere(glm::ivec3& _colour, glm::vec3& _centre, float _radius);
	glm::ivec3 traceRay(Ray& _ray);
	bool castShadow(Object* _object, Ray& _ray);

private:
	glm::ivec3 backgroundColour;
	glm::vec3 lightPosition;
	std::vector<std::shared_ptr<Object>> objects;
};
