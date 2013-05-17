#include "Path.h"

Path::Path(){mass = 0; rotation = 0;}
Path::Path(float mass, float rot){this->mass = mass; rotation = rot;}

sf::Vector2f Path::applyRotation(sf::Vector2f force){
	return sf::Vector2f(0,0);
}