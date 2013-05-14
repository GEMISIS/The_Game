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
	if(BaseObject::textureList.count(filename) > 0)
	{
		string s(filename.c_str());
		s.append(to_string((long long)BaseObject::textureList.size()));
		BaseObject::textureList.insert(pair<string, Texture*>(s, BaseObject::textureList.at(filename)));
		this->filename = s;
	}
	else
	{
		Texture* t = new Texture();
		if(!t->loadFromFile(filename))
		{
			cout << "Could not load texture " << filename << endl;
		}
		else
		{
			BaseObject::textureList.insert(std::pair<std::string, Texture*>(filename, t));
			this->filename = filename;
		}
	}
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
		BaseObject::textureList.erase(filename);
	}
}

BaseObject::~BaseObject()
{
	BaseObject::textureList.erase(this->filename);
}

