#include "WorldClass.h"

unordered_map<string, sf::Texture*> World::textureList;

World::World()
{
}

World::World(const string& filename)
{
	if(World::textureList.count(filename) > 0)
	{
		string s(filename.c_str());
		s.append(to_string((long long)World::textureList.size()));
		World::textureList.insert(pair<string, sf::Texture*>(s, World::textureList.at(filename)));
		this->filename = s;
	}
	else
	{
		sf::Texture* t = new sf::Texture();
		if(!t->loadFromFile(filename))
		{
			cout << "Could not load texture " << filename << endl;
			return;
		}
		else
		{
			World::textureList.insert(std::pair<std::string, sf::Texture*>(filename, t));
		}
		this->filename = filename;
	}

	this->sprite.setTexture(*World::textureList[this->filename]);
}

void World::Update(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

World::~World()
{
	World::textureList.erase(this->filename);
}

