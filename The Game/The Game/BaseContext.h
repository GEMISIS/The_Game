#ifndef BASECONTEXT_H
#define BASECONTEXT_H

#include <SFML/Graphics.hpp>

class BaseContext{
public:
	BaseContext();
	virtual void handleEvent(sf::Event &e, sf::RenderWindow &w);
	virtual void updateLogic(sf::Time delta);
	virtual void draw(sf::RenderWindow &w);

private:

};

#endif