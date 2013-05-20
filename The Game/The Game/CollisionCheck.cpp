#include "CollisionCheck.h"

CollisionCheck::CollisionCheck(){}

void CollisionCheck::addItem(CollidableObject* obj){checkList.push_back(obj);}
void CollisionCheck::checkCollisions(){
	if(checkList.size() >= 2){
		//HURG I NEED TO FIGURE SOME STUFF OUT

		//for(auto first = checkList.begin(); first != 









		/*
		auto first = checkList.begin();
		auto second = ++checkList.begin();

		while(first != --checkList.end()){
			auto next = second;

			while(next != checkList.end()){
				if((*first)->collides(**next)){
					(*first)->collidesWith(**next);
					(*next)->collidesWith(**first);
				}
				
				++next;
			}
		}*/
	}
}