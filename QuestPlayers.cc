#include <iostream>
#include <list>
using namespace std;
#include <string>

#include "QuestPlayers.h"

//Static Id to allow for comparison of QuestPlayers
int QuestPlayers::nextId = 1001;

//Constructor for QuestPlayer objects
QuestPlayers::QuestPlayers(char a) :  avatar(a){
  id = nextId;
  ++nextId;
}

//Getters
char QuestPlayers::getAvatar() { return avatar; }
int QuestPlayers::getPositionX() { return positionX; }
int QuestPlayers::getPositionY() { return positionY; }
int QuestPlayers::getId() { return id; }
