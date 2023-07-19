#include <iostream>
#include <list>
using namespace std;
#include <string>

#include "Fighters.h"

//creates a fighter which is randomly decided between porc dork and borc
Fighters::Fighters() : QuestPlayers(0){
  health = 5;
  positionX = 24;
  positionY = random(5);
  int n = random(3);
  if(n == 0){
    borc();
  }else if (n == 1){
    porc();
  }else{
    dorc();
  }
}

//sets the stats of the fighter according to borcs stats
void Fighters::borc(){
  avatar = 'b';
  int s = random(4);
  strength = (s+8);
}

//sets stats of the fighter according to porcs stats
void Fighters::porc(){
  avatar = 'p';
  int s = random(2);
  strength = s+4;
}

//sets stats of the fighter according to dorcs stats
void Fighters::dorc(){
  avatar = 'd';
  int s = random(3);
  strength = s+6;
}

//moves a fighter left until they reach the end of the screen
void Fighters::move(){
  positionX--;
  if (positionX < 0) die();
  int n = random(3);
  if(n==0){
    positionY++;
    if (positionY==5) positionY--;
  }else if(n==1){
    positionY--;
    if (positionY == -1) positionY++;
  }
}

//lowers a fighters health by the given amount
void Fighters::takeDamage(int d){
  health-=d;
  if (health <= 0){
    die();
  }
}

//kills a fighter
void Fighters::die(){
  dead = true;
}

//getters
int Fighters::getHealth() { return health; }
int Fighters::getStrength() { return strength; }
bool Fighters::getDead() { return dead; }






