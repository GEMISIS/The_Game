#ifndef ENTITY_H
#define ENTITY_H

#include "TextureInterface.h"

class Entity : public Sprite, protected TextureInterface
{
public:
	Entity();
	Entity(const string &filename);
	void setImage(const string& filename);

private:
	//FloatRect hitbox;
};

#endif