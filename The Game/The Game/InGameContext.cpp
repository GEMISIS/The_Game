#include "InGameContext.h"

#include <iostream>
#include "ImpulsePath.h"
ImpulsePath test(1.0, 0.0, sf::Vector2f(10,10), 10.0);

InGameContext::InGameContext(){}
InGameContext::InGameContext(RenderWindow &window) : BaseContext(window), player("res/ship.png")
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
}
void InGameContext::draw()
{
	this->window->draw(player);
}

