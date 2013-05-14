#ifndef _BaseObject_CLASS_H_
#define _BaseObject_CLASS_H_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class BaseObject
{
public:
	BaseObject();
	BaseObject(const string filename);
	void setTexture(const string filename);
	~BaseObject();
protected:
	string filename;
	static unordered_map<string, sf::Texture*> textureList;
};

#endif