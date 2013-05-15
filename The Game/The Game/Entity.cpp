#include "Entity.h"

Entity::Entity() : TextureInterface(){}
Entity::Entity(const string &filename) : TextureInterface(filename){setTexture(*loadedTexture);}