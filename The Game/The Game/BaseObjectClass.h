#ifndef _BaseObject_CLASS_H_
#define _BaseObject_CLASS_H_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class BaseObject
{
public:
	BaseObject();
	BaseObject(const string filename);
	void addTexture(const string filename);
	~BaseObject();
protected:
	string filename;
	static unordered_map<string, Texture*> textureList;
};

#endif

