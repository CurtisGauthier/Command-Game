#include <iostream>
#include <list>
using namespace std;
#include <string>

#include "Control.h"

//The main control flow of the program
void Control::launch()
{
  int    choice;
  while (1) {
    view.showMenu(choice);

    if (choice == 0)
      break;

    if (choice == 1) {
      Game game;
      game.play();
    }
  }
}
