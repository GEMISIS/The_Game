#ifndef SINPATH_H
#define SINPATH_H

#include "Path.h"

class SinPath : Path{
public:
	SinPath();
	SinPath(PhysicsObject &obj, sf::Vector2f initImpulse, float oscWidth, float oscFreq);

	sf::Vector2f calcForceVector(PhysicsObject &obj, const sf::Time &delta);

private:
	sf::Time totalDelta;
};

#endif