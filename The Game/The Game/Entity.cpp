#include "Entity.h"

Entity::Entity() : TextureInterface()
{
}

Entity::Entity(const string &filename) : TextureInterface(filename)
{
	setTexture(*loadedTexture);
}

void Entity::setImage(const string &filename)
{
	this->setLoadedTexture(filename);
	this->setTexture(*loadedTexture);
}