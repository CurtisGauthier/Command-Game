#ifndef QUESTPLAYERS_H
#define QUESTPLAYERS_H

//The base class for all objects in the game

class QuestPlayers{
  public:
    QuestPlayers(char = 0);
    virtual void move() = 0;
    char getAvatar();
    int getPositionX();
    int getPositionY();
    int getId();
  protected:    
    char avatar;   
    int positionX;
    int positionY;
  private:
    static int nextId;
    int id;
};


#endif
