#ifndef GAME_H
#define GAME_H

#include <list>
using namespace std;

#include "QuestPlayers.h"
#include "Fighters.h"
#include "Heroes.h"
#include "Dragon.h"
#include "Board.h"
#include "Items.h"
/*#include "Shield.h"
#include "Sword.h"
#include "Potion.h"*/

//Creates a game object which stores QuestPlayer objects and displays the board
//Performs majority of the games calculations through the use of member functions

class Game{

  public:
    Game();
    ~Game();
    void play();
  private:
    void createFighter();
    void moveQuesters();
    Board<char> board;
    list<QuestPlayers*> questerList;
    string winCon = "";
    bool endGame();
    void checkCollision(QuestPlayers*);
    void collide(QuestPlayers*, QuestPlayers*);
    void initQuesters();
    void removeFighters();
    void updateBoard();
};



#endif
