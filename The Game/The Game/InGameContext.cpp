#include "InGameContext.h"
#include "DataFile.h"
#include <iostream>

#include "TrianglePath.h"
#include "Util.h"
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int x, y, z;
}TestSettings;

InGameContext::InGameContext(){}
InGameContext::InGameContext(RenderWindow &window) : BaseContext(window), player("res/ship.png")
{
	player.setPosition(((float)this->window->getSize().x / 2) - (Player::HITBOX_SIZE.x / 2), (float)this->window->getSize().y - Player::HITBOX_SIZE.y - 32);

	srand (time(NULL));
	int x = 0;
	int y = 0;

	for(int i = 0; i < 5000; ++i){
		x += 20;
		if(x > 800){
			x = 0;
			y += 1;
		}

		Bullet* b = new Bullet(sf::Vector2f(x,y), 1);
		b->setStoredTexture("res/bullet.png");
		b->addPath(new TrianglePath(*b,sf::Vector2f(0,100),rand()%500,rand()%5+3,true));
		playerColCheck.addItem(b);
		entities.push_back(b);
	}

	playerColCheck.addItem(&player);

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
void InGameContext::updateLogic(const Time &delta)
{
	//Update player logic
	player.updatePlayerLogic(delta);

	//Calculate player movement
	player.resetVelocity();
	player.calcSmoothInput();
	player.move(delta);

	//Calculate other entity movement
	auto it = entities.begin();
	while(it != entities.end()){
		(*it)->applyPhysics(delta);
		++it;

	}

	//Check collisions
	//the current collision system is just a prototype, ignore it atm.
	//playerColCheck.checkCollisions();
	
	//If an entity is slated for removal, remove it.
	it = entities.begin();
	while(it != entities.end()){
		if((*it)->getSlated()){
			auto next = it;
			++next;
			delete *it;
			entities.erase(it);
			it = next;
			continue;
		}
		++it;
	}
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