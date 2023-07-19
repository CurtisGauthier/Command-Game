#ifndef FIGHTERS_H
#define FIGHTERS_H

#include "QuestPlayers.h"
#include "random.h"

//creates a fighter which is a subclass of QuestPlayers

class Fighters : public QuestPlayers {

  public:
    Fighters();
    void takeDamage(int);
    void die();
    int getHealth();
    int getStrength();
    virtual void move();
    bool getDead();
  private:
    bool dead = false;
    int strength;
    int health;
    void borc();
    void porc();
    void dorc();

};


#endif
