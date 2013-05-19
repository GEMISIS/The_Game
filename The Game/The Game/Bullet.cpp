#include "Bullet.h"

#include <iostream>

Bullet::Bullet(){}
Bullet::Bullet(sf::Vector2f pos, float mass) : PhysicsObject(mass){
	sprite.setPosition(pos);
	hitbox.left = pos.x;
	hitbox.top = pos.y;
}

//public

void Bullet::setTexture(const string &filename){
	sprite.setImage(filename);
	sf::Vector2u size = sprite.getTexture()->getSize();
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
	sprite.move(dis);
	hitbox.left += dis.x;
	hitbox.top += dis.y;
}
void Bullet::collidesWith(const CollidableObject &other){}

//private

void Bullet::draw (RenderTarget &target, RenderStates states) const{target.draw(sprite,states);}