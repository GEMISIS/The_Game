#ifndef INGAMECONTEXT_H
#define INGAMECONTEXT_H

#include "BaseContext.h"

class InGameContext : public BaseContext{
public:
	InGameContext();
	InGameContext(sf::RenderWindow* w);
	void handleEvent(sf::Event &e);
	void updateLogic(sf::Time delta);
	void draw();

private:
	
};

#endif