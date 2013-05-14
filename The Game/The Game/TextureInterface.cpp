#include "TextureInterface.h"

unordered_map<string, Texture*> TextureInterface::textureMap;
unordered_map<string, unsigned int> TextureInterface::textureAmounts;

TextureInterface::TextureInterface()
{
}

TextureInterface::TextureInterface(const string filename)
{
	this->preloadTexture(filename);
}

Texture* TextureInterface::getTextureFromMap()
{
	return this->textureMap[this->filename];
}

void TextureInterface::preloadTexture(const string filename)
{
	if(TextureInterface::textureMap.count(filename) == 0)
	{
		Texture* t = new Texture();
		if(!t->loadFromFile(filename))
		{
			cout << "Could not load texture " << filename << endl;
			return;
		}
		else
		{
			TextureInterface::textureMap.insert(pair<string, Texture*>(filename, t));
		}
		TextureInterface::textureAmounts.insert(pair<string, int>(filename, 1));
	}
	else
	{
		textureAmounts[filename] += 1;
	}
	this->filename = filename;
}

void TextureInterface::preloadTextureToList(const string filename)
{
	if(TextureInterface::textureMap.count(filename) == 0)
	{
		Texture* t = new Texture();
		if(!t->loadFromFile(filename))
		{
			cout << "Could not load texture " << filename << endl;
		}
		else
		{
			TextureInterface::textureMap.insert(pair<string, Texture*>(filename, t));
			TextureInterface::textureAmounts.insert(pair<string, int>(filename, 1));
		}
		textureAmounts.insert(pair<string, int>(filename, 1));
	}
}

void TextureInterface::removeTextureFromList(const string filename)
{
	if(TextureInterface::textureMap.count(filename) > 0)
	{
		if(TextureInterface::textureAmounts[filename] < 2)
		{
			TextureInterface::textureMap.at(filename)->~Texture();
			TextureInterface::textureMap.erase(filename);
			TextureInterface::textureAmounts.erase(filename);
		}
	}
}

TextureInterface::~TextureInterface()
{
	if(TextureInterface::textureMap.count(filename) > 0)
	{
		if(TextureInterface::textureAmounts[filename] < 2)
		{
			TextureInterface::textureMap.at(filename)->~Texture();
			TextureInterface::textureMap.erase(filename);
			TextureInterface::textureAmounts.erase(filename);
		}
		else
		{
			TextureInterface::textureAmounts[filename] -= 1;
		}
	}
}

