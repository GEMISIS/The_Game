#ifndef BASECONTEXT_H
#define BASECONTEXT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class BaseContext{
public:
	BaseContext();
	BaseContext(RenderTexture* renderTexture);
	virtual void handleEvent(Event &e) = 0;
	virtual void updateLogic(Time delta) = 0;
	virtual void draw() = 0;
protected:
	RenderTexture* renderTexture;
private:
};

#endif