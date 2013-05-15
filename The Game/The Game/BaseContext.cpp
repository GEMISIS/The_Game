#include "BaseContext.h"
#include <iostream>

BaseContext::BaseContext()
{
}

BaseContext::BaseContext(RenderTexture* renderTexture)
{
	this->renderTexture = renderTexture;
}

