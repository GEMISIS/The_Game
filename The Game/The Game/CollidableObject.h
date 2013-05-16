#ifndef COLLIDABLEOBJECT_H
#define COLLIDABLEOBJECT_H

#include <SFML/Graphics.hpp>

class CollidableObject{
public:
	CollidableObject();
	CollidableObject(const sf::FloatRect &hitbox);

	bool collides(const CollidableObject &other);
	virtual void collidesWith(const CollidableObject &other) = 0;
	
protected:
	sf::FloatRect hitbox;
};

#endif