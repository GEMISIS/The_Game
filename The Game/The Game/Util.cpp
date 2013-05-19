#include "Util.h"
#include <math.h>

#include <iostream>

float getRot(sf::Vector2f vec){
	//Returns the rotation of a vector in radians
	return atan2(vec.y,vec.x);
}

sf::Vector2f rotVec(sf::Vector2f vec, float rot){
	float x = (vec.x * cos(rot)) - (vec.y * sin(rot));
	float y = (vec.y * cos(rot)) + (vec.x * sin(rot));
	return sf::Vector2f(x,y);
}