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
	TextureInterface(const string filename);
	Texture* getTextureFromMap();
	void preloadTexture(const string filename);
	static void preloadTextureToList(const string filename);
	static void removeTextureFromList(const string filename);
	~TextureInterface();
private:
	string filename;
	static unordered_map<string, Texture*> textureMap;
	static unordered_map<string, unsigned int> textureAmounts;
};

#endif

