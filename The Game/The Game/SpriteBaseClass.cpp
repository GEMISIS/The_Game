#include "SpriteBaseClass.h"

SpriteBase::SpriteBase() : BaseObject()
{
}

SpriteBase::SpriteBase(const string filename) : BaseObject(filename)
{
	this->setTexture(*this->textureList[this->filename]);
}

void SpriteBase::setImage(const string filename)
{
	this->addTexture(filename);
	this->setTexture(*this->textureList[this->filename]);
}
