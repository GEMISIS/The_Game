#include "InGameContext.h"

#include <iostream>

InGameContext::InGameContext(){}
InGameContext::InGameContext(sf::RenderWindow* w): BaseContext(w){}

void InGameContext::handleEvent(sf::Event &e){}
void InGameContext::updateLogic(sf::Time delta){}
void InGameContext::draw(){}