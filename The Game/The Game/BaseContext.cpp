#include "BaseContext.h"
#include <iostream>

BaseContext* BaseContext::currentContext;

BaseContext::BaseContext()
{
}

BaseContext::BaseContext(RenderWindow &window)
{
	this->window = &window;
}

void BaseContext::addEntity(Entity* e)
{
	entities.push_back(e);
}