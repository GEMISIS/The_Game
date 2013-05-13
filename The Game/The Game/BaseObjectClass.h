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
	BaseObject(const string& filename);
	// Used for debug reasons atm.
	void setPosition(float x, float y);
	// Used for debug reasons atm.
	void setTexture(const string& filename);
	// Used for debug reasons atm.
	void Update(sf::RenderWindow& window);
	~BaseObject();

	// Used for debug reasons atm.
	sf::Sprite sprite;
protected:
	static unordered_map<string, sf::Texture*> textureList;
private:
	string filename;
};

#endif