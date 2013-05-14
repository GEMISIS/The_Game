#include "BaseObjectClass.h"

unordered_map<string, Texture*> BaseObject::textureList;

BaseObject::BaseObject()
{
}

BaseObject::BaseObject(const string filename)
{
	this->addTexture(filename);
}

void BaseObject::addTexture(const string filename)
{
	if(BaseObject::textureList.count(filename) == 0)
	{
		Texture* t = new Texture();
		if(!t->loadFromFile(filename))
		{
			cout << "Could not load texture " << filename << endl;
			return;
		}
		else
		{
			BaseObject::textureList.insert(std::pair<std::string, Texture*>(filename, t));
		}
	}
	this->filename = filename;
}

void BaseObject::addTextureToList(const string filename)
{
	if(BaseObject::textureList.count(filename) == 0)
	{
		Texture* t = new Texture();
		if(!t->loadFromFile(filename))
		{
			cout << "Could not load texture " << filename << endl;
		}
		else
		{
			BaseObject::textureList.insert(std::pair<std::string, Texture*>(filename, t));
		}
	}
}

void BaseObject::removeTextureFromList(const string filename)
{
	if(BaseObject::textureList.count(filename) > 0)
	{
		BaseObject::textureList.at(filename)->~Texture();
		BaseObject::textureList.erase(filename);
	}
}

BaseObject::~BaseObject()
{
}

