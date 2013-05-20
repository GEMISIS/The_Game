#ifndef COLLISIONCHECK_H
#define COLLISIONCHECK_H

#include <list>
#include "CollidableObject.h"


class CollisionCheck{
public:
	CollisionCheck();

	void addItem(CollidableObject* obj);
	void checkCollisions();

private:
	std::list<CollidableObject*> checkList;

};

#endif