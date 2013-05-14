#ifndef INGAMECONTEXT_H
#define INGAMECONTEXT_H

#include "BaseContext.h"

class InGameContext : public BaseContext{
public:
	InGameContext();
	void handleEvent(sf::Event &e, sf::RenderWindow &w);
	void draw(sf::RenderWindow &w);

private:
	
};

#endif