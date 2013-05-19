#include "InGameContext.h"
#include "DataFile.h"
#include <iostream>

#include "TrianglePath.h"
#include "Util.h"

typedef struct
{
	int x, y, z;
}TestSettings;

InGameContext::InGameContext(){}
InGameContext::InGameContext(RenderWindow &window) : BaseContext(window), player("res/ship.png"), 
	test1(sf::Vector2f(400,50), 1),
	test2(sf::Vector2f(400,50), 1),
	test3(sf::Vector2f(400,50), 1),
	test4(sf::Vector2f(400,50), 1)
{
	player.setPosition(((float)this->window->getSize().x / 2) - (Player::HITBOX_SIZE.x / 2), (float)this->window->getSize().y - Player::HITBOX_SIZE.y - 32);

	sf::Vector2f initImp(0,100);

	test1.addPath(new TrianglePath(test1,initImp,800,1.0f,true));
	test2.addPath(new TrianglePath(test2,initImp,800,1.0f,false));
	test3.addPath(new TrianglePath(test3,initImp,800,1.0f,true));
	test4.addPath(new TrianglePath(test4,initImp,800,1.0f,false));

	TestSettings test1 = {1, 5, 6};
	TestSettings test2 = {0, 0, 0};
	char* set1 = (char*)&test1;
	char* set2;
	DataFile::SaveData("testing.set", set1, sizeof(TestSettings));
	DataFile::LoadData("testing.set", set2);
	test2 = *((TestSettings*)set2);
	cout << test1.x << ", " << test1.y << ", " << test1.z << "\n";
	cout << test2.x << ", " << test2.y << ", " << test2.z << "\n";
}

void InGameContext::handleEvent(Event &e)
{
	if(e.type == Event::KeyPressed)
	{
		if(e.key.code == Keyboard::Escape)
		{
			this->window->close();
		}
	}
}
void InGameContext::updateLogic(Time delta)
{
	player.resetVelocity();
	player.calcSmoothInput();
	player.move(delta);

	test1.applyPhysics(delta);
	test2.applyPhysics(delta);
	test3.applyPhysics(delta);
	test4.applyPhysics(delta);
}
void InGameContext::draw()
{
	this->window->draw(player);
	this->window->draw(test1);
	this->window->draw(test2);
	this->window->draw(test3);
	this->window->draw(test4);
}

