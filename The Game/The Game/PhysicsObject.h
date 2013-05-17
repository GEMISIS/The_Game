#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <SFML/Graphics.hpp>
#include <stack>

class PhysicsObject{
public:
	PhysicsObject();
	PhysicsObject(float mass);
	
	float getMass();

	void applyForce(const sf::Vector2f &force);
	void applyInstantImpulse(const sf::Vector2f &deltaM);
	virtual void applyPhysics(const sf::Time &delta) = 0;

protected:
	float mass;

	sf::Vector2f calcPhysics(const sf::Time &delta);

private:
	sf::Vector2f velocity;
	std::stack<sf::Vector2f> forces;
};

#endif