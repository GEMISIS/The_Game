#include "SinPath.h"

SinPath::SinPath(){}
SinPath::SinPath(PhysicsObject &obj, sf::Vector2f initImpulse, float oscWidth, float oscFreq){
	obj.applyInstantImpulse(initImpulse);
}

sf::Vector2f SinPath::calcForceVector(PhysicsObject &obj, const sf::Time &delta){
	totalDelta += delta;




	return sf::Vector2f(0,0);
}