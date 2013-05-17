#ifndef IMPULSEPATH_H
#define IMPULSEPATH_H

#include "Path.h"

class ImpulsePath : Path{
public:
	ImpulsePath(); //Seriously, don't do it...
	ImpulsePath(float mass, const sf::Vector2f &targetVelocity, float accTime);
	//NOTE: ImpulsePath is highly inaccurate under very small accTimes (under 0.2f),
	//and also somewhat innacurate under small accTimes (under 0.5f)
	//Right now, it is never 100% compleatly accurate (looking into that that)

	sf::Vector2f calcForceVector();

private:
	sf::Vector2f forceAmt;
	sf::Clock clock;
	float time;

};

#endif