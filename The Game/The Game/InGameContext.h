#ifndef INGAMECONTEXT_H
#define INGAMECONTEXT_H

#include "BaseContext.h"
#include "Player.h"
#include "Bullet.h"
#include "CollisionCheck.h"

class InGameContext : public BaseContext{
public:
	InGameContext();
	InGameContext(RenderWindow &window);

	void handleEvent(Event &e);
	void updateLogic(Time delta);
	void draw();
	void cleanup();
private:
	Player player;

	CollisionCheck playerColCheck;
};

#endif