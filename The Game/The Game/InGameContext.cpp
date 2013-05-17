#include "InGameContext.h"

#include <iostream>


InGameContext::InGameContext(){}
InGameContext::InGameContext(RenderWindow &window) : BaseContext(window), player("res/ship.png"), 
	test1(sf::Vector2f(400,50), 1),
	test2(sf::Vector2f(350,50), 1),
	test3(sf::Vector2f(300,50), 1),
	test4(sf::Vector2f(450,50), 1)
{
	player.setPosition(((float)this->window->getSize().x / 2) - (Player::HITBOX_SIZE.x / 2), (float)this->window->getSize().y - Player::HITBOX_SIZE.y - 32);
}

void InGameContext::handleEvent(Event &e)
{
	if(e.type == Event::KeyPressed)
	{
		if(e.key.code == Keyboard::Escape)
		{
			this->window->close();
		}
	}
}
void InGameContext::updateLogic(Time delta)
{
	player.resetVelocity();
	player.calcSmoothInput();
	player.move(delta);

	test1.applyPhysics(delta);
	test2.applyPhysics(delta);
	test3.applyPhysics(delta);
	test4.applyPhysics(delta);
}
void InGameContext::draw()
{
	this->window->draw(player);
	this->window->draw(test1);
	this->window->draw(test2);
	this->window->draw(test3);
	this->window->draw(test4);
}

