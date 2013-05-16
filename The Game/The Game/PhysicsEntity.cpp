#include "PhysicsEntity.h"

PhysicsEntity::PhysicsEntity(){}
PhysicsEntity::PhysicsEntity(const string &filename, int mass): Entity(filename), PhysicsObject(mass){}

void PhysicsEntity::applyPhysics(sf::Time delta){
	//Moves the entity based on it's velocity over time delta
	sf::Vector2f vel = this->calcPhysics(delta);
	this->move(vel.x*delta.asSeconds(),vel.y*delta.asSeconds());
}