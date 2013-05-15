#include "TextureInterface.h"

unordered_map<string, Texture> TextureInterface::textureMap;
unordered_map<string, unsigned int> TextureInterface::textureAmounts;

TextureInterface::TextureInterface(){}
TextureInterface::TextureInterface(const TextureInterface &ti){
	filename = ti.filename;
	texLoaded = ti.texLoaded;
	loadedTexture = ti.loadedTexture;
	incTexAmount();
}
TextureInterface::TextureInterface(const string &filename){setLoadedTexture(filename);}
TextureInterface::~TextureInterface(){decTexAmount();}

//public

void TextureInterface::setLoadedTexture(const string &filename)
{
	if(texLoaded) decTexAmount();

	if(textureMap.count(filename) > 0){
		loadedTexture = &textureMap[filename];
		this->filename = filename;
		texLoaded = true;
		incTexAmount();
		return;
	}

	Texture t;
	if(!t.loadFromFile(filename)){cout << "Could not load texture " << filename << endl; return;}
	textureMap[filename] = t;

	loadedTexture = &textureMap[filename];
	this->filename = filename;
	texLoaded = true;
	incTexAmount();
}

//private

unsigned int TextureInterface::getTexAmount(){
	if(textureAmounts.count(filename) == 0) return 0;
	return textureAmounts[filename];
}
void TextureInterface::incTexAmount(){
	if(textureAmounts.count(filename) == 0){textureAmounts[filename] = 1; return;}
	textureAmounts[filename]++;
}
void TextureInterface::decTexAmount(){
	if(textureAmounts.count(filename) == 0) return;
	if(textureAmounts[filename] == 1){
		textureMap.erase(filename);
		textureAmounts.erase(filename);
		return;
	}
	textureAmounts[filename]--;
}