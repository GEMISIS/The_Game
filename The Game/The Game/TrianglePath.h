#ifndef TRIANGLEPATH_H
#define TRIANGLEPATH_H

#include "Path.h"

class TrianglePath : public Path{
public:
	TrianglePath();
	TrianglePath(PhysicsObject &obj, sf::Vector2f initImpulse, float oscWidth, float oscFreq, bool lr);

	void calcForceVector(PhysicsObject &obj, const sf::Time &delta);

private:
	float oscFreq;
	float currOscTime;
	sf::Vector2f oscVel;
	bool lr; //l = false, right = true
};

#endif