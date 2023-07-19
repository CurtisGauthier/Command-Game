#ifndef HEROES_H
#define HEROES_H

#include "QuestPlayers.h"
#include "random.h"

//Creates Heroes which are a subclass of QuestPlayers

class Heroes : public QuestPlayers {

  public:
    Heroes(string = "", char =0, int=0, int=0, int=0);
    void takeDamage(int);
    void die();
    void addStrength(int);
    void addArmour(int);
    void addHealth(int);
    int getStrength();
    int getHealth();
    int getArmour();
    string getName();
    bool getEm();
    virtual void move();
    bool getDead();
  private:
    string name;
    bool gotEm = false;
    int strength;
    int health;
    int armour;
    bool dead = false;

};



#endif
