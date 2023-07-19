#ifndef ITEMS_H
#define ITEMS_H

#include "QuestPlayers.h"
#include "Heroes.h"


class Items : public QuestPlayers {
  public:
    Items();
    virtual void move();
    virtual int effect() = 0;
    int getType();
    bool getUsed();
    void use();
  protected:
    int type;
    bool used = false;
};


class Potion : public Items{
  public:
    Potion();
    virtual int effect();
  private:
    int health;
};

class Sword : public Items{
  public:
    Sword();
    virtual int effect();
  private:
    int strength;
};

class Shield : public Items{
  public:
    Shield();
    virtual int effect();
  private:
    int armour;
};





#endif
