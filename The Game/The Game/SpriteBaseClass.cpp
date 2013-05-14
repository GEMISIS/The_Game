#include "SpriteBaseClass.h"

SpriteBase::SpriteBase() : BaseObject()
{
}

SpriteBase::SpriteBase(const string filename) : BaseObject(filename)
{
	this->sprite.setTexture(*this->textureList[this->filename]);
}

void SpriteBase::setImage(const string filename)
{
	this->setTexture(filename);
	this->sprite.setTexture(*this->textureList[this->filename]);
}

void SpriteBase::setPosition(float x, float y)
{
	this->sprite.setPosition(sf::Vector2f(x, y));
}

void SpriteBase::setColor(sf::Color color)
{
	this->sprite.setColor(color);
}

void SpriteBase::Update(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}
