#include "Util.h"
#include <cmath>

sf::Vector2f rotVec(sf::Vector2f vec, float rot){
	float x = (vec.x * cos(rot)) - (vec.y * sin(rot));
	float y = (vec.y * cos(rot)) + (vec.x * sin(rot));
	return sf::Vector2f(x,y);
}