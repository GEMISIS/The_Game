#include "Path.h"

Path::Path(){initRotation = 0;}
Path::Path(PhysicsObject &obj, float rot){this->obj = &obj; initRotation = rot;}