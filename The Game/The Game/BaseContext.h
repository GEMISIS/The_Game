#ifndef BASECONTEXT_H
#define BASECONTEXT_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Entity.h"

using namespace sf;

class BaseContext{
public:
	static BaseContext* currentContext;

	BaseContext();
	BaseContext(RenderWindow &window);
	virtual void handleEvent(Event &e) = 0;
	virtual void updateLogic(const Time &delta) = 0;
	virtual void draw() = 0;
	virtual void cleanup() = 0;
	void addEntity(Entity* e);
protected:
	RenderWindow* window;
	list<Entity*> entities;
private:
};

#endif