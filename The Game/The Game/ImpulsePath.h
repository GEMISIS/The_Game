#ifndef IMPULSEPATH_H
#define IMPULSEPATH_H

#include "Path.h"

class ImpulsePath : Path{
public:
	ImpulsePath(); //Seriously, don't do it...
	ImpulsePath(float mass, const sf::Vector2f &targetVelocity, float accTime);
	sf::Vector2f calcForceVector();

private:
	sf::Vector2f forceAmt;
	sf::Clock clock;
	float time;

	
};

#endif