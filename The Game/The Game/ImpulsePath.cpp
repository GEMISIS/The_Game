#include "ImpulsePath.h"

ImpulsePath::ImpulsePath(){}
ImpulsePath::ImpulsePath(float mass, const sf::Vector2f &targetVelocity, float accTime) :
	Path(mass)
{
	forceAmt = sf::Vector2f(targetVelocity.x/accTime*mass,targetVelocity.y/accTime*mass);
	time = accTime;
}

sf::Vector2f ImpulsePath::calcForceVector(){
	if(clock.getElapsedTime().asSeconds() < time)
		return forceAmt;
	else
		return sf::Vector2f(0,0);
}