#include "Player.h"

const float Player::MOVE_SPEED = 500.0;
const sf::Vector2f Player::HITBOX_SIZE(50.0,50.0);

Player::Player(){}
Player::Player(const std::string &filename): sprite(filename){
	hitbox.width = HITBOX_SIZE.x;
	hitbox.height = HITBOX_SIZE.y;
}

//public

void Player::resetVelocity(){velocity = sf::Vector2f(0,0);}
void Player::addVelocity(const sf::Vector2f &amt){velocity += amt;}
void Player::move(const sf::Time &delta){
	sf::Vector2f amt(velocity.x*delta.asSeconds(),velocity.y*delta.asSeconds());
	sprite.move(amt.x, amt.y);
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