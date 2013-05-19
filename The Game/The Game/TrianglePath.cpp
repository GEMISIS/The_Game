#include "TrianglePath.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include "Util.h"

#include <iostream>

TrianglePath::TrianglePath(){}
TrianglePath::TrianglePath(PhysicsObject &obj, sf::Vector2f initImpulse, float oscWidth, float oscFreq, bool lr){
	this->lr = lr;
	this->oscFreq = oscFreq;

	if(!lr)
		currOscTime = oscFreq/4;
	else
		currOscTime = 3*oscFreq/4;

	sf::Vector2f oscVel(0,4*oscWidth/oscFreq);
	this->oscVel = rotVec(oscVel, getRot(initImpulse));

	obj.applyInstantImpulse(initImpulse);
	if(!lr)
		obj.applyInstantImpulse(sf::Vector2f(-this->oscVel.x/2,-this->oscVel.y/2));
	else
		obj.applyInstantImpulse(sf::Vector2f(this->oscVel.x/2,this->oscVel.y/2));
	
}

void TrianglePath::calcForceVector(PhysicsObject &obj, const sf::Time &delta){
	currOscTime += delta.asSeconds();
	if(currOscTime > oscFreq)
		currOscTime -= oscFreq;

	if(currOscTime < oscFreq/2  && !lr){
		obj.applyInstantImpulse(oscVel);
		lr = true;
	}

	if(currOscTime > oscFreq/2  && lr){
		obj.applyInstantImpulse(-oscVel);
		lr = false;
	}
}