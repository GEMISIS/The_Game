#ifndef _SPRITE_BASE_CLASS_H_
#define _SPRITE_BASE_CLASS_H_

#include "BaseObjectClass.h"

class SpriteBase : protected BaseObject
{
public:
	SpriteBase();
	SpriteBase(const string filename);
	void setImage(const string filename);
	void setPosition(float x, float y);
	void setColor(sf::Color color);
	void Update(sf::RenderWindow& window);
protected:
	sf::Sprite sprite;
};

#endif