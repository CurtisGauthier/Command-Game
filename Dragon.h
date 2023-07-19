#ifndef DRAGON_H
#define DRAGON_H

#include "QuestPlayers.h"

//creates a dragon which is a subclass of QuestPlayers

class Dragon : public QuestPlayers {
  public:
    Dragon(char=0);
    virtual void move();
  private:
    bool direction = true;
};

#endif
