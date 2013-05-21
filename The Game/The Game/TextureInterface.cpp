#include "TextureInterface.h"

unordered_map<string, Texture> TextureInterface::textureMap;
unordered_map<string, unsigned int> TextureInterface::textureAmounts;

TextureInterface::TextureInterface()
{
}
TextureInterface::TextureInterface(const TextureInterface &ti)
{
	this->filename = ti.filename;
	this->texLoaded = ti.texLoaded;
	this->loadedTexture = ti.loadedTexture;
	this->incTexAmount();
}
TextureInterface::TextureInterface(const string &filename)
{
	this->setLoadedTexture(filename);
}
TextureInterface::~TextureInterface()
{
	this->decTexAmount();
}

//public

void TextureInterface::setLoadedTexture(const string &filename)
{
	if(this->texLoaded)
	{
		this->decTexAmount();
	}

	if(TextureInterface::textureMap.count(filename) == 0)
	{
		Texture t;
		if(!t.loadFromFile(filename))
		{
			cout << "Could not load texture " << filename << endl;
			return;
		}
		else
		{
			this->textureMap[filename] = t;
		}
	}

	this->loadedTexture = &textureMap[filename];
	this->filename = filename;
	this->texLoaded = true;
	this->incTexAmount();
}

//private

unsigned int TextureInterface::getTexAmount()
{
	return (this->textureAmounts.count(this->filename) > 0) ? this->textureAmounts[this->filename] : 0;
}
void TextureInterface::incTexAmount()
{
	if(this->textureAmounts.count(this->filename) == 0)
	{
		this->textureAmounts.insert(pair<string, int>(this->filename, 1));
		cout << "creating " << filename << endl;
	}
	else
	{
		this->textureAmounts[this->filename] += 1;
		//cout << "adding " << filename << " to " << textureAmounts[filename] << endl;
	}
}
void TextureInterface::decTexAmount()
{
	if(this->textureAmounts.size() > 0)
	{
		if(this->textureAmounts.count(this->filename) > 0)
		{
			if(this->textureAmounts[this->filename] == 1)
			{
				this->textureMap.erase(this->filename);
				this->textureAmounts.erase(this->filename);
				cout << "deleting " << filename << endl;
			}
			else
			{
				this->textureAmounts[this->filename] -= 1;
				//cout << "subtracting " << filename << " to " << textureAmounts[filename] << endl;
			}
		}
	}
}