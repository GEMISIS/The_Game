#ifndef STOREDSPRITE_H
#define STOREDSPRITE_H

#include "TextureInterface.h"

class StoredSprite : public Sprite, protected TextureInterface
{
public:
	StoredSprite();
	StoredSprite(const string &filename);
	void setImage(const string& filename);
};

#endif