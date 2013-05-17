#ifndef PATH_H
#define PATH_H

#include <SFML/Graphics.hpp>

class Path{
public:
	Path();
	Path(float mass);
	virtual sf::Vector2f calcForceVector() = 0;

private:
	float mass;
};

#endif