#include <iostream>
using namespace std;

#include <cstdlib>
#include <time.h>

#include "Control.h"

/*
 *This program simulates a game where hero objects move from the start of a grid to the end of the grid with the goal of reaching the end before being defeated by fighters and dragons
 *
 * Enter 1/0 as prompted to start or exit
 * The game can be replayed until 0 is entered
 *
 * Author: Curtis Gauthier 101102886
 *
 */


int main(){
  srand( (unsigned)time( NULL ));
  Control control;
  control.launch();
  return 0;
}
