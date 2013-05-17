#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(){mass = 0;}
PhysicsObject::PhysicsObject(float mass){this->mass = mass;}

//public

float PhysicsObject::getMass(){return mass;}

void PhysicsObject::applyForce(const sf::Vector2f &force){
	//Adds a force to the physics object
	//This must be called every game loop
	//(All forces are removed from the object once physics are calculated)
	forces.push(force);
}

//protected

sf::Vector2f PhysicsObject::calcPhysics(const sf::Time &delta){
	//Calculates the change in velocity over time delta
	//Returns the new velocity in units/second
	sf::Vector2f acc(0,0);
	while(!forces.empty()){
		acc += forces.top()/mass;
		forces.pop();
	}
	velocity.x += acc.x*delta.asSeconds();
	velocity.y += acc.y*delta.asSeconds();
	return velocity;
}