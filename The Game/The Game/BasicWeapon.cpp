#include "BasicWeapon.h"
#include "BaseContext.h"
#include "Bullet.h"
#include "Util.h"
#include <iostream>


BasicWeapon::BasicWeapon(){this->bullSpeed = 100;}
BasicWeapon::BasicWeapon(float bullSpeed){this->bullSpeed = bullSpeed;}

void BasicWeapon::fire(sf::Vector2f pos, float rot){
	Bullet* b = new Bullet(pos,1);
	BaseContext::currentContext->addEntity(b);
	b->applyInstantImpulse(rotVec(sf::Vector2f(bullSpeed,0),rot));
	b->setStoredTexture("res/bullet.png");
}