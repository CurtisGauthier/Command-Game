#include <iostream>
using namespace std;

#include "Items.h"

Sword::Sword(){
  avatar = '2';
  strength = 3;
  type = 2;
}

int Sword::effect(){
  return(strength);
}
