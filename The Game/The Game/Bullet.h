#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "StoredSprite.h"
#include "Path.h"
#include "ImpulsePath.h"

class Bullet : public PhysicsObject, public sf::Drawable{
public:
	Bullet();
	Bullet(sf::Vector2f pos, float mass);
	//~Bullet();

	void applyPhysics(const sf::Time &delta);

private:
	StoredSprite sprite;
	ImpulsePath path;

	void draw(RenderTarget &target, RenderStates states) const;
};

#endif