#ifndef _WORLD_CLASS_H_
#define _WORLD_CLASS_H_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class World
{
public:
	World();
	World(const string& filename);
	void Update(sf::RenderWindow& window);
	~World();
private:
	string filename;
	sf::Sprite sprite;
	static unordered_map<string, sf::Texture*> textureList;
};

#endif