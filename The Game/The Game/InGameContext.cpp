#include "InGameContext.h"

#include "Entity.h"
#include <iostream>

Entity player;
const Vector2f velocitySpeed(0.5f, 0.5f);
Vector2f velocity;

InGameContext::InGameContext(){}
InGameContext::InGameContext(RenderWindow &window) : BaseContext(window)
{
	player.setImage("res/ship.png");
	player.setPosition(((float)this->window->getSize().x / 2) - ((float)player.getTexture()->getSize().x / 2), (float)this->window->getSize().y - (float)player.getTexture()->getSize().y - 32);
}

void InGameContext::handleEvent(Event &e)
{
	if(e.type == Event::KeyReleased)
	{
		if(e.key.code == Keyboard::Left ||
			e.key.code == Keyboard::Right)
		{
			velocity.x = 0;
		}
		if(e.key.code == Keyboard::Up ||
			e.key.code == Keyboard::Down)
		{
			velocity.y = 0;
		}
	}
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
	if(Keyboard::isKeyPressed(Keyboard::Left))
	{
		velocity.x = -velocitySpeed.x;
	}
	if(Keyboard::isKeyPressed(Keyboard::Right))
	{
		velocity.x = velocitySpeed.x;
	}
	if(Keyboard::isKeyPressed(Keyboard::Up))
	{
		velocity.y = -velocitySpeed.y;
	}
	if(Keyboard::isKeyPressed(Keyboard::Down))
	{
		velocity.y = velocitySpeed.y;
	}
	player.move(velocity);
}

void InGameContext::draw()
{
	this->window->draw(player);
}

