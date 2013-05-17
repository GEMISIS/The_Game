#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(){mass = 0;}
PhysicsObject::PhysicsObject(int mass){this->mass = mass;}
PhysicsObject::~PhysicsObject(){forces.clear();}

//public

void PhysicsObject::addForce(const std::string &name, const sf::Vector2f &force){
	//Adds a force to the physics object
	//If the force already exists, nothing happens
	forces.insert(std::pair<std::string,sf::Vector2f>(name,force));
}
void PhysicsObject::removeForce(const std::string &name){
	//Removes the force from the object
	//If the force does not exist, nothing happens
	if(forces.count(name) > 0)
		forces.erase(name);
}

//protected

sf::Vector2f PhysicsObject::calcPhysics(const sf::Time &delta){
	//Calculates the change in velocity over time delta
	//Returns the new velocity in units/second
	sf::Vector2f acc;
	for(auto it = forces.begin(); it != forces.end(); ++it)
		acc += sf::Vector2f(it->second.x/mass,it->second.y/mass);
	velocity.x += acc.x*delta.asSeconds();
	velocity.y += acc.y*delta.asSeconds();
	return velocity;
}