#ifndef PATH_H
#define PATH_H

#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"

class Path{
public:
	virtual void calcForceVector(PhysicsObject &obj, const sf::Time &delta) = 0;
};

#endif