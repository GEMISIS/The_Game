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
InGameContext::InGameContext(RenderWindow &window) : BaseContext(window), player("res/ship.png")
{
	player.setPosition(((float)this->window->getSize().x / 2) - (Player::HITBOX_SIZE.x / 2), (float)this->window->getSize().y - Player::HITBOX_SIZE.y - 32);

	Bullet* test1 = new Bullet(sf::Vector2f(400,0), 1);
	Bullet* test2 = new Bullet(sf::Vector2f(400,600), 1);
	Bullet* test3 = new Bullet(sf::Vector2f(0,300), 1);
	Bullet* test4 = new Bullet(sf::Vector2f(800,300), 1);
	test1->setStoredTexture("res/bullet.png");
	test2->setStoredTexture("res/bullet.png");
	test3->setStoredTexture("res/bullet.png");
	test4->setStoredTexture("res/bullet.png");
	test1->addPath(new TrianglePath(*test1,sf::Vector2f(0,100),800,1.0f,true));
	test2->addPath(new TrianglePath(*test2,sf::Vector2f(0,-100),800,1.0f,true));
	test3->addPath(new TrianglePath(*test3,sf::Vector2f(100,0),600,1.0f,true));
	test4->addPath(new TrianglePath(*test4,sf::Vector2f(-100,0),600,1.0f,true));
	playerColCheck.addItem(&player);
	playerColCheck.addItem(test1);
	playerColCheck.addItem(test2);
	playerColCheck.addItem(test3);
	playerColCheck.addItem(test4);
	entities.push_back(test1);
	entities.push_back(test2);
	entities.push_back(test3);
	entities.push_back(test4);

	//Commented out because I've changed the testing objects it uses
	/*TestSettings test1 = {1, 5, 6};
	TestSettings test2 = {0, 0, 0};
	char* set1 = (char*)&test1;
	char* set2;
	DataFile::SaveData("testing.set", set1, sizeof(TestSettings));
	DataFile::LoadData("testing.set", set2);
	test2 = *((TestSettings*)set2);
	cout << test1.x << ", " << test1.y << ", " << test1.z << "\n";
	cout << test2.x << ", " << test2.y << ", " << test2.z << "\n";*/
}

void InGameContext::handleEvent(Event &e)
{
	if(e.type == Event::KeyPressed)
	{
		if(e.key.code == Keyboard::Escape)
		{
			this->cleanup();
			this->window->close();
		}
	}
}
void InGameContext::updateLogic(Time delta)
{
	player.resetVelocity();
	player.calcSmoothInput();
	player.move(delta);

	auto it = entities.begin();
	while(it != entities.end()){
		(*it)->applyPhysics(delta);
		++it;

	}

	playerColCheck.checkCollisions();
	
}
void InGameContext::draw()
{
	this->window->draw(player);

	auto it = entities.begin();
	while(it != entities.end()){
		this->window->draw(**it);
		++it;
	}
}

void InGameContext::cleanup()
{
	auto it = entities.begin();
	while(it != entities.end()){
		delete *it;
		++it;
	}
	entities.clear();
}