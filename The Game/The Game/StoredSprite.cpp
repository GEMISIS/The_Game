#include "StoredSprite.h"

StoredSprite::StoredSprite() : TextureInterface()
{
}

StoredSprite::StoredSprite(const string &filename) : TextureInterface(filename)
{
	setTexture(*loadedTexture);
}

void StoredSprite::setStoredTexture(const string &filename)
{
	this->setLoadedTexture(filename);
	this->setTexture(*loadedTexture);
}