#include "SpriteBaseClass.h"

SpriteBase::SpriteBase() : TextureInterface()
{
}

SpriteBase::SpriteBase(const string filename) : TextureInterface(filename)
{
	this->setTexture(*this->getTextureFromMap());
}

void SpriteBase::setImage(const string filename)
{
	this->preloadTexture(filename);
	this->setTexture(*this->getTextureFromMap());
}
