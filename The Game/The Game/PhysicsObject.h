#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class PhysicsObject{
public:
	PhysicsObject();
	PhysicsObject(int mass);
	~PhysicsObject();
	
	void addForce(const std::string &name, sf::Vector2f force);
	void removeForce(const std::string &name);
	virtual void applyPhysics(sf::Time delta) = 0;

protected:
	int mass;

	sf::Vector2f calcPhysics(sf::Time delta);

private:
	sf::Vector2f velocity;
	std::unordered_map<std::string, sf::Vector2f> forces;
};

#endif