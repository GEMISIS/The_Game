#ifndef BASICWEAPON_H
#define BASICWEAPON_H

#include "Weapon.h"

class BasicWeapon : public Weapon{
public:
	BasicWeapon();
	BasicWeapon(float bullSpeed);
	void fire(sf::Vector2f pos, float rot);

private:
	float bullSpeed;

};

#endif