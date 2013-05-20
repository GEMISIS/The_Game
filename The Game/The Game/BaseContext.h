#ifndef BASECONTEXT_H
#define BASECONTEXT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class BaseContext{
public:
	BaseContext();
	BaseContext(RenderWindow &window);
	virtual void handleEvent(Event &e) = 0;
	virtual void updateLogic(Time delta) = 0;
	virtual void draw() = 0;
	virtual void cleanup() = 0;
	static BaseContext* currentContext;
protected:
	RenderWindow* window;
private:
};

#endif