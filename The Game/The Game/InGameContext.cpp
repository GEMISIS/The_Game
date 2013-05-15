#include "InGameContext.h"
#include "CharacterClass.h"

#include <iostream>

SpriteBase sprite;
const Vector2f velocitySpeed(0.5f, 0.5f);
Vector2f velocity;

InGameContext::InGameContext()
{
}

InGameContext::InGameContext(RenderTexture* renderTexture) : BaseContext(renderTexture)
{
	sprite.setImage("res/ship.png");
	sprite.setPosition((renderTexture->getSize().x / 2) - (sprite.getTexture()->getSize().x / 2), renderTexture->getSize().y - sprite.getTexture()->getSize().y - 32);
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
		if(e.key.code == Keyboard::Left)
		{
			velocity.x = -velocitySpeed.x;
		}
		if(e.key.code == Keyboard::Right)
		{
			velocity.x = velocitySpeed.x;
		}
		if(e.key.code == Keyboard::Up)
		{
			velocity.y = -velocitySpeed.y;
		}
		if(e.key.code == Keyboard::Down)
		{
			velocity.y = velocitySpeed.y;
		}
	}
}

void InGameContext::updateLogic(Time delta)
{
	sprite.move(velocity);
}

void InGameContext::draw()
{
	this->renderTexture->clear();
	this->renderTexture->draw(sprite);
	this->renderTexture->display();
}

