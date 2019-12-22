#include "Sphere.h"
#include "Ray.h"
#include "Scene.h"

Sphere::Sphere(glm::ivec3& _colour, glm::vec3& _centre, float _radius)
{
	colour = _colour;
	centre = _centre;
	radius = _radius;
}

Intersection Sphere::rayHit(Ray& _ray)
{
	// Distance along the ray to the point closest to the sphere's centre
	float distanceToClosestPoint = _ray.getDistanceTo(centre);

	// If the point is behind the ray's origin, no hit
	if (distanceToClosestPoint < 0.0f)
		return { false };

	// Calculate distance from the point to the centre of the sphere
	float distanceFromCentre = glm::length(_ray.getPointAt(distanceToClosestPoint) - centre);

	// If the distance is greater than the sphere's radius, no hit
	if (distanceFromCentre > radius)
		return { false };

	// Otherwise, we have a hit!

	// Distance along the ray to the surface of the sphere, the point of intersection
	float distanceToIntersection = distanceToClosestPoint - sqrt(radius * radius - distanceFromCentre * distanceFromCentre);

	// Return the intersection
	return { true, distanceToIntersection, _ray.getPointAt(distanceToIntersection) };
}

glm::ivec3 Sphere::returnColour(Intersection& _intersection, Scene* _scene)
{
	glm::vec3 normal = glm::normalize(_intersection.point - centre);

	glm::ivec3 diffuseColour = getDiffuseColour(normal, _intersection, _scene);

	// Direction from this point to the scene's light
	glm::vec3 lightDirection = glm::normalize(_scene->getLightPosition() - _intersection.point);

	// The dot product of the normal and light direction, mapped to 0.0f to 1.0f
	// This value will be 1.0f when the normal directly faces the light, and 0.0f when the normal faces directly away
	float specular = (glm::dot(normal, lightDirection) + 1.0f) / 2;

	// If this point is in shadow, reduce the specular value by a quarter
	if (_scene->castShadow(this, Ray(_intersection.point, lightDirection)))
	{
		specular *= 0.75f;
	}

	return glm::ivec3(specular * diffuseColour.x, specular * diffuseColour.y, specular * diffuseColour.z);
}
