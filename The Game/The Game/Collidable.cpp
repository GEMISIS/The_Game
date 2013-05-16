#include "Collidable.h"

CollidableObject::CollidableObject(){}
CollidableObject::CollidableObject(const sf::FloatRect &hitbox){this->hitbox = hitbox;}

bool CollidableObject::collides(const CollidableObject &other){
	//Checks to see if two collideable objects collide with each other
	return hitbox.intersects(other.hitbox);
}