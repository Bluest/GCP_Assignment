#include <list>
#include <memory>

#include <glm/glm.hpp>

class Sphere;

class Scene
{
private:
	std::list<std::shared_ptr<Sphere>> spheres;

public:
	void addSphere(glm::vec3 _centre, float _radius);
};
