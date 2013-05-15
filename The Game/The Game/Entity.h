#ifndef ENTITY_H
#define ENTITY_H

#include "TextureInterface.h"

class Entity : protected TextureInterface, public Sprite
{
public:
	Entity();
	Entity(const string &filename);
	void setImage(const string &filename);
};

#endif