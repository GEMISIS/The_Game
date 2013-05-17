#ifndef PATH_H
#define PATH_H

#include <SFML/Graphics.hpp>

class Path{
public:
	Path();
	Path(float mass, float rot);
	virtual sf::Vector2f calcForceVector() = 0;

protected:
	sf::Vector2f applyRotation(sf::Vector2f force);

private:
	float mass;
	float rotation; //With 0 being right, going counter-clockwise
};

#endif