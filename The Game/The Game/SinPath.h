#ifndef SINPATH_H
#define SINPATH_H

#include "Path.h"

class SinPath : Path{
public:
	SinPath();
	SinPath(PhysicsObject &obj, float rot);

	void updatePathLogic();

private:
	sf::Clock clock;
};

#endif