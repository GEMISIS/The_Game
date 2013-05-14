#ifndef _SPRITE_BASE_CLASS_H_
#define _SPRITE_BASE_CLASS_H_

#include "BaseObjectClass.h"

class SpriteBase : protected BaseObject, public Sprite
{
public:
	SpriteBase();
	SpriteBase(const string filename);
	void setImage(const string filename);
};

#endif