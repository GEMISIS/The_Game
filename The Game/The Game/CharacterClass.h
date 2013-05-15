#ifndef _PLAYER_CHARACTER_CLASS_H_
#define _PLAYER_CHARACTER_CLASS_H_

#include "Entity.h"

class Character : public Entity
{
public:
	Character();
	Character(const string filename);
};

#endif