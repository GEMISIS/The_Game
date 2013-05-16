#ifndef INGAMECONTEXT_H
#define INGAMECONTEXT_H

#include "BaseContext.h"
#include "PhysicsEntity.h"

class InGameContext : public BaseContext{
public:
	InGameContext();
	InGameContext(RenderWindow &window);
	void handleEvent(Event &e);
	void updateLogic(Time delta);
	void draw();
private:
	PhysicsEntity player;
};

#endif