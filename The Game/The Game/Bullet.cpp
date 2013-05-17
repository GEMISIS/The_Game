#include "Bullet.h"

#include <iostream>

Bullet::Bullet(){}
Bullet::Bullet(sf::Vector2f pos, float mass) : PhysicsObject(mass), path(mass, sf::Vector2f(0,50), 0.2f){
	sprite.setImage("res/bullet.png");
	sprite.setPosition(pos);
}
//Bullet::~Bullet(){delete path;}

//public

void Bullet::applyPhysics(const sf::Time &delta){
	applyForce(path.calcForceVector());
	sf::Vector2f vel = calcPhysics(delta);
	std::cout << vel.y << std::endl;
	sf::Vector2f amt(vel.x*delta.asSeconds(),vel.y*delta.asSeconds());
	sprite.move(amt);
}

//private

void Bullet::draw (RenderTarget &target, RenderStates states) const{target.draw(sprite,states);}