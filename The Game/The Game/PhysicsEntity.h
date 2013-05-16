#ifndef PHYSICSENTITY_H
#define PHYSICSENTITY_H

#include "Entity.h"
#include "PhysicsObject.h"

class PhysicsEntity : public Entity, public PhysicsObject{
public:
	PhysicsEntity();
	PhysicsEntity(const string &filename, int mass);

	void applyPhysics(sf::Time delta);
};

#endif