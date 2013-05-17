#include "Bullet.h"

#include <iostream>

Bullet::Bullet(){}
Bullet::Bullet(sf::Vector2f pos, float mass) : PhysicsObject(mass){
	sprite.setImage("res/bullet.png");
	sprite.setPosition(pos);
	applyInstantImpulse(sf::Vector2f(0,100));
}
//Bullet::~Bullet(){delete path;}

//public

void Bullet::applyPhysics(const sf::Time &delta){
	sf::Vector2f vel = calcPhysics(delta);
	sprite.move(sf::Vector2f(vel.x*delta.asSeconds(),vel.y*delta.asSeconds()));
}

//private

void Bullet::draw (RenderTarget &target, RenderStates states) const{target.draw(sprite,states);}