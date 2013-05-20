#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Path.h"
#include "Entity.h"

class Bullet : public Entity{
public:
	Bullet();
	Bullet(sf::Vector2f pos, float mass);

	void setStoredTexture(const string &filename);
	void addPath(Path* path);

	void kill();
	void collidesWith(const CollidableObject &other);
	void applyPhysics(const sf::Time &delta);

private:
	std::vector<Path*> paths;
};

#endif