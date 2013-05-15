#include "Entity.h"

Entity::Entity() : TextureInterface()
{
}

Entity::Entity(const string &filename) : TextureInterface(filename)
{
	this->setTexture(*this->getTextureFromMap());
}

void Entity::setImage(const string &filename)
{
	this->preloadTexture(filename);
	this->setTexture(*this->getTextureFromMap());
}
