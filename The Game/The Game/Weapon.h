#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>

class Weapon{
public:
	virtual void fire(sf::Vector2f pos, float rot) = 0;
};

#endif