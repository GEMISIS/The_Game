#include "Player.h"

#include "BasicWeapon.h"
#define _USE_MATH_DEFINES
#include <math.h>


const float Player::MOVE_SPEED = 500.0;
const sf::Vector2f Player::HITBOX_SIZE(50.0,50.0);

Player::Player(){init();}
Player::Player(const std::string &filename): sprite(filename){
	init();
	hitbox.width = HITBOX_SIZE.x;
	hitbox.height = HITBOX_SIZE.y;
}
Player::~Player(){delete weapon;}

//public

void Player::updatePlayerLogic(const sf::Time &delta){
	if(weaponOnCD){
		sinceLastFired += delta.asSeconds();
		if(sinceLastFired >= weaponCD)
			weaponOnCD = false;
	}
}

void Player::calcSmoothInput(){
	//Calculates the effect of current player input
	bool lDown = Keyboard::isKeyPressed(Keyboard::Left);
	bool rDown = Keyboard::isKeyPressed(Keyboard::Right);
	bool uDown = Keyboard::isKeyPressed(Keyboard::Up);
	bool dDown = Keyboard::isKeyPressed(Keyboard::Down);

	if(lDown){
		if(!lFirst && !rFirst) lFirst = true;
		if((rDown && rFirst) || (lDown && !rDown))
			addVelocity(Vector2f(-MOVE_SPEED,0));	
	}else
		lFirst = false;	

	if(rDown){
		if(!rFirst && !lFirst) rFirst = true;
		if((lDown && lFirst) || (rDown && !lDown))
			addVelocity(Vector2f(MOVE_SPEED,0));
	}else
		rFirst = false;		

	if(uDown){
		if(!uFirst && !dFirst) uFirst = true;
		if((dDown && dFirst) || (uDown && !dDown))
			addVelocity(Vector2f(0,-MOVE_SPEED));
	}else
		uFirst = false;
		
	if(dDown){
		if(!dFirst && !uFirst) dFirst = true;
		if((uDown && uFirst) || (dDown && !uDown))
			addVelocity(Vector2f(0,MOVE_SPEED));
	}else
		dFirst = false;

	if(Keyboard::isKeyPressed(Keyboard::Z) && !weaponOnCD){
		weaponOnCD = true;
		sinceLastFired = 0;
		weapon->fire(sf::Vector2f(hitbox.left,hitbox.top),(float)(3*M_PI/2));
	}
}

void Player::resetVelocity(){velocity = sf::Vector2f(0,0);}
void Player::addVelocity(const sf::Vector2f &amt){velocity += amt;}
void Player::move(const sf::Time &delta){
	sf::Vector2f amt(velocity.x*delta.asSeconds(),velocity.y*delta.asSeconds());
	sprite.move(amt);
	hitbox.left += amt.x;
	hitbox.top += amt.y;
}
void Player::setPosition(float x, float y){
	sprite.setPosition(x,y);
	hitbox.left = x;
	hitbox.top = y;
}
void Player::setPosition(const Vector2f &position){
	sprite.setPosition(position);
	hitbox.left = position.x;
	hitbox.top = position.y;
}

void Player::collidesWith(const CollidableObject &other){}

//private

void Player::draw (RenderTarget &target, RenderStates states) const{target.draw(sprite,states);}
void Player::init(){
	//An initalization function because c++ doesn't support delegating constructors
	lFirst = false;
	rFirst = false;
	uFirst = false;
	dFirst = false;
	weaponOnCD = false;
	weapon = new BasicWeapon();
	weaponCD = 0.5f;
}