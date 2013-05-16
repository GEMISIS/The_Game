#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "CollidableObject.h"

class Player: public Entity, public CollidableObject{
public:
	Player();
	Player(const std::string &filename);

	void resetVelocity();
	void addVelocity(const sf::Vector2f &amt);
	void move(const sf::Time &delta);

	void collidesWith(const CollidableObject &other);

private:
	//const sf::Vector2f hitboxSize;
	sf::Vector2f velocity;
};

#endif