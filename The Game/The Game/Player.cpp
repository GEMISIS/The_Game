#include "Player.h"

Player::Player(){}
Player::Player(const std::string &filename): Entity(filename){}

void Player::resetVelocity(){velocity = sf::Vector2f(0,0);}
void Player::addVelocity(const sf::Vector2f &amt){velocity += amt;}
void Player::move(const sf::Time &delta){
	Entity::move(velocity.x*delta.asSeconds(),velocity.y*delta.asSeconds());
}

void Player::collidesWith(const CollidableObject &other){}