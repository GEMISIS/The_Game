#ifndef BASECONTEXT_H
#define BASECONTEXT_H

#include <SFML/Graphics.hpp>

class BaseContext{
public:
	BaseContext();
	BaseContext(sf::RenderWindow* w);
	virtual void handleEvent(sf::Event &e);
	virtual void updateLogic(sf::Time delta);
	virtual void draw();

protected:
	sf::RenderWindow* window;

private:

};

#endif