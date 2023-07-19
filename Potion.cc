#include <iostream>
using namespace std;

#include "Items.h"

Potion::Potion(){
  avatar = '3';
  health = (random(3)+5);
  type = 3;
}

int Potion::effect(){
  return(health);
}
