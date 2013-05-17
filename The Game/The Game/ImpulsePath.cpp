#include "ImpulsePath.h"

ImpulsePath::ImpulsePath(){}
ImpulsePath::ImpulsePath(float mass, float rot, const sf::Vector2f &targetVelocity, float accTime) :
	Path(mass, rot)
{
	forceAmt = sf::Vector2f(targetVelocity.x/accTime*mass,targetVelocity.y/accTime*mass);
	forceAmt = applyRotation(forceAmt);
	time = accTime;
}

sf::Vector2f ImpulsePath::calcForceVector(){
	if(clock.getElapsedTime().asSeconds() < time)
		return forceAmt;
	else
		return sf::Vector2f(0,0);
}