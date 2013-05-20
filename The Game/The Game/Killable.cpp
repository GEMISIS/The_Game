#include "Killable.h"

Killable::Killable(){this->slatedForRemoval = false;}

bool Killable::getSlated(){return slatedForRemoval;}
void Killable::slateForRemoval(){slatedForRemoval = true;}