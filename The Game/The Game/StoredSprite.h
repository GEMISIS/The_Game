#ifndef STOREDSPRITE_H
#define STOREDSPRITE_H

#include "TextureInterface.h"

class StoredSprite : public Sprite, protected TextureInterface
{
public:
	StoredSprite();
	StoredSprite(const string &filename);
	void setStoredTexture(const string& filename);
};

#endif