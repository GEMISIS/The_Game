#include "Bullet.h"

#include <iostream>

Bullet::Bullet(){}
Bullet::Bullet(sf::Vector2f pos, float mass){
	this->mass = mass;
	setPosition(pos);
	hitbox.left = pos.x;
	hitbox.top = pos.y;
}

//public

void Bullet::setStoredTexture(const string &filename){
	StoredSprite::setStoredTexture(filename);
	sf::Vector2u size = getTexture()->getSize();
	hitbox.width = (float)size.x;
	hitbox.height = (float)size.y;
}
void Bullet::addPath(Path* path){
	paths.push_back(path);
}

void Bullet::applyPhysics(const sf::Time &delta){
	for(unsigned int i = 0; i < paths.size(); i++){
		paths[i]->calcForceVector(*this,delta);
	}

	sf::Vector2f dis = calcPhysics(delta);
	move(dis);
	hitbox.left += dis.x;
	hitbox.top += dis.y;
}
void Bullet::collidesWith(const CollidableObject &other){kill();}
void Bullet::kill(){slateForRemoval();}

//private

