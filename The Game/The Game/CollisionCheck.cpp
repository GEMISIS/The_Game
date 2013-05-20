#include "CollisionCheck.h"

CollisionCheck::CollisionCheck(){}

void CollisionCheck::addItem(CollidableObject* obj){checkList.push_back(obj);}
void CollisionCheck::removeItem(CollidableObject* obj){checkList.remove(obj);}
void CollisionCheck::checkCollisions(){
	if(checkList.size() >= 2){
		for(auto first = checkList.begin(); first != --checkList.end(); ++first){
			auto next = first;
			++next;

			while(next != checkList.end()){
				if((*first)->collides(**next)){
					(*first)->collidesWith(**next);
					(*next)->collidesWith(**first);
				}

				++next;
			}
		}
	}
}