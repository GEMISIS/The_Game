#ifndef PATH_H
#define PATH_H

#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"

class Path{
public:
	Path();
	Path(PhysicsObject &obj, float Rot);
	virtual void updatePathLogic() = 0;

private:
	float initRotation; //With 0 being right, going counter-clockwise
	PhysicsObject* obj;
};

#endif