#include <iostream>
#include <list>
using namespace std;
#include <string>

#include "Heroes.h"

//constructor with random starting height
Heroes::Heroes(string n, char a, int h, int s, int ar) : name(n), health(h), strength(s), armour(ar), QuestPlayers(a){
  positionX = 0;
  positionY = random(5);
}

//functions to add stats with items
void Heroes::addHealth(int h) { health+=h; }
void Heroes::addStrength(int s){ strength+=s; }
void Heroes::addArmour(int a) { armour+=a; }

//getters
int Heroes::getHealth() { return health; }
int Heroes::getStrength() { return strength; }
int Heroes::getArmour() { return armour; }
bool Heroes::getEm() { return gotEm; }
bool Heroes::getDead() { return dead;}
string Heroes::getName() {return name; }

//dictates functionality when a hero dies
void Heroes::die(){
  avatar = '+';
  dead = true;
  strength = 0;
}

//lowers a heroes health by the given amount
void Heroes::takeDamage(int d){
  d-=armour;
  if (d<=0) return;
  health-=d;
  if (health <=0){
    die();
  }
}

//moves a hero to the right and randomly up, down or even
void Heroes::move(){
  if(dead) return;
  positionX++;
  int n = random(3);
  if (n==0){
    positionY++;
    if (positionY==5){
      positionY--;
    }
  }else if(n==1){
    positionY--;
    if (positionY==-1){
      positionY++;
    }
  }
  
  //checks if the hero has entered the cave
  if(positionX == 25){
    if (positionY > 0 && positionY < 4){
      gotEm = true;
    }else{
      positionX--;
    }
  }


}
