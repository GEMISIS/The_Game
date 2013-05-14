#include "BaseObjectClass.h"

unordered_map<string, sf::Texture*> BaseObject::textureList;

BaseObject::BaseObject()
{
}

BaseObject::BaseObject(const string filename)
{
	this->setTexture(filename);
}

void BaseObject::setTexture(const string filename)
{
	if(BaseObject::textureList.count(filename) > 0)
	{
		string s(filename.c_str());
		s.append(to_string((long long)BaseObject::textureList.size()));
		BaseObject::textureList.insert(pair<string, sf::Texture*>(s, BaseObject::textureList.at(filename)));
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
			BaseObject::textureList.insert(std::pair<std::string, sf::Texture*>(filename, t));
		}
		this->filename = filename;
	}
}

BaseObject::~BaseObject()
{
	BaseObject::textureList.erase(this->filename);
}

