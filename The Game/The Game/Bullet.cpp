#include "Bullet.h"

#include <iostream>

Bullet::Bullet(){}
Bullet::Bullet(sf::Vector2f pos, float mass) : PhysicsObject(mass){
	sprite.setImage("res/bullet.png");
	sprite.setPosition(pos);
}

//public

void Bullet::setStoredSprite(StoredSprite sprite){
	this->sprite = sprite;
}
void Bullet::addPath(Path* path){
	paths.push_back(path);
}

void Bullet::applyPhysics(const sf::Time &delta){
	for(unsigned int i = 0; i < paths.size(); i++){
		paths[i]->calcForceVector(*this,delta);
	}

	sprite.move(calcPhysics(delta));
}

//private

void Bullet::draw (RenderTarget &target, RenderStates states) const{target.draw(sprite,states);}