#ifndef _PLAYER_CHARACTER_CLASS_H_
#define _PLAYER_CHARACTER_CLASS_H_

#include "SpriteBaseClass.h"

class Character : public SpriteBase
{
public:
	Character();
	Character(const string filename);
};

#endif