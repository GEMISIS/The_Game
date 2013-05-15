#ifndef _TEXTURE_INTERFACE_H_
#define _TEXTURE_INTERFACE_H_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class TextureInterface
{
public:
	TextureInterface();
	TextureInterface(const string &filename);
	~TextureInterface();
	void setLoadedTexture(const string &filename);

protected:
	Texture* loadedTexture;

private:
	static unordered_map<string, Texture> textureMap;
	static unordered_map<string, unsigned int> textureAmounts;

	string filename;
	bool texLoaded;

	unsigned int getTexAmount();
	void incTexAmount();
	void decTexAmount();
};

#endif

