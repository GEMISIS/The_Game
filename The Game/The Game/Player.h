#ifndef PLAYER_H
#define PLAYER_H

#include "StoredSprite.h"
#include "CollidableObject.h"
#include "Weapon.h"

class Player : public CollidableObject, public sf::Drawable{
public:
	static const float MOVE_SPEED;
	static const sf::Vector2f HITBOX_SIZE;

	Player();
	Player(const std::string &filename);
	~Player();

	void updatePlayerLogic(const sf::Time &delta);
	void calcSmoothInput();

	void resetVelocity();
	void addVelocity(const sf::Vector2f &amt);
	void move(const sf::Time &delta);
	void setPosition(float x, float y);
	void setPosition(const Vector2f &position);

	void collidesWith(const CollidableObject &other);
private:
	StoredSprite sprite;
	sf::Vector2f velocity;
	bool rFirst;
	bool lFirst;
	bool uFirst;
	bool dFirst;
	Weapon* weapon;
	bool weaponOnCD;
	float sinceLastFired;
	float weaponCD;

	void draw(RenderTarget &target, RenderStates states) const;
	void init();
};

#endif