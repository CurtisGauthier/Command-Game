#include <iostream>
using namespace std;

#include "Items.h"

Items::Items() : QuestPlayers(0){
  positionX = random(24);
  positionY = random(5);
}

int Items::getType(){ return type; }
bool Items::getUsed(){ return used; }

void Items::use(){ used = true; }

void Items::move(){
}
