#ifndef INGAMECONTEXT_H
#define INGAMECONTEXT_H

#include "BaseContext.h"
#include "Player.h"
#include "Bullet.h"

class InGameContext : public BaseContext{
public:
	InGameContext();
	InGameContext(RenderWindow &window);
	void handleEvent(Event &e);
	void updateLogic(Time delta);
	void draw();
private:
	Player player;
	Bullet test1;
	Bullet test2;
	Bullet test3;
	Bullet test4;
};

#endif