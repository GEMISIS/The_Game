#ifndef INGAMECONTEXT_H
#define INGAMECONTEXT_H

#include <list>
#include "BaseContext.h"
#include "Player.h"
#include "Bullet.h"
#include "Killable.h"
#include "CollisionCheck.h"

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

	list<Killable*> entList;
	CollisionCheck playerColCheck;
};

#endif