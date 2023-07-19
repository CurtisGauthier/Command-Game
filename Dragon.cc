#include <iostream>
using namespace std;

#include "Dragon.h"

//creates a dragon at the middle of the rightmost column
Dragon::Dragon(char a) : QuestPlayers(a){
  positionX = 24;
  positionY = 2;
}


//moves the dragon's postion up and down
void Dragon::move(){
  if (direction == true){
    positionY++;
    if (positionY==3) direction = false;
  }else{
    positionY--;
    if (positionY==1) direction = true;
  }
}
