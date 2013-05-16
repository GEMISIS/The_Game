#include "StoredSprite.h"

StoredSprite::StoredSprite() : TextureInterface()
{
}

StoredSprite::StoredSprite(const string &filename) : TextureInterface(filename)
{
	setTexture(*loadedTexture);
}

void StoredSprite::setImage(const string &filename)
{
	this->setLoadedTexture(filename);
	this->setTexture(*loadedTexture);
}