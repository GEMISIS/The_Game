#include "BaseContext.h"
#include <iostream>

BaseContext::BaseContext(){}
BaseContext::BaseContext(sf::RenderWindow* w){window = w;}

void BaseContext::handleEvent(sf::Event &e){}
void BaseContext::updateLogic(sf::Time delta){}
void BaseContext::draw(){}