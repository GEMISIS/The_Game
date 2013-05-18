#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "PhysicsObject.h"
#include "StoredSprite.h"
#include "Path.h"

class Bullet : public PhysicsObject, public sf::Drawable{
public:
	Bullet();
	Bullet(sf::Vector2f pos, float mass);

	void setStoredSprite(StoredSprite sprite);
	void addPath(Path* path);

	void applyPhysics(const sf::Time &delta);

private:
	StoredSprite sprite;
	std::vector<Path*> paths;

	void draw(RenderTarget &target, RenderStates states) const;
};

#endif