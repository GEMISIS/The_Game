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

