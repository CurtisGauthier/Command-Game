#include <iostream>
using namespace std;

#include "Items.h"

Shield::Shield(){
  avatar = '1';
  armour = (random(3)+1);
  type = 1;
}

int Shield::effect(){
  return(armour);
}
