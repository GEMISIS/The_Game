#include "Bullet.h"

#include <iostream>

Bullet::Bullet(){}
Bullet::Bullet(sf::Vector2f pos, float mass) : PhysicsObject(mass), path(mass, sf::Vector2f(10,10), 15){
	sprite.setImage("res/bullet.png");
	sprite.setPosition(pos);
}
//Bullet::~Bullet(){delete path;}

//public

void Bullet::applyPhysics(const sf::Time &delta){
	applyForce(path.calcForceVector());
	sf::Vector2f vel = calcPhysics(delta);
	sf::Vector2f amt(vel.x*delta.asSeconds(),vel.y*delta.asSeconds());
	sprite.move(amt);
}

//private

void Bullet::draw (RenderTarget &target, RenderStates states) const{target.draw(sprite,states);}