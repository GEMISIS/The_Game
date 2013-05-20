#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "StoredSprite.h"
#include "Killable.h"
#include "CollidableObject.h"
#include "PhysicsObject.h"

class Entity : public Killable, public CollidableObject, public PhysicsObject, public StoredSprite{
public:
	Entity();

	virtual void kill() = 0;
	virtual void collidesWith(const CollidableObject &other) = 0;
	virtual void applyPhysics(const sf::Time &delta) = 0;
};


#endif