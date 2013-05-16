#include "InGameContext.h"

#include <iostream>

float pmf = 500.0;

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
	if(Keyboard::isKeyPressed(Keyboard::Left))
		player.addVelocity(Vector2f(-pmf,0));

	if(Keyboard::isKeyPressed(Keyboard::Right))
		player.addVelocity(Vector2f(pmf,0));

	if(Keyboard::isKeyPressed(Keyboard::Up))
		player.addVelocity(Vector2f(0,-pmf));

	if(Keyboard::isKeyPressed(Keyboard::Down))
		player.addVelocity(Vector2f(0,pmf));

	player.move(delta);
}
void InGameContext::draw()
{
	this->window->draw(player);
}

