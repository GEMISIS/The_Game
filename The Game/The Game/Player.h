#ifndef PLAYER_H
#define PLAYER_H

#include "StoredSprite.h"
#include "CollidableObject.h"

class Player : public CollidableObject, public sf::Drawable{
public:
	static const float MOVE_SPEED;
	static const sf::Vector2f HITBOX_SIZE;

	Player();
	Player(const std::string &filename);

	void resetVelocity();
	void addVelocity(const sf::Vector2f &amt);
	void move(const sf::Time &delta);
	void setPosition(float x, float y);
	void setPosition(const Vector2f &position);

	void collidesWith(const CollidableObject &other);
private:
	StoredSprite sprite;
	sf::Vector2f velocity;

	void draw(RenderTarget &target, RenderStates states) const;
};

#endif