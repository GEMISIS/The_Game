#ifndef _SPRITE_BASE_CLASS_H_
#define _SPRITE_BASE_CLASS_H_

#include "TextureInterface.h"

class SpriteBase : protected TextureInterface, public Sprite
{
public:
	SpriteBase();
	SpriteBase(const string filename);
	void setImage(const string filename);
};

#endif