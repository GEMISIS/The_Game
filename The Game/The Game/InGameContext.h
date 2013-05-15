#ifndef INGAMECONTEXT_H
#define INGAMECONTEXT_H

#include "BaseContext.h"

class InGameContext : public BaseContext{
public:
	InGameContext();
	InGameContext(RenderTexture* renderTexture);
	void handleEvent(Event &e);
	void updateLogic(Time delta);
	void draw();
private:
};

#endif