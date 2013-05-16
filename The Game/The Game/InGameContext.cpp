#include "InGameContext.h"

#include <iostream>

<<<<<<< HEAD
Entity player;
const Vector2f velocitySpeed(0.5f, 0.5f);
Vector2f velocity;
=======
float pmf = 100.0;
>>>>>>> Physics System

InGameContext::InGameContext(){}
InGameContext::InGameContext(RenderWindow &window) : BaseContext(window), player("res/ship.png",1)
{
	player.setImage("res/ship.png");
	player.setPosition(((float)this->window->getSize().x / 2) - ((float)player.getTexture()->getSize().x / 2), (float)this->window->getSize().y - (float)player.getTexture()->getSize().y - 32);
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
	if(Keyboard::isKeyPressed(Keyboard::Left))
		player.addForce("left",Vector2f(-pmf,0));
	else
		player.removeForce("left");

	if(Keyboard::isKeyPressed(Keyboard::Right))
		player.addForce("right",Vector2f(pmf,0));
	else
		player.removeForce("right");

	if(Keyboard::isKeyPressed(Keyboard::Up))
		player.addForce("up",Vector2f(0,-pmf));
	else
		player.removeForce("up");

	if(Keyboard::isKeyPressed(Keyboard::Down))
		player.addForce("down",Vector2f(0,pmf));
	else
		player.removeForce("down");

	player.applyPhysics(delta);
}
void InGameContext::draw()
{
	this->window->draw(player);
}

