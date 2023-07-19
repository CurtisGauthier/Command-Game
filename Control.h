#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include "Game.h"
#include "random.h"

//Governs the main control flow of the program

class Control{

  public:
    void launch();
  private:
    View view;
};

#endif
