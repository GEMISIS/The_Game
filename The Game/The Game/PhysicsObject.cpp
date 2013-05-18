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
void PhysicsObject::applyInstantImpulse(const sf::Vector2f &deltaM){
	//Applies an instant change in velocity
	velocity += deltaM/mass;
}

//protected

sf::Vector2f PhysicsObject::calcPhysics(const sf::Time &delta){
	//Calculates the displacement of the object over time delta
	//Returns a displacement vector
	float t = delta.asSeconds();
	sf::Vector2f acc(0,0);

	while(!forces.empty()){
		acc += forces.top()/mass;
		forces.pop();
	}
	sf::Vector2f oldVel = velocity;
	velocity.x += acc.x*t;
	velocity.y += acc.y*t;

	sf::Vector2f dis((velocity.x + oldVel.x)/2*t,(velocity.y + oldVel.y)/2*t);
	//THIS IS STILL WRONG HURRRRG NEED TO IMPLEMENT JERK

	return dis;
}