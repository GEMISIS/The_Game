#include "BaseContext.h"
#include <iostream>

BaseContext::BaseContext()
{
}

BaseContext::BaseContext(RenderWindow &window)
{
	this->window = &window;
}

