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
	
	void addForce(const std::string &name, const sf::Vector2f &force);
	void removeForce(const std::string &name);
	virtual void applyPhysics(const sf::Time &delta) = 0;

protected:
	int mass;

	sf::Vector2f calcPhysics(const sf::Time &delta);

private:
	sf::Vector2f velocity;
	std::unordered_map<std::string, sf::Vector2f> forces;
};

#endif