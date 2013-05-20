#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "PhysicsObject.h"
#include "StoredSprite.h"
#include "Path.h"
#include "CollidableObject.h"
#include "Killable.h"

class Bullet : public PhysicsObject, public sf::Drawable, public CollidableObject, public Killable{
public:
	Bullet();
	Bullet(sf::Vector2f pos, float mass);

	void setTexture(const string &filename);
	void addPath(Path* path);

	void applyPhysics(const sf::Time &delta);
	void collidesWith(const CollidableObject &other);
	void kill();

private:
	StoredSprite sprite;
	std::vector<Path*> paths;

	void draw(RenderTarget &target, RenderStates states) const;
};

#endif